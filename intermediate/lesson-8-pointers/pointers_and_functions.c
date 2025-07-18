/*
 * Pointers and Functions - Parameter Passing and Function Pointers
 * 
 * This program demonstrates:
 * - Pass by value vs pass by reference
 * - Function parameters with pointers
 * - Returning pointers from functions
 * - Function pointers and callbacks
 * 
 * For frontend developers: This is like JavaScript's object reference
 * passing, but with explicit control over what gets modified.
 */

#include <stdio.h>
#include <string.h>

// Function prototypes
void pass_by_value_demo(int value);
void pass_by_reference_demo(int* value_ptr);
void swap_values(int* a, int* b);
void modify_array(int* arr, int size);
char* find_character(char* str, char target);
int* find_maximum(int* arr, int size);

// Function pointer demonstrations
int add(int a, int b);
int multiply(int a, int b);
void calculate_and_print(int x, int y, int (*operation)(int, int), const char* op_name);

void demonstrate_pass_by_value_vs_reference(void) {
    printf("=== Pass by Value vs Pass by Reference ===\n");
    
    int original = 100;
    
    printf("Original value: %d\n", original);
    
    // Pass by value - original unchanged
    printf("\nCalling pass_by_value_demo(original):\n");
    pass_by_value_demo(original);
    printf("After pass by value, original = %d\n", original);
    
    // Pass by reference - original modified
    printf("\nCalling pass_by_reference_demo(&original):\n");
    pass_by_reference_demo(&original);
    printf("After pass by reference, original = %d\n", original);
}

void pass_by_value_demo(int value) {
    printf("  Inside function: received value = %d\n", value);
    value = 999;  // This only modifies the local copy
    printf("  Inside function: modified value = %d\n", value);
}

void pass_by_reference_demo(int* value_ptr) {
    printf("  Inside function: received pointer to %p\n", (void*)value_ptr);
    printf("  Inside function: dereferenced value = %d\n", *value_ptr);
    *value_ptr = 999;  // This modifies the original variable
    printf("  Inside function: modified original to %d\n", *value_ptr);
}

void demonstrate_swap_function(void) {
    printf("\n=== Swapping Values Using Pointers ===\n");
    
    int first = 42;
    int second = 84;
    
    printf("Before swap: first = %d, second = %d\n", first, second);
    swap_values(&first, &second);
    printf("After swap: first = %d, second = %d\n", first, second);
}

void swap_values(int* a, int* b) {
    printf("  Swapping values at %p and %p\n", (void*)a, (void*)b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demonstrate_array_modification(void) {
    printf("\n=== Modifying Arrays Through Function Parameters ===\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Arrays are automatically passed as pointers
    modify_array(numbers, size);
    
    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void modify_array(int* arr, int size) {
    printf("  Inside function: array address = %p\n", (void*)arr);
    for (int i = 0; i < size; i++) {
        arr[i] *= 10;  // Multiply each element by 10
    }
}

void demonstrate_returning_pointers(void) {
    printf("\n=== Returning Pointers from Functions ===\n");
    
    char text[] = "Hello, World!";
    char target = 'W';
    
    printf("Searching for '%c' in \"%s\"\n", target, text);
    
    char* found = find_character(text, target);
    if (found != NULL) {
        printf("Found '%c' at position %ld\n", *found, found - text);
        printf("Remaining string: \"%s\"\n", found);
    } else {
        printf("Character '%c' not found\n", target);
    }
    
    // Finding maximum in array
    int values[] = {23, 67, 12, 89, 45, 34};
    int count = sizeof(values) / sizeof(values[0]);
    
    int* max_ptr = find_maximum(values, count);
    if (max_ptr != NULL) {
        printf("\nMaximum value %d found at index %ld\n", 
               *max_ptr, max_ptr - values);
    }
}

char* find_character(char* str, char target) {
    while (*str != '\0') {
        if (*str == target) {
            return str;  // Return pointer to found character
        }
        str++;
    }
    return NULL;  // Character not found
}

int* find_maximum(int* arr, int size) {
    if (arr == NULL || size <= 0) {
        return NULL;
    }
    
    int* max_ptr = arr;
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max_ptr) {
            max_ptr = &arr[i];
        }
    }
    return max_ptr;
}

void demonstrate_function_pointers(void) {
    printf("\n=== Function Pointers and Callbacks ===\n");
    
    int x = 15, y = 25;
    
    printf("Demonstrating function pointers with x = %d, y = %d\n", x, y);
    
    // Function pointers - like JavaScript callbacks
    calculate_and_print(x, y, add, "addition");
    calculate_and_print(x, y, multiply, "multiplication");
    
    // Array of function pointers
    int (*operations[])(int, int) = {add, multiply};
    const char* names[] = {"add", "multiply"};
    
    printf("\nUsing array of function pointers:\n");
    for (int i = 0; i < 2; i++) {
        int result = operations[i](x, y);
        printf("  %s(%d, %d) = %d\n", names[i], x, y, result);
    }
    
    // Direct function pointer assignment
    int (*current_op)(int, int) = add;
    printf("\nDirect function pointer usage:\n");
    printf("  current_op points to add: %d + %d = %d\n", x, y, current_op(x, y));
    
    current_op = multiply;
    printf("  current_op points to multiply: %d * %d = %d\n", x, y, current_op(x, y));
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void calculate_and_print(int x, int y, int (*operation)(int, int), const char* op_name) {
    int result = operation(x, y);
    printf("  %s: %d and %d = %d\n", op_name, x, y, result);
}

void demonstrate_pointer_parameters_best_practices(void) {
    printf("\n=== Pointer Parameter Best Practices ===\n");
    
    // Always check for NULL pointers
    printf("Testing NULL pointer safety:\n");
    
    int* null_ptr = NULL;
    printf("  Checking NULL before use: ");
    if (null_ptr != NULL) {
        printf("Safe to use: %d\n", *null_ptr);
    } else {
        printf("NULL pointer detected - avoiding crash!\n");
    }
    
    // Use const for read-only parameters
    const char* message = "Read-only string";
    printf("  Read-only parameter: \"%s\"\n", message);
    
    // Demonstrate array size passing
    int data[] = {10, 20, 30};
    int data_size = sizeof(data) / sizeof(data[0]);
    
    printf("  Always pass array size with pointer:\n");
    printf("    Array address: %p\n", (void*)data);
    printf("    Array size: %d elements\n", data_size);
}

int main(void) {
    printf("Pointers and Functions - Parameter Passing and Callbacks\n");
    printf("=======================================================\n");
    
    demonstrate_pass_by_value_vs_reference();
    demonstrate_swap_function();
    demonstrate_array_modification();
    demonstrate_returning_pointers();
    demonstrate_function_pointers();
    demonstrate_pointer_parameters_best_practices();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Use pointers to modify variables in calling function\n");
    printf("2. Arrays are automatically passed as pointers\n");
    printf("3. Always check for NULL before dereferencing\n");
    printf("4. Function pointers enable callbacks and dynamic dispatch\n");
    printf("5. Pass array size along with pointer parameters\n");
    
    return 0;
}