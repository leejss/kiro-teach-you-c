/*
 * Binary File Operations - Data Serialization and Binary I/O
 * 
 * This program demonstrates:
 * - Binary vs text file operations
 * - Structure serialization to files
 * - Endianness and portability concerns
 * - Performance implications of binary I/O
 * 
 * For frontend developers: Unlike JavaScript's automatic JSON serialization,
 * C requires manual binary data layout and endianness handling.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <sys/stat.h>

// Define structures for binary serialization
typedef struct {
    uint32_t id;
    char name[50];
    double salary;
    uint16_t department_id;
    uint8_t active;
} Employee;

typedef struct {
    uint16_t department_id;
    char department_name[30];
    uint32_t budget;
} Department;

typedef struct {
    char magic[4];        // File format identifier
    uint16_t version;     // File format version
    uint32_t record_count;
    uint32_t checksum;
} FileHeader;

// Function prototypes
void demonstrate_binary_vs_text(void);
void demonstrate_structure_serialization(void);
void demonstrate_endianness_handling(void);
void demonstrate_binary_file_format(void);
void demonstrate_performance_comparison(void);
uint32_t calculate_checksum(const void* data, size_t size);
void show_binary_data_layout(const void* data, size_t size, const char* description);

void demonstrate_binary_vs_text(void) {
    printf("=== Binary vs Text File Operations ===\n");
    
    int numbers[] = {1000, 2000, 3000, 4000, 5000};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    // Write as text file
    FILE* text_file = fopen("numbers_text.txt", "w");
    if (text_file == NULL) {
        perror("Failed to create text file");
        return;
    }
    
    printf("Writing numbers as text:\n");
    for (int i = 0; i < count; i++) {
        fprintf(text_file, "%d\n", numbers[i]);
        printf("  %d -> \"%d\\n\" (text representation)\n", numbers[i], numbers[i]);
    }
    fclose(text_file);
    
    // Write as binary file
    FILE* binary_file = fopen("numbers_binary.bin", "wb");
    if (binary_file == NULL) {
        perror("Failed to create binary file");
        return;
    }
    
    printf("\nWriting numbers as binary:\n");
    size_t written = fwrite(numbers, sizeof(int), count, binary_file);
    printf("  Wrote %zu integers (%zu bytes total)\n", written, written * sizeof(int));
    
    // Show binary representation
    for (int i = 0; i < count; i++) {
        printf("  %d -> ", numbers[i]);
        unsigned char* bytes = (unsigned char*)&numbers[i];
        for (size_t j = 0; j < sizeof(int); j++) {
            printf("%02X ", bytes[j]);
        }
        printf("(binary representation)\n");
    }
    fclose(binary_file);
    
    // Compare file sizes
    struct stat text_stat, binary_stat;
    stat("numbers_text.txt", &text_stat);
    stat("numbers_binary.bin", &binary_stat);
    
    printf("\nFile size comparison:\n");
    printf("  Text file: %ld bytes\n", text_stat.st_size);
    printf("  Binary file: %ld bytes\n", binary_stat.st_size);
    printf("  Space savings: %.1f%%\n", 
           100.0 * (text_stat.st_size - binary_stat.st_size) / text_stat.st_size);
    
    // Read back and verify
    printf("\nReading back binary data:\n");
    binary_file = fopen("numbers_binary.bin", "rb");
    if (binary_file != NULL) {
        int read_numbers[5];
        size_t read_count = fread(read_numbers, sizeof(int), count, binary_file);
        
        printf("  Read %zu integers:\n", read_count);
        for (size_t i = 0; i < read_count; i++) {
            printf("    [%zu]: %d %s\n", i, read_numbers[i],
                   (read_numbers[i] == numbers[i]) ? "✓" : "✗");
        }
        fclose(binary_file);
    }
    printf("\n");
}

void demonstrate_structure_serialization(void) {
    printf("=== Structure Serialization ===\n");
    
    // Create sample data
    Employee employees[] = {
        {1001, "Alice Johnson", 75000.50, 100, 1},
        {1002, "Bob Smith", 68000.00, 101, 1},
        {1003, "Carol Davis", 82000.75, 100, 0}
    };
    
    Department departments[] = {
        {100, "Engineering", 500000},
        {101, "Marketing", 250000}
    };
    
    int emp_count = sizeof(employees) / sizeof(employees[0]);
    int dept_count = sizeof(departments) / sizeof(departments[0]);
    
    printf("Serializing %d employees and %d departments\n", emp_count, dept_count);
    
    // Show structure memory layout
    printf("\nEmployee structure layout:\n");
    printf("  Size: %zu bytes\n", sizeof(Employee));
    printf("  id offset: %zu\n", offsetof(Employee, id));
    printf("  name offset: %zu\n", offsetof(Employee, name));
    printf("  salary offset: %zu\n", offsetof(Employee, salary));
    printf("  department_id offset: %zu\n", offsetof(Employee, department_id));
    printf("  active offset: %zu\n", offsetof(Employee, active));
    
    // Write structures to binary file
    FILE* file = fopen("company_data.bin", "wb");
    if (file == NULL) {
        perror("Failed to create company data file");
        return;
    }
    
    // Write employee count and data
    fwrite(&emp_count, sizeof(int), 1, file);
    fwrite(employees, sizeof(Employee), emp_count, file);
    
    // Write department count and data
    fwrite(&dept_count, sizeof(int), 1, file);
    fwrite(departments, sizeof(Department), dept_count, file);
    
    fclose(file);
    printf("Data serialized to company_data.bin\n");
    
    // Read back and verify
    file = fopen("company_data.bin", "rb");
    if (file == NULL) {
        perror("Failed to open company data file");
        return;
    }
    
    // Read employee data
    int read_emp_count;
    fread(&read_emp_count, sizeof(int), 1, file);
    printf("\nReading back %d employees:\n", read_emp_count);
    
    Employee* read_employees = malloc(read_emp_count * sizeof(Employee));
    fread(read_employees, sizeof(Employee), read_emp_count, file);
    
    for (int i = 0; i < read_emp_count; i++) {
        printf("  Employee %d: ID=%u, Name=\"%s\", Salary=$%.2f, Dept=%u, Active=%s\n",
               i + 1, read_employees[i].id, read_employees[i].name,
               read_employees[i].salary, read_employees[i].department_id,
               read_employees[i].active ? "Yes" : "No");
    }
    
    // Read department data
    int read_dept_count;
    fread(&read_dept_count, sizeof(int), 1, file);
    printf("\nReading back %d departments:\n", read_dept_count);
    
    Department* read_departments = malloc(read_dept_count * sizeof(Department));
    fread(read_departments, sizeof(Department), read_dept_count, file);
    
    for (int i = 0; i < read_dept_count; i++) {
        printf("  Department %d: ID=%u, Name=\"%s\", Budget=$%u\n",
               i + 1, read_departments[i].department_id,
               read_departments[i].department_name, read_departments[i].budget);
    }
    
    fclose(file);
    free(read_employees);
    free(read_departments);
    printf("\n");
}

void demonstrate_endianness_handling(void) {
    printf("=== Endianness and Portability ===\n");
    
    // Detect system endianness
    uint32_t test_value = 0x12345678;
    unsigned char* bytes = (unsigned char*)&test_value;
    
    printf("System endianness detection:\n");
    printf("  Value 0x12345678 stored as: ");
    for (int i = 0; i < 4; i++) {
        printf("%02X ", bytes[i]);
    }
    
    if (bytes[0] == 0x78) {
        printf("(Little Endian)\n");
    } else if (bytes[0] == 0x12) {
        printf("(Big Endian)\n");
    } else {
        printf("(Unknown)\n");
    }
    
    // Demonstrate endianness conversion functions
    uint16_t host_short = 0x1234;
    uint32_t host_long = 0x12345678;
    
    printf("\nEndianness conversion:\n");
    printf("  Host order (16-bit): 0x%04X\n", host_short);
    printf("  Network order (16-bit): 0x%04X\n", htons(host_short));
    printf("  Host order (32-bit): 0x%08X\n", host_long);
    printf("  Network order (32-bit): 0x%08X\n", htonl(host_long));
    
    // Write data in portable format
    FILE* file = fopen("portable_data.bin", "wb");
    if (file == NULL) {
        perror("Failed to create portable data file");
        return;
    }
    
    // Convert to network byte order before writing
    uint16_t network_short = htons(host_short);
    uint32_t network_long = htonl(host_long);
    
    fwrite(&network_short, sizeof(uint16_t), 1, file);
    fwrite(&network_long, sizeof(uint32_t), 1, file);
    fclose(file);
    
    printf("\nData written in network byte order (portable)\n");
    
    // Read back and convert
    file = fopen("portable_data.bin", "rb");
    if (file != NULL) {
        uint16_t read_short;
        uint32_t read_long;
        
        fread(&read_short, sizeof(uint16_t), 1, file);
        fread(&read_long, sizeof(uint32_t), 1, file);
        
        // Convert back to host order
        read_short = ntohs(read_short);
        read_long = ntohl(read_long);
        
        printf("Data read back and converted to host order:\n");
        printf("  16-bit: 0x%04X %s\n", read_short, 
               (read_short == host_short) ? "✓" : "✗");
        printf("  32-bit: 0x%08X %s\n", read_long,
               (read_long == host_long) ? "✓" : "✗");
        
        fclose(file);
    }
    printf("\n");
}

void demonstrate_binary_file_format(void) {
    printf("=== Custom Binary File Format ===\n");
    
    const char* filename = "custom_format.dat";
    
    // Sample data
    int data[] = {100, 200, 300, 400, 500};
    int data_count = sizeof(data) / sizeof(data[0]);
    
    // Create file with custom header
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to create custom format file");
        return;
    }
    
    // Create and write header
    FileHeader header;
    memcpy(header.magic, "MYFT", 4);  // Magic number
    header.version = htons(1);        // Version 1
    header.record_count = htonl(data_count);
    header.checksum = htonl(calculate_checksum(data, sizeof(data)));
    
    printf("Writing file header:\n");
    printf("  Magic: %.4s\n", header.magic);
    printf("  Version: %u\n", ntohs(header.version));
    printf("  Record count: %u\n", ntohl(header.record_count));
    printf("  Checksum: 0x%08X\n", ntohl(header.checksum));
    
    fwrite(&header, sizeof(FileHeader), 1, file);
    
    // Write data
    for (int i = 0; i < data_count; i++) {
        uint32_t network_value = htonl(data[i]);
        fwrite(&network_value, sizeof(uint32_t), 1, file);
    }
    
    fclose(file);
    printf("Custom format file created\n");
    
    // Read and validate file
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open custom format file");
        return;
    }
    
    // Read header
    FileHeader read_header;
    if (fread(&read_header, sizeof(FileHeader), 1, file) != 1) {
        fprintf(stderr, "Failed to read file header\n");
        fclose(file);
        return;
    }
    
    // Validate magic number
    if (memcmp(read_header.magic, "MYFT", 4) != 0) {
        fprintf(stderr, "Invalid file format (bad magic number)\n");
        fclose(file);
        return;
    }
    
    // Convert header fields
    uint16_t version = ntohs(read_header.version);
    uint32_t record_count = ntohl(read_header.record_count);
    uint32_t stored_checksum = ntohl(read_header.checksum);
    
    printf("\nReading file header:\n");
    printf("  Magic: %.4s ✓\n", read_header.magic);
    printf("  Version: %u\n", version);
    printf("  Record count: %u\n", record_count);
    printf("  Stored checksum: 0x%08X\n", stored_checksum);
    
    // Read data
    uint32_t* read_data = malloc(record_count * sizeof(uint32_t));
    for (uint32_t i = 0; i < record_count; i++) {
        uint32_t network_value;
        fread(&network_value, sizeof(uint32_t), 1, file);
        read_data[i] = ntohl(network_value);
    }
    
    // Verify checksum
    uint32_t calculated_checksum = calculate_checksum(read_data, record_count * sizeof(uint32_t));
    printf("  Calculated checksum: 0x%08X %s\n", calculated_checksum,
           (calculated_checksum == stored_checksum) ? "✓" : "✗");
    
    // Display data
    printf("\nData records:\n");
    for (uint32_t i = 0; i < record_count; i++) {
        printf("  Record %u: %u\n", i + 1, read_data[i]);
    }
    
    fclose(file);
    free(read_data);
    printf("\n");
}

void demonstrate_performance_comparison(void) {
    printf("=== Performance Comparison ===\n");
    
    const int data_size = 100000;
    int* test_data = malloc(data_size * sizeof(int));
    
    // Initialize test data
    for (int i = 0; i < data_size; i++) {
        test_data[i] = i * i;
    }
    
    clock_t start, end;
    
    // Test 1: Write individual integers (many system calls)
    start = clock();
    FILE* file = fopen("perf_individual.bin", "wb");
    for (int i = 0; i < data_size; i++) {
        fwrite(&test_data[i], sizeof(int), 1, file);
    }
    fclose(file);
    end = clock();
    double individual_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Test 2: Write entire array (single system call)
    start = clock();
    file = fopen("perf_bulk.bin", "wb");
    fwrite(test_data, sizeof(int), data_size, file);
    fclose(file);
    end = clock();
    double bulk_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Test 3: Write with custom buffer
    start = clock();
    file = fopen("perf_buffered.bin", "wb");
    char custom_buffer[8192];
    setvbuf(file, custom_buffer, _IOFBF, sizeof(custom_buffer));
    for (int i = 0; i < data_size; i++) {
        fwrite(&test_data[i], sizeof(int), 1, file);
    }
    fclose(file);
    end = clock();
    double buffered_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Performance results for %d integers:\n", data_size);
    printf("  Individual writes: %.4f seconds\n", individual_time);
    printf("  Bulk write: %.4f seconds (%.1fx faster)\n", 
           bulk_time, individual_time / bulk_time);
    printf("  Buffered writes: %.4f seconds (%.1fx faster)\n",
           buffered_time, individual_time / buffered_time);
    
    // Verify file sizes are identical
    struct stat stat1, stat2, stat3;
    stat("perf_individual.bin", &stat1);
    stat("perf_bulk.bin", &stat2);
    stat("perf_buffered.bin", &stat3);
    
    printf("File sizes: %ld, %ld, %ld bytes %s\n",
           stat1.st_size, stat2.st_size, stat3.st_size,
           (stat1.st_size == stat2.st_size && stat2.st_size == stat3.st_size) ? "✓" : "✗");
    
    free(test_data);
    
    // Cleanup performance test files
    remove("perf_individual.bin");
    remove("perf_bulk.bin");
    remove("perf_buffered.bin");
    printf("\n");
}

uint32_t calculate_checksum(const void* data, size_t size) {
    const unsigned char* bytes = (const unsigned char*)data;
    uint32_t checksum = 0;
    
    for (size_t i = 0; i < size; i++) {
        checksum = (checksum << 1) ^ bytes[i];
    }
    
    return checksum;
}

void show_binary_data_layout(const void* data, size_t size, const char* description) {
    const unsigned char* bytes = (const unsigned char*)data;
    
    printf("%s (%zu bytes):\n", description, size);
    printf("  Hex: ");
    for (size_t i = 0; i < size && i < 16; i++) {
        printf("%02X ", bytes[i]);
    }
    if (size > 16) printf("...");
    printf("\n");
    
    printf("  ASCII: ");
    for (size_t i = 0; i < size && i < 16; i++) {
        printf("%c", (bytes[i] >= 32 && bytes[i] <= 126) ? bytes[i] : '.');
    }
    if (size > 16) printf("...");
    printf("\n");
}

int main(void) {
    printf("Binary File Operations - Data Serialization and Binary I/O\n");
    printf("==========================================================\n");
    
    demonstrate_binary_vs_text();
    demonstrate_structure_serialization();
    demonstrate_endianness_handling();
    demonstrate_binary_file_format();
    demonstrate_performance_comparison();
    
    printf("=== Key Implementation Details ===\n");
    printf("1. Binary files store data in native machine format\n");
    printf("2. Endianness affects multi-byte data portability\n");
    printf("3. Structure padding affects binary serialization\n");
    printf("4. Binary I/O is faster than text conversion\n");
    printf("5. Custom file formats need headers and validation\n");
    printf("6. Bulk operations are much faster than individual calls\n");
    
    // Cleanup test files
    remove("numbers_text.txt");
    remove("numbers_binary.bin");
    remove("company_data.bin");
    remove("portable_data.bin");
    remove("custom_format.dat");
    printf("\nTest files cleaned up\n");
    
    return 0;
}