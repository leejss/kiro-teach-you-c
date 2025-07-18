/*
 * File Basics - Fundamental File Operations and Resource Management
 * 
 * This program demonstrates:
 * - File opening, reading, writing, and closing
 * - Error handling and resource management
 * - File position tracking and seeking
 * - Implementation details of file operations
 * 
 * For frontend developers: Unlike JavaScript's automatic file handling,
 * C requires explicit resource management and error checking.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

// Function prototypes
void demonstrate_file_creation_and_writing(void);
void demonstrate_file_reading(void);
void demonstrate_file_positioning(void);
void demonstrate_file_metadata(void);
void demonstrate_error_handling(void);
void show_file_implementation_details(FILE* file, const char* filename);

void demonstrate_file_creation_and_writing(void) {
    printf("=== File Creation and Writing ===\n");
    
    // Create a new file for writing
    const char* filename = "sample_output.txt";
    FILE* file = fopen(filename, "w");
    
    if (file == NULL) {
        fprintf(stderr, "Failed to create file '%s': %s\n", filename, strerror(errno));
        return;
    }
    
    printf("Successfully opened '%s' for writing\n", filename);
    show_file_implementation_details(file, filename);
    
    // Write different types of data
    fprintf(file, "File I/O Demonstration\n");
    fprintf(file, "=====================\n\n");
    
    // Write formatted data
    int numbers[] = {10, 20, 30, 40, 50};
    fprintf(file, "Numbers: ");
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fprintf(file, "\n");
    
    // Write current timestamp
    time_t current_time = time(NULL);
    fprintf(file, "Created: %s", ctime(&current_time));
    
    // Write character data
    char message[] = "This file was created by a C program.\n";
    fputs(message, file);
    
    // Write binary data as text
    fprintf(file, "\nBinary representation of 42: ");
    int value = 42;
    for (int i = 7; i >= 0; i--) {
        fprintf(file, "%d", (value >> i) & 1);
    }
    fprintf(file, "\n");
    
    // Show current file position
    long position = ftell(file);
    printf("Current file position: %ld bytes\n", position);
    
    // Flush buffer to ensure data is written
    fflush(file);
    printf("Buffer flushed to disk\n");
    
    fclose(file);
    printf("File closed successfully\n\n");
}

void demonstrate_file_reading(void) {
    printf("=== File Reading Operations ===\n");
    
    const char* filename = "sample_output.txt";
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Failed to open file '%s' for reading: %s\n", filename, strerror(errno));
        return;
    }
    
    printf("Successfully opened '%s' for reading\n", filename);
    show_file_implementation_details(file, filename);
    
    // Method 1: Read character by character
    printf("\nReading first 50 characters:\n");
    printf("\"");
    for (int i = 0; i < 50; i++) {
        int ch = fgetc(file);
        if (ch == EOF) {
            printf("\" (reached end of file at character %d)\n", i);
            break;
        }
        if (ch == '\n') {
            printf("\\n");
        } else if (ch == '\t') {
            printf("\\t");
        } else {
            printf("%c", ch);
        }
    }
    if (!feof(file)) {
        printf("\"\n");
    }
    
    // Reset to beginning
    rewind(file);
    printf("File position reset to beginning\n");
    
    // Method 2: Read line by line
    printf("\nReading line by line:\n");
    char line_buffer[256];
    int line_number = 1;
    
    while (fgets(line_buffer, sizeof(line_buffer), file) != NULL) {
        // Remove newline if present
        size_t len = strlen(line_buffer);
        if (len > 0 && line_buffer[len-1] == '\n') {
            line_buffer[len-1] = '\0';
        }
        
        printf("  Line %d: \"%s\"\n", line_number, line_buffer);
        line_number++;
        
        if (line_number > 5) {  // Limit output
            printf("  ... (truncated for display)\n");
            break;
        }
    }
    
    // Method 3: Read entire file into buffer
    rewind(file);
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    
    printf("\nFile size: %ld bytes\n", file_size);
    
    // Allocate buffer for entire file
    char* file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        fprintf(stderr, "Failed to allocate memory for file content\n");
        fclose(file);
        return;
    }
    
    // Read entire file
    size_t bytes_read = fread(file_content, 1, file_size, file);
    file_content[bytes_read] = '\0';  // Null terminate
    
    printf("Read %zu bytes from file\n", bytes_read);
    printf("First 100 characters of file content:\n");
    printf("\"%.100s", file_content);
    if (strlen(file_content) > 100) {
        printf("...\"");
    } else {
        printf("\"");
    }
    printf("\n");
    
    free(file_content);
    fclose(file);
    printf("File closed and memory freed\n\n");
}

void demonstrate_file_positioning(void) {
    printf("=== File Positioning and Seeking ===\n");
    
    // Create a test file with known content
    const char* filename = "position_test.txt";
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to create position test file");
        return;
    }
    
    // Write alphabet
    for (char c = 'A'; c <= 'Z'; c++) {
        fputc(c, file);
    }
    fclose(file);
    
    // Reopen for reading and demonstrate positioning
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open position test file");
        return;
    }
    
    printf("Created file with alphabet (A-Z)\n");
    
    // Show initial position
    long pos = ftell(file);
    printf("Initial position: %ld\n", pos);
    
    // Read first 5 characters
    printf("Reading first 5 characters: ");
    for (int i = 0; i < 5; i++) {
        int ch = fgetc(file);
        printf("%c", ch);
    }
    printf("\n");
    
    pos = ftell(file);
    printf("Position after reading 5 chars: %ld\n", pos);
    
    // Seek to middle of file
    fseek(file, 13, SEEK_SET);  // Position 13 (letter 'N')
    pos = ftell(file);
    printf("After seeking to position 13: %ld\n", pos);
    
    int ch = fgetc(file);
    printf("Character at position 13: %c\n", ch);
    
    // Seek relative to current position
    fseek(file, 5, SEEK_CUR);  // Move 5 positions forward
    pos = ftell(file);
    printf("After seeking +5 from current: %ld\n", pos);
    
    ch = fgetc(file);
    printf("Character at new position: %c\n", ch);
    
    // Seek from end of file
    fseek(file, -3, SEEK_END);  // 3 positions from end
    pos = ftell(file);
    printf("After seeking -3 from end: %ld\n", pos);
    
    ch = fgetc(file);
    printf("Character 3 from end: %c\n", ch);
    
    // Demonstrate rewind
    rewind(file);
    pos = ftell(file);
    printf("After rewind: %ld\n", pos);
    
    ch = fgetc(file);
    printf("First character after rewind: %c\n", ch);
    
    fclose(file);
    printf("Position test completed\n\n");
}

void demonstrate_file_metadata(void) {
    printf("=== File Metadata and System Information ===\n");
    
    const char* filename = "sample_output.txt";
    struct stat file_stat;
    
    if (stat(filename, &file_stat) == 0) {
        printf("File metadata for '%s':\n", filename);
        printf("  Size: %ld bytes\n", file_stat.st_size);
        printf("  Permissions: %o (octal)\n", file_stat.st_mode & 0777);
        printf("  Links: %ld\n", file_stat.st_nlink);
        printf("  Inode: %ld\n", file_stat.st_ino);
        
        // Convert timestamps to readable format
        printf("  Last access: %s", ctime(&file_stat.st_atime));
        printf("  Last modified: %s", ctime(&file_stat.st_mtime));
        printf("  Status change: %s", ctime(&file_stat.st_ctime));
        
        // File type detection
        printf("  File type: ");
        if (S_ISREG(file_stat.st_mode)) {
            printf("Regular file\n");
        } else if (S_ISDIR(file_stat.st_mode)) {
            printf("Directory\n");
        } else if (S_ISLNK(file_stat.st_mode)) {
            printf("Symbolic link\n");
        } else {
            printf("Other\n");
        }
        
        // Permission breakdown
        printf("  Permissions breakdown:\n");
        printf("    Owner: %c%c%c\n",
               (file_stat.st_mode & S_IRUSR) ? 'r' : '-',
               (file_stat.st_mode & S_IWUSR) ? 'w' : '-',
               (file_stat.st_mode & S_IXUSR) ? 'x' : '-');
        printf("    Group: %c%c%c\n",
               (file_stat.st_mode & S_IRGRP) ? 'r' : '-',
               (file_stat.st_mode & S_IWGRP) ? 'w' : '-',
               (file_stat.st_mode & S_IXGRP) ? 'x' : '-');
        printf("    Other: %c%c%c\n",
               (file_stat.st_mode & S_IROTH) ? 'r' : '-',
               (file_stat.st_mode & S_IWOTH) ? 'w' : '-',
               (file_stat.st_mode & S_IXOTH) ? 'x' : '-');
    } else {
        printf("Failed to get metadata for '%s': %s\n", filename, strerror(errno));
    }
    printf("\n");
}

void demonstrate_error_handling(void) {
    printf("=== Error Handling and Edge Cases ===\n");
    
    // Try to open non-existent file
    printf("Attempting to open non-existent file:\n");
    FILE* file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        printf("  Expected error: %s\n", strerror(errno));
    } else {
        printf("  Unexpected success!\n");
        fclose(file);
    }
    
    // Try to write to read-only file
    printf("\nAttempting to write to read-only file:\n");
    file = fopen("sample_output.txt", "r");
    if (file != NULL) {
        int result = fputs("This should fail", file);
        if (result == EOF) {
            printf("  Write failed as expected (file opened read-only)\n");
            if (ferror(file)) {
                printf("  Error flag set on file stream\n");
            }
        } else {
            printf("  Unexpected write success!\n");
        }
        fclose(file);
    }
    
    // Demonstrate EOF detection
    printf("\nDemonstrating EOF detection:\n");
    file = fopen("position_test.txt", "r");
    if (file != NULL) {
        int char_count = 0;
        int ch;
        
        while ((ch = fgetc(file)) != EOF) {
            char_count++;
        }
        
        printf("  Read %d characters before EOF\n", char_count);
        printf("  EOF reached: %s\n", feof(file) ? "Yes" : "No");
        printf("  Error occurred: %s\n", ferror(file) ? "Yes" : "No");
        
        fclose(file);
    }
    
    // Demonstrate buffer overflow protection
    printf("\nDemonstrating safe string reading:\n");
    file = fopen("sample_output.txt", "r");
    if (file != NULL) {
        char small_buffer[10];  // Intentionally small buffer
        
        if (fgets(small_buffer, sizeof(small_buffer), file) != NULL) {
            printf("  Read into small buffer: \"%.20s\"\n", small_buffer);
            printf("  Buffer size: %zu, String length: %zu\n", 
                   sizeof(small_buffer), strlen(small_buffer));
        }
        
        fclose(file);
    }
    printf("\n");
}

void show_file_implementation_details(FILE* file, const char* filename) {
    printf("File implementation details:\n");
    
    // Show file descriptor (Unix/Linux specific)
    int fd = fileno(file);
    printf("  File descriptor: %d\n", fd);
    
    // Show current position
    long position = ftell(file);
    printf("  Current position: %ld bytes\n", position);
    
    // Show buffer information
    printf("  System buffer size: %d bytes\n", BUFSIZ);
    
    // Show file stream flags
    printf("  EOF flag: %s\n", feof(file) ? "Set" : "Clear");
    printf("  Error flag: %s\n", ferror(file) ? "Set" : "Clear");
    
    printf("\n");
}

int main(void) {
    printf("File Basics - Fundamental File Operations\n");
    printf("========================================\n");
    
    demonstrate_file_creation_and_writing();
    demonstrate_file_reading();
    demonstrate_file_positioning();
    demonstrate_file_metadata();
    demonstrate_error_handling();
    
    printf("=== Key Implementation Details ===\n");
    printf("1. FILE* is a wrapper around system file descriptors\n");
    printf("2. File operations use system buffers for efficiency\n");
    printf("3. Always check return values for error conditions\n");
    printf("4. File position is tracked automatically by the system\n");
    printf("5. Resource cleanup (fclose) is mandatory\n");
    printf("6. Text mode vs binary mode affects line ending handling\n");
    
    // Cleanup test files
    remove("position_test.txt");
    printf("\nTest files cleaned up\n");
    
    return 0;
}