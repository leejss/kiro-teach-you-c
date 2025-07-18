/*
 * Basic Variables - C Data Types and Declaration
 * 
 * This example demonstrates fundamental C variable types,
 * declaration, initialization, and basic operations.
 * 
 * Key C Programming Concepts:
 * - Static typing (types declared at compile time)
 * - Variable declaration and initialization
 * - Different integer and floating-point types
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== C Variable Types and Operations ===\n\n");
    
    // Integer types - different sizes for different needs
    char small_num = 100;          // 1 byte: -128 to 127
    short medium_num = 30000;      // 2 bytes: -32,768 to 32,767
    int regular_num = 2000000;     // 4 bytes: ~-2B to 2B
    long big_num = 9000000000L;    // 8 bytes: very large numbers
    
    printf("Integer Types:\n");
    printf("char:  %d (1 byte)\n", small_num);
    printf("short: %d (2 bytes)\n", medium_num);
    printf("int:   %d (4 bytes)\n", regular_num);
    printf("long:  %ld (8 bytes)\n", big_num);
    printf("\n");
    
    // Floating point types - for decimal numbers
    float single_precision = 3.14159f;     // 4 bytes
    double double_precision = 3.141592653589793; // 8 bytes
    
    printf("Floating Point Types:\n");
    printf("float:  %.5f (4 bytes)\n", single_precision);
    printf("double: %.15f (8 bytes)\n", double_precision);
    printf("\n");
    
    // Character type - for single characters
    char letter = 'A';
    char digit = '5';
    
    printf("Character Types:\n");
    printf("Letter: %c (ASCII: %d)\n", letter, letter);
    printf("Digit:  %c (ASCII: %d)\n", digit, digit);
    printf("\n");
    
    // Boolean type (requires stdbool.h)
    bool is_true = true;
    bool is_false = false;
    
    printf("Boolean Types:\n");
    printf("True:  %s\n", is_true ? "true" : "false");
    printf("False: %s\n", is_false ? "true" : "false");
    printf("\n");
    
    // Variable operations
    int a = 10;
    int b = 3;
    
    printf("Arithmetic Operations:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d (integer division)\n", a / b);
    printf("a %% b = %d (remainder)\n", a % b);
    
    return 0;
}