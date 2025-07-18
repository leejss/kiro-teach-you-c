/*
 * Simple Calculator - Arithmetic Operations in C
 * 
 * This is a classic C programming exercise that demonstrates:
 * - Variable declaration and initialization
 * - Arithmetic operations
 * - Different data types for different purposes
 * - Basic input/output formatting
 * 
 * Note: This is a fundamental C programming problem, similar to
 * how you might handle numeric operations in JavaScript, but
 * with C's static typing and explicit type handling.
 */

#include <stdio.h>

int main() {
    printf("=== Simple Calculator ===\n\n");
    
    // Declare variables for our calculations
    double num1 = 15.5;
    double num2 = 4.2;
    
    printf("Number 1: %.2f\n", num1);
    printf("Number 2: %.2f\n", num2);
    printf("\n");
    
    // Basic arithmetic operations
    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    double quotient = num1 / num2;
    
    printf("Arithmetic Results:\n");
    printf("%.2f + %.2f = %.2f\n", num1, num2, sum);
    printf("%.2f - %.2f = %.2f\n", num1, num2, difference);
    printf("%.2f * %.2f = %.2f\n", num1, num2, product);
    printf("%.2f / %.2f = %.2f\n", num1, num2, quotient);
    printf("\n");
    
    // Integer operations (different behavior)
    int int_a = 17;
    int int_b = 5;
    
    printf("Integer Operations:\n");
    printf("%d + %d = %d\n", int_a, int_b, int_a + int_b);
    printf("%d - %d = %d\n", int_a, int_b, int_a - int_b);
    printf("%d * %d = %d\n", int_a, int_b, int_a * int_b);
    printf("%d / %d = %d (integer division - no decimals)\n", int_a, int_b, int_a / int_b);
    printf("%d %% %d = %d (remainder/modulo)\n", int_a, int_b, int_a % int_b);
    printf("\n");
    
    // Mixed type operations (automatic type conversion)
    int integer_val = 10;
    double double_val = 3.5;
    double mixed_result = integer_val * double_val;
    
    printf("Mixed Type Operations:\n");
    printf("int %d * double %.1f = %.1f\n", integer_val, double_val, mixed_result);
    printf("(Result is automatically converted to double)\n");
    printf("\n");
    
    // Compound assignment operators
    int counter = 5;
    printf("Compound Assignment:\n");
    printf("Initial counter: %d\n", counter);
    
    counter += 3;  // Same as: counter = counter + 3
    printf("After += 3: %d\n", counter);
    
    counter *= 2;  // Same as: counter = counter * 2
    printf("After *= 2: %d\n", counter);
    
    counter /= 4;  // Same as: counter = counter / 4
    printf("After /= 4: %d\n", counter);
    
    return 0;
}