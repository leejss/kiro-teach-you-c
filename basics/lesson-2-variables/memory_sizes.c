/*
 * Memory Sizes - Understanding Data Type Storage
 * 
 * This example explores the sizeof operator and memory usage
 * of different C data types. This is a fundamental C concept
 * that helps understand memory efficiency and system programming.
 * 
 * Key C Programming Concepts:
 * - sizeof operator
 * - Memory footprint of different types
 * - Platform-dependent sizes
 * - Memory efficiency considerations
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== C Data Type Memory Sizes ===\n\n");
    
    // Basic integer types
    printf("Integer Type Sizes:\n");
    printf("char:      %zu bytes\n", sizeof(char));
    printf("short:     %zu bytes\n", sizeof(short));
    printf("int:       %zu bytes\n", sizeof(int));
    printf("long:      %zu bytes\n", sizeof(long));
    printf("long long: %zu bytes\n", sizeof(long long));
    printf("\n");
    
    // Floating point types
    printf("Floating Point Type Sizes:\n");
    printf("float:      %zu bytes\n", sizeof(float));
    printf("double:     %zu bytes\n", sizeof(double));
    printf("long double: %zu bytes\n", sizeof(long double));
    printf("\n");
    
    // Other types
    printf("Other Type Sizes:\n");
    printf("bool:       %zu bytes\n", sizeof(bool));
    printf("char*:      %zu bytes (pointer)\n", sizeof(char*));
    printf("int*:       %zu bytes (pointer)\n", sizeof(int*));
    printf("\n");
    
    // Array sizes
    int numbers[10];
    char text[50];
    double values[5];
    
    printf("Array Sizes:\n");
    printf("int[10]:    %zu bytes (%zu elements * %zu bytes each)\n", 
           sizeof(numbers), sizeof(numbers)/sizeof(int), sizeof(int));
    printf("char[50]:   %zu bytes (%zu elements * %zu bytes each)\n", 
           sizeof(text), sizeof(text)/sizeof(char), sizeof(char));
    printf("double[5]:  %zu bytes (%zu elements * %zu bytes each)\n", 
           sizeof(values), sizeof(values)/sizeof(double), sizeof(double));
    printf("\n");
    
    // Memory usage calculation example
    printf("=== Memory Usage Example ===\n");
    
    // Simulate a simple data record
    struct {
        int id;           // 4 bytes
        char name[20];    // 20 bytes
        double salary;    // 8 bytes
        bool active;      // 1 byte
    } employee_record;
    
    printf("Employee Record Structure:\n");
    printf("int id:        %zu bytes\n", sizeof(employee_record.id));
    printf("char name[20]: %zu bytes\n", sizeof(employee_record.name));
    printf("double salary: %zu bytes\n", sizeof(employee_record.salary));
    printf("bool active:   %zu bytes\n", sizeof(employee_record.active));
    printf("Total size:    %zu bytes\n", sizeof(employee_record));
    printf("\n");
    
    // Memory efficiency demonstration
    int num_employees = 1000;
    size_t total_memory = sizeof(employee_record) * num_employees;
    
    printf("Memory for %d employees: %zu bytes (%.2f KB)\n", 
           num_employees, total_memory, total_memory / 1024.0);
    
    printf("\nNote: Actual memory usage may include padding for alignment.\n");
    printf("C gives you precise control over memory usage!\n");
    
    return 0;
}