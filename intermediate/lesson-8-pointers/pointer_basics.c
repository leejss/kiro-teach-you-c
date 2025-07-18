/*
 * Pointer Basics - Understanding Memory Addresses and Dereferencing
 * 
 * This program demonstrates fundamental pointer concepts:
 * - Pointer declaration and initialization
 * - Address-of operator (&)
 * - Dereference operator (*)
 * - Memory address visualization
 * 
 * For frontend developers: Think of pointers like JavaScript object references,
 * but with explicit control over memory addresses.
 */

#include <stdio.h>

void demonstrate_basic_pointers(void) {
    printf("=== Basic Pointer Operations ===\n");
    
    // Declare and initialize variables
    int age = 25;
    double salary = 75000.50;
    char grade = 'A';
    
    // Declare pointers and initialize with addresses
    int* age_ptr = &age;
    double* salary_ptr = &salary;
    char* grade_ptr = &grade;
    
    // Display values and addresses
    printf("Direct access:\n");
    printf("  age = %d (at address %p)\n", age, (void*)&age);
    printf("  salary = %.2f (at address %p)\n", salary, (void*)&salary);
    printf("  grade = %c (at address %p)\n", grade, (void*)&grade);
    
    printf("\nPointer access:\n");
    printf("  age_ptr points to %p, value = %d\n", (void*)age_ptr, *age_ptr);
    printf("  salary_ptr points to %p, value = %.2f\n", (void*)salary_ptr, *salary_ptr);
    printf("  grade_ptr points to %p, value = %c\n", (void*)grade_ptr, *grade_ptr);
    
    // Modify values through pointers
    printf("\n=== Modifying Values Through Pointers ===\n");
    *age_ptr = 26;
    *salary_ptr = 80000.00;
    *grade_ptr = 'A';
    
    printf("After modification through pointers:\n");
    printf("  age = %d\n", age);
    printf("  salary = %.2f\n", salary);
    printf("  grade = %c\n", grade);
}

void demonstrate_pointer_sizes(void) {
    printf("\n=== Pointer Sizes and Types ===\n");
    
    int value = 42;
    int* int_ptr = &value;
    double* double_ptr = NULL;
    char* char_ptr = NULL;
    void* void_ptr = &value;
    
    printf("Pointer sizes (all pointers are same size on this system):\n");
    printf("  int* size: %zu bytes\n", sizeof(int_ptr));
    printf("  double* size: %zu bytes\n", sizeof(double_ptr));
    printf("  char* size: %zu bytes\n", sizeof(char_ptr));
    printf("  void* size: %zu bytes\n", sizeof(void_ptr));
    
    printf("\nData type sizes:\n");
    printf("  int size: %zu bytes\n", sizeof(int));
    printf("  double size: %zu bytes\n", sizeof(double));
    printf("  char size: %zu bytes\n", sizeof(char));
}

void demonstrate_null_pointers(void) {
    printf("\n=== NULL Pointer Safety ===\n");
    
    int* ptr = NULL;
    
    printf("Checking NULL pointer before use:\n");
    if (ptr == NULL) {
        printf("  ptr is NULL - safe to check!\n");
    }
    
    // Initialize pointer properly
    int value = 100;
    ptr = &value;
    
    if (ptr != NULL) {
        printf("  ptr is now valid, value = %d\n", *ptr);
    }
    
    // Demonstrate pointer comparison
    int another_value = 200;
    int* another_ptr = &another_value;
    
    printf("\nPointer comparisons:\n");
    printf("  ptr == another_ptr: %s\n", (ptr == another_ptr) ? "true" : "false");
    printf("  *ptr == *another_ptr: %s\n", (*ptr == *another_ptr) ? "true" : "false");
}

void demonstrate_pointer_to_pointer(void) {
    printf("\n=== Pointer to Pointer ===\n");
    
    int value = 42;
    int* ptr = &value;
    int** ptr_to_ptr = &ptr;
    
    printf("Multi-level indirection:\n");
    printf("  value = %d\n", value);
    printf("  *ptr = %d\n", *ptr);
    printf("  **ptr_to_ptr = %d\n", **ptr_to_ptr);
    
    printf("\nAddresses:\n");
    printf("  &value = %p\n", (void*)&value);
    printf("  ptr = %p\n", (void*)ptr);
    printf("  &ptr = %p\n", (void*)&ptr);
    printf("  ptr_to_ptr = %p\n", (void*)ptr_to_ptr);
    
    // Modify through double pointer
    **ptr_to_ptr = 84;
    printf("\nAfter modifying through double pointer:\n");
    printf("  value = %d\n", value);
}

int main(void) {
    printf("Pointer Basics - Understanding Memory and References\n");
    printf("==================================================\n");
    
    demonstrate_basic_pointers();
    demonstrate_pointer_sizes();
    demonstrate_null_pointers();
    demonstrate_pointer_to_pointer();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Pointers store memory addresses, not values\n");
    printf("2. Use & to get address, * to dereference\n");
    printf("3. Always initialize pointers (use NULL if no initial target)\n");
    printf("4. Check for NULL before dereferencing\n");
    printf("5. All pointer types have same size (address size)\n");
    
    return 0;
}