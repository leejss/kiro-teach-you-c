/*
 * Loop Patterns - Different Loop Types and Techniques
 * 
 * This example demonstrates:
 * - for loops with different patterns
 * - while loops for condition-based iteration
 * - do-while loops for at-least-once execution
 * - Nested loops and loop control
 * 
 * Understanding different loop patterns is essential for
 * C programming and algorithm implementation.
 */

#include <stdio.h>

int main() {
    printf("=== Loop Patterns in C ===\n\n");
    
    // 1. Basic for loop
    printf("1. Basic for loop (counting 1 to 5):\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 2. Reverse for loop
    printf("2. Reverse for loop (counting 5 to 1):\n");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 3. Step-by-step for loop
    printf("3. For loop with step of 2 (even numbers 0-10):\n");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 4. While loop example
    printf("4. While loop (powers of 2 less than 100):\n");
    int power = 1;
    while (power < 100) {
        printf("%d ", power);
        power *= 2;
    }
    printf("\n\n");
    
    // 5. Do-while loop example
    printf("5. Do-while loop (user input validation):\n");
    int number;
    do {
        printf("Enter a number between 1 and 10: ");
        if (scanf("%d", &number) != 1) {
            printf("Invalid input!\n");
            // Clear input buffer
            while (getchar() != '\n');
            number = 0; // Force loop to continue
        } else if (number < 1 || number > 10) {
            printf("Number must be between 1 and 10!\n");
        }
    } while (number < 1 || number > 10);
    printf("You entered: %d\n\n", number);
    
    // 6. Nested loops - multiplication table
    printf("6. Nested loops (5x5 multiplication table):\n");
    printf("   ");
    for (int i = 1; i <= 5; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    for (int i = 1; i <= 5; i++) {
        printf("%2d:", i);
        for (int j = 1; j <= 5; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    printf("\n");
    
    // 7. Loop with break and continue
    printf("7. Loop with break and continue (skip even, stop at 15):\n");
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            continue; // Skip even numbers
        }
        if (i > 15) {
            break; // Stop when i > 15
        }
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 8. Pattern printing with nested loops
    printf("8. Pattern printing (right triangle):\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    
    // 9. Array processing with loops
    printf("9. Array processing (find sum and average):\n");
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;
    
    printf("Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
        sum += numbers[i];
    }
    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n\n", (double)sum / size);
    
    // 10. Factorial calculation
    printf("10. Factorial calculation using loop:\n");
    int n = 6;
    long factorial = 1;
    
    printf("Calculating %d! = ", n);
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        printf("%d", i);
        if (i < n) printf(" × ");
    }
    printf(" = %ld\n\n", factorial);
    
    // 11. Prime number checking
    printf("11. Prime number checking (numbers 2-20):\n");
    printf("Prime numbers: ");
    for (int num = 2; num <= 20; num++) {
        int is_prime = 1; // Assume prime
        
        // Check for factors
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                is_prime = 0; // Not prime
                break;
            }
        }
        
        if (is_prime) {
            printf("%d ", num);
        }
    }
    printf("\n\n");
    
    // 12. Fibonacci sequence
    printf("12. Fibonacci sequence (first 10 numbers):\n");
    int fib1 = 0, fib2 = 1, next;
    printf("Fibonacci: %d %d ", fib1, fib2);
    
    for (int i = 3; i <= 10; i++) {
        next = fib1 + fib2;
        printf("%d ", next);
        fib1 = fib2;
        fib2 = next;
    }
    printf("\n\n");
    
    printf("Loop patterns demonstration complete!\n");
    
    return 0;
}