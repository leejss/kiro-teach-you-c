/*
 * Input Validation - Robust Input Handling in C
 * 
 * This example demonstrates proper input validation techniques in C.
 * Input validation is crucial in C programming because there's no
 * automatic type conversion like in JavaScript.
 * 
 * Key C Programming Concepts:
 * - scanf return value checking
 * - Input buffer clearing
 * - Error handling and recovery
 * - Safe input practices
 */

#include <stdio.h>
#include <string.h>

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to get a valid integer
int get_valid_integer(const char* prompt) {
    int value;
    int result;
    
    do {
        printf("%s", prompt);
        result = scanf("%d", &value);
        
        if (result != 1) {
            printf("Error: Please enter a valid integer.\n");
            clear_input_buffer();
        } else {
            clear_input_buffer();  // Clear any remaining input
            return value;
        }
    } while (1);
}

// Function to get a valid float
float get_valid_float(const char* prompt) {
    float value;
    int result;
    
    do {
        printf("%s", prompt);
        result = scanf("%f", &value);
        
        if (result != 1) {
            printf("Error: Please enter a valid number.\n");
            clear_input_buffer();
        } else {
            clear_input_buffer();
            return value;
        }
    } while (1);
}

// Function to get a valid character from a set
char get_valid_char(const char* prompt, const char* valid_chars) {
    char input;
    
    do {
        printf("%s", prompt);
        scanf(" %c", &input);  // Space before %c to skip whitespace
        clear_input_buffer();
        
        if (strchr(valid_chars, input) != NULL) {
            return input;
        } else {
            printf("Error: Please enter one of: %s\n", valid_chars);
        }
    } while (1);
}

// Function to get a string with length validation
void get_valid_string(const char* prompt, char* buffer, int max_length) {
    do {
        printf("%s", prompt);
        if (fgets(buffer, max_length, stdin) != NULL) {
            // Remove newline if present
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n') {
                buffer[len-1] = '\0';
            }
            
            if (strlen(buffer) > 0) {
                return;  // Valid non-empty string
            } else {
                printf("Error: Please enter a non-empty string.\n");
            }
        } else {
            printf("Error: Failed to read input.\n");
        }
    } while (1);
}

int main() {
    printf("=== Input Validation Examples ===\n\n");
    
    // Example 1: Validated integer input
    printf("Example 1: Integer Input Validation\n");
    int age = get_valid_integer("Enter your age (0-150): ");
    
    // Additional validation for range
    while (age < 0 || age > 150) {
        printf("Age must be between 0 and 150.\n");
        age = get_valid_integer("Enter your age (0-150): ");
    }
    printf("Valid age entered: %d\n\n", age);
    
    // Example 2: Validated float input
    printf("Example 2: Float Input Validation\n");
    float temperature = get_valid_float("Enter temperature in Celsius: ");
    printf("Temperature: %.1f°C (%.1f°F)\n\n", temperature, temperature * 9.0f/5.0f + 32.0f);
    
    // Example 3: Character validation
    printf("Example 3: Character Input Validation\n");
    char grade = get_valid_char("Enter grade (A, B, C, D, F): ", "ABCDF");
    printf("Grade entered: %c\n\n", grade);
    
    // Example 4: String validation
    printf("Example 4: String Input Validation\n");
    char name[50];
    get_valid_string("Enter your name: ", name, sizeof(name));
    printf("Name entered: %s\n\n", name);
    
    // Example 5: Menu with validation
    printf("Example 5: Menu Selection\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    
    int choice = get_valid_integer("Select operation (1-4): ");
    while (choice < 1 || choice > 4) {
        printf("Please select a number between 1 and 4.\n");
        choice = get_valid_integer("Select operation (1-4): ");
    }
    
    float num1 = get_valid_float("Enter first number: ");
    float num2 = get_valid_float("Enter second number: ");
    
    printf("\nCalculation Result:\n");
    switch (choice) {
        case 1:
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case 4:
            if (num2 != 0.0f) {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
    }
    
    printf("\nAll inputs were validated successfully!\n");
    
    return 0;
}