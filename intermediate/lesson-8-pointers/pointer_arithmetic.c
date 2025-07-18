/*
 * Pointer Arithmetic - Array Traversal and Memory Navigation
 * 
 * This program demonstrates:
 * - Pointer arithmetic operations
 * - Array access via pointers
 * - Pointer and array relationship
 * - Memory layout understanding
 * 
 * For frontend developers: This is like manually iterating through
 * JavaScript arrays, but with direct memory address manipulation.
 */

#include <stdio.h>

void demonstrate_array_pointer_relationship(void) {
    printf("=== Array and Pointer Relationship ===\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // Same as &numbers[0]
    
    printf("Array contents and addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("  numbers[%d] = %d at address %p\n", 
               i, numbers[i], (void*)&numbers[i]);
    }
    
    printf("\nAccessing via pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("  *(ptr + %d) = %d at address %p\n", 
               i, *(ptr + i), (void*)(ptr + i));
    }
    
    printf("\nEquivalent expressions:\n");
    printf("  numbers[2] = %d\n", numbers[2]);
    printf("  *(numbers + 2) = %d\n", *(numbers + 2));
    printf("  *(ptr + 2) = %d\n", *(ptr + 2));
    printf("  ptr[2] = %d\n", ptr[2]);
}

void demonstrate_pointer_increment(void) {
    printf("\n=== Pointer Increment and Decrement ===\n");
    
    int data[] = {100, 200, 300, 400, 500};
    int* ptr = data;
    
    printf("Forward traversal using pointer increment:\n");
    for (int i = 0; i < 5; i++) {
        printf("  *ptr = %d (address: %p)\n", *ptr, (void*)ptr);
        ptr++;  // Move to next element
    }
    
    // Reset pointer to last element
    ptr = &data[4];
    
    printf("\nBackward traversal using pointer decrement:\n");
    for (int i = 4; i >= 0; i--) {
        printf("  *ptr = %d (address: %p)\n", *ptr, (void*)ptr);
        ptr--;  // Move to previous element
    }
}

void demonstrate_pointer_arithmetic_operations(void) {
    printf("\n=== Pointer Arithmetic Operations ===\n");
    
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double* start = values;
    double* end = values + 4;  // Points to last element
    
    printf("Pointer arithmetic with doubles:\n");
    printf("  start points to: %.1f (address: %p)\n", *start, (void*)start);
    printf("  end points to: %.1f (address: %p)\n", *end, (void*)end);
    
    // Pointer subtraction
    printf("  end - start = %ld elements\n", end - start);
    printf("  Address difference: %ld bytes\n", (char*)end - (char*)start);
    
    // Pointer comparison
    printf("\nPointer comparisons:\n");
    printf("  start < end: %s\n", (start < end) ? "true" : "false");
    printf("  start == values: %s\n", (start == values) ? "true" : "false");
    
    // Moving pointer by offset
    double* middle = start + 2;
    printf("  middle (start + 2) points to: %.1f\n", *middle);
}

void demonstrate_string_pointer_arithmetic(void) {
    printf("\n=== String Traversal with Pointers ===\n");
    
    char message[] = "Hello, World!";
    char* ptr = message;
    
    printf("Character-by-character traversal:\n");
    printf("String: \"%s\"\n", message);
    printf("Characters: ");
    
    while (*ptr != '\0') {
        printf("'%c' ", *ptr);
        ptr++;
    }
    printf("\n");
    
    // Count characters using pointer arithmetic
    ptr = message;
    int count = 0;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    printf("Character count: %d\n", count);
    
    // Alternative: pointer subtraction for length
    char* start = message;
    char* end_ptr = message;
    while (*end_ptr != '\0') {
        end_ptr++;
    }
    printf("Length via pointer subtraction: %ld\n", end_ptr - start);
}

void demonstrate_multidimensional_arrays(void) {
    printf("\n=== Multidimensional Arrays and Pointers ===\n");
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Pointer to first row
    int (*row_ptr)[4] = matrix;
    
    printf("Matrix traversal using pointer arithmetic:\n");
    for (int i = 0; i < 3; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < 4; j++) {
            // Multiple ways to access elements
            printf("%d ", (*(row_ptr + i))[j]);
            // Alternative: printf("%d ", *(*(row_ptr + i) + j));
        }
        printf("\n");
    }
    
    // Treating 2D array as 1D
    int* flat_ptr = (int*)matrix;
    printf("\nFlat traversal (treating 2D as 1D):\n");
    for (int i = 0; i < 12; i++) {
        printf("%d ", *(flat_ptr + i));
        if ((i + 1) % 4 == 0) printf("\n");
    }
}

void demonstrate_pointer_bounds_safety(void) {
    printf("\n=== Pointer Bounds and Safety ===\n");
    
    int safe_array[] = {1, 2, 3, 4, 5};
    int* ptr = safe_array;
    int array_size = sizeof(safe_array) / sizeof(safe_array[0]);
    
    printf("Safe array traversal with bounds checking:\n");
    for (int i = 0; i < array_size; i++) {
        if (ptr + i >= safe_array && ptr + i < safe_array + array_size) {
            printf("  safe_array[%d] = %d\n", i, *(ptr + i));
        } else {
            printf("  Index %d is out of bounds!\n", i);
        }
    }
    
    printf("\nDemonstrating pointer bounds:\n");
    printf("  Array start: %p\n", (void*)safe_array);
    printf("  Array end: %p\n", (void*)(safe_array + array_size));
    printf("  Current ptr: %p\n", (void*)ptr);
    printf("  Ptr + 10 (unsafe): %p\n", (void*)(ptr + 10));
}

int main(void) {
    printf("Pointer Arithmetic - Memory Navigation and Array Access\n");
    printf("=====================================================\n");
    
    demonstrate_array_pointer_relationship();
    demonstrate_pointer_increment();
    demonstrate_pointer_arithmetic_operations();
    demonstrate_string_pointer_arithmetic();
    demonstrate_multidimensional_arrays();
    demonstrate_pointer_bounds_safety();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Array names are pointers to first element\n");
    printf("2. ptr[i] is equivalent to *(ptr + i)\n");
    printf("3. Pointer arithmetic scales by data type size\n");
    printf("4. Always check bounds to avoid buffer overflows\n");
    printf("5. Pointer subtraction gives element count\n");
    
    return 0;
}