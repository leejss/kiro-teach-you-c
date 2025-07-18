# Lesson 10: File Input/Output Operations

## Learning Objectives

By the end of this lesson, you'll understand:

- File operations and system-level I/O
- Binary vs text file handling
- File pointers and stream management
- Error handling and resource management
- Performance implications of different I/O approaches

## Key Concepts for Frontend Developers

### JavaScript vs C: File System Access

**JavaScript (Browser/Node.js Abstraction):**

```javascript
// Browser: Indirect file access through APIs
const fileInput = document.querySelector('input[type="file"]');
fileInput.addEventListener("change", async (event) => {
  const file = event.target.files[0];
  const text = await file.text(); // Automatic encoding handling
  console.log(text); // Memory managed automatically
});

// Node.js: Higher-level file operations
const fs = require("fs").promises;
const data = await fs.readFile("config.json", "utf8"); // Encoding specified
const parsed = JSON.parse(data); // Automatic parsing
```

**C (Direct System Calls):**

```c
// Direct file system interaction
FILE* file = fopen("config.txt", "r");  // Manual file handle management
if (file == NULL) {
    perror("Failed to open file");      // Explicit error handling
    return -1;
}

char buffer[1024];
size_t bytes_read = fread(buffer, 1, sizeof(buffer)-1, file);  // Manual buffer management
buffer[bytes_read] = '\0';  // Manual null termination

// Manual parsing required
int value = atoi(buffer);   // No automatic type conversion

fclose(file);  // Manual resource cleanup
```

**Key Implementation Differences:**

- C requires explicit file handle management and cleanup
- Manual buffer allocation and bounds checking
- Direct interaction with operating system file descriptors
- No automatic encoding detection or conversion
- Explicit error checking for every operation
- Manual memory management for file data

## File System Implementation Details

### File Descriptors and Streams

```c
// FILE* is a wrapper around file descriptors
FILE* file = fopen("data.txt", "r");

// Get underlying file descriptor (Unix/Linux)
int fd = fileno(file);
printf("File descriptor: %d\n", fd);

// Show file position tracking
long position = ftell(file);
printf("Current position: %ld bytes\n", position);

// Demonstrate buffering
printf("Buffer size: %d\n", BUFSIZ);  // System buffer size
```

### Memory Layout of FILE Structure

```c
// FILE structure contains:
// - File descriptor
// - Buffer pointer and size
// - Current position
// - Error and EOF flags
// - Mode flags (read/write/append)

printf("Size of FILE structure: %zu bytes\n", sizeof(FILE));
```

## File Operations Implementation

### Opening Files - System Level Details

```c
// Different modes have different system implications
FILE* read_file = fopen("input.txt", "r");      // O_RDONLY
FILE* write_file = fopen("output.txt", "w");    // O_WRONLY | O_CREAT | O_TRUNC
FILE* append_file = fopen("log.txt", "a");      // O_WRONLY | O_CREAT | O_APPEND
FILE* binary_file = fopen("data.bin", "rb");    // Binary mode (no text conversion)

// Show actual file permissions and attributes
struct stat file_info;
if (stat("input.txt", &file_info) == 0) {
    printf("File size: %ld bytes\n", file_info.st_size);
    printf("File permissions: %o\n", file_info.st_mode & 0777);
    printf("Last modified: %ld\n", file_info.st_mtime);
}
```

### Buffering Implementation Details

```c
// Show different buffering modes
FILE* file = fopen("test.txt", "w");

// Full buffering (default for files)
setvbuf(file, NULL, _IOFBF, BUFSIZ);

// Line buffering (default for terminals)
setvbuf(file, NULL, _IOLBF, BUFSIZ);

// No buffering (immediate system calls)
setvbuf(file, NULL, _IONBF, 0);

// Custom buffer
char custom_buffer[4096];
setvbuf(file, custom_buffer, _IOFBF, sizeof(custom_buffer));
```

## Performance Implications

### Buffer Size Impact

```c
#include <time.h>

// Small buffer - many system calls
clock_t start = clock();
FILE* file = fopen("large_file.txt", "r");
char small_buffer[64];
while (fread(small_buffer, 1, sizeof(small_buffer), file) > 0) {
    // Process data
}
fclose(file);
clock_t end = clock();
printf("Small buffer time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

// Large buffer - fewer system calls
start = clock();
file = fopen("large_file.txt", "r");
char large_buffer[8192];
while (fread(large_buffer, 1, sizeof(large_buffer), file) > 0) {
    // Process data
}
fclose(file);
end = clock();
printf("Large buffer time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
```

