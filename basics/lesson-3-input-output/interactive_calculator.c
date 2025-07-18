/*
 * Interactive Calculator - User Input and Processing
 * 
 * This is a classic C programming exercise that demonstrates:
 * - Interactive user input with scanf
 * - Menu-driven program structure
 * - Input validation and error handling
 * - Formatted output for results
 * 
 * This type of program is fundamental in C programming education
 * and demonstrates practical I/O usage.
 */

#include <stdio.h>

int main() {
    printf("=== Interactive Calculator ===\n\n");
    
    double num1, num2, result;
    char operation;
    
    // Get first number
    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Error: Invalid number format\n");
        return 1;
    }
    
    // Get operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);  // Space before %c to skip whitespace
    
    // Get second number
    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Error: Invalid number format\n");
        return 1;
    }
    
    printf("\n");
    
    // Perform calculation based on operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '/':
            if (num2 == 0.0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            break;
            
        default:
            printf("Error: Unknown operation '%c'\n", operation);
            printf("Supported operations: +, -, *, /\n");
            return 1;
    }
    
    // Additional information
    printf("\nAdditional Information:\n");
    
    if (result > 0) {
        printf("Result is positive\n");
    } else if (result < 0) {
        printf("Result is negative\n");
    } else {
        printf("Result is zero\n");
    }
    
    // Show result in different formats
    printf("Result in different formats:\n");
    printf("Decimal: %.6f\n", result);
    printf("Scientific: %.2e\n", result);
    printf("Integer part: %d\n", (int)result);
    
    return 0;
}