### Memory-Mapped Files vs Traditional I/O

```c
#include <sys/mman.h>
#include <sys/stat.h>

// Traditional I/O: Copy data through kernel buffers
FILE* file = fopen("data.txt", "r");
char* buffer = malloc(file_size);
fread(buffer, 1, file_size, file);  // Data copied: disk -> kernel -> user space

// Memory-mapped I/O: Direct memory access
int fd = open("data.txt", O_RDONLY);
char* mapped = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
// Data accessed directly from virtual memory (faster for large files)
```

## Examples

1. `file_basics.c` - File opening, reading, writing, and resource management
2. `binary_file_operations.c` - Binary file handling and data serialization
3. `file_processing.c` - Text processing, parsing, and data extraction
4. `advanced_file_io.c` - Performance optimization and system-level operations

## Real-World Applications

- **Configuration Files**: Reading application settings and parameters
- **Data Serialization**: Saving/loading program state and structures
- **Log Processing**: Analyzing system logs and generating reports
- **File Format Parsing**: Reading CSV, JSON, binary formats
- **System Programming**: Direct file system interaction and monitoring

## Error Handling Implementation

### Comprehensive Error Checking

```c
FILE* safe_fopen(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        fprintf(stderr, "Failed to open '%s' in mode '%s': ", filename, mode);
        perror("");  // Print system error message
        return NULL;
    }
    return file;
}

int safe_fread(void* buffer, size_t size, size_t count, FILE* file) {
    size_t result = fread(buffer, size, count, file);
    if (result != count) {
        if (feof(file)) {
            printf("End of file reached\n");
        } else if (ferror(file)) {
            fprintf(stderr, "Read error occurred\n");
            return -1;
        }
    }
    return result;
}
```

### Resource Management Patterns

```c
// RAII-style resource management in C
typedef struct {
    FILE* file;
    char* buffer;
    size_t buffer_size;
} FileHandler;

FileHandler* create_file_handler(const char* filename, const char* mode, size_t buffer_size) {
    FileHandler* handler = malloc(sizeof(FileHandler));
    if (!handler) return NULL;

    handler->file = fopen(filename, mode);
    if (!handler->file) {
        free(handler);
        return NULL;
    }

    handler->buffer = malloc(buffer_size);
    if (!handler->buffer) {
        fclose(handler->file);
        free(handler);
        return NULL;
    }

    handler->buffer_size = buffer_size;
    return handler;
}

void destroy_file_handler(FileHandler* handler) {
    if (handler) {
        if (handler->file) fclose(handler->file);
        if (handler->buffer) free(handler->buffer);
        free(handler);
    }
}
```

## System-Level File Operations

### File Metadata and Attributes

```c
#include <sys/stat.h>
#include <time.h>

void show_file_details(const char* filename) {
    struct stat file_stat;
    if (stat(filename, &file_stat) == 0) {
        printf("File: %s\n", filename);
        printf("  Size: %ld bytes\n", file_stat.st_size);
        printf("  Permissions: %o\n", file_stat.st_mode & 0777);
        printf("  Links: %ld\n", file_stat.st_nlink);
        printf("  Last access: %s", ctime(&file_stat.st_atime));
        printf("  Last modified: %s", ctime(&file_stat.st_mtime));
        printf("  Inode: %ld\n", file_stat.st_ino);

        // File type detection
        if (S_ISREG(file_stat.st_mode)) printf("  Type: Regular file\n");
        else if (S_ISDIR(file_stat.st_mode)) printf("  Type: Directory\n");
        else if (S_ISLNK(file_stat.st_mode)) printf("  Type: Symbolic link\n");
    }
}
```

### Directory Operations

```c
#include <dirent.h>

void list_directory_contents(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("  %s", entry->d_name);

        // Show file type from directory entry
        switch (entry->d_type) {
            case DT_REG: printf(" (file)"); break;
            case DT_DIR: printf(" (directory)"); break;
            case DT_LNK: printf(" (link)"); break;
            default: printf(" (other)"); break;
        }
        printf("\n");
    }

    closedir(dir);
}
```

## Compilation & Execution

```bash
# Build all examples
make all

# Run all examples in sequence
make run

# Run individual examples
./file_basics
./binary_file_operations
./file_processing
./advanced_file_io

# Memory checking (if valgrind is available)
make memcheck

# Create test files for examples
make test-files
```

## Next Steps

After mastering file I/O, you'll move to advanced topics including dynamic memory management, where you'll learn to create flexible data structures that can be saved to and loaded from files, preparing you for complex systems programming tasks.
