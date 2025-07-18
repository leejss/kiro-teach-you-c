/*
 * Number Base Converter - Format Specifiers and Conversions
 * 
 * This example demonstrates advanced printf format specifiers
 * and number base conversions. This is a practical C programming
 * exercise that shows how C handles different number representations.
 * 
 * Key C Programming Concepts:
 * - Format specifiers (%d, %x, %o, %b)
 * - Number base conversions
 * - Input validation
 * - Formatted output control
 */

#include <stdio.h>

// Function to print binary representation (C doesn't have %b)
void print_binary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    
    // Find the highest bit position
    int bit_position = 31;
    while (bit_position >= 0 && !(num & (1 << bit_position))) {
        bit_position--;
    }
    
    // Print bits from highest to lowest
    for (int i = bit_position; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Space every 4 bits
    }
}

int main() {
    printf("=== Number Base Converter ===\n\n");
    
    int number;
    
    printf("Enter a decimal number: ");
    if (scanf("%d", &number) != 1) {
        printf("Error: Please enter a valid integer\n");
        return 1;
    }
    
    printf("\nNumber: %d\n", number);
    printf("Conversions:\n");
    printf("─────────────────────────────\n");
    
    // Different number base representations
    printf("Decimal:     %d\n", number);
    printf("Hexadecimal: %x (lowercase)\n", number);
    printf("Hexadecimal: %X (uppercase)\n", number);
    printf("Octal:       %o\n", number);
    printf("Binary:      ");
    print_binary(number);
    printf("\n\n");
    
    // Formatted output examples
    printf("Formatted Output Examples:\n");
    printf("─────────────────────────────\n");
    printf("With prefix:     0x%x (hex), 0%o (octal)\n", number, number);
    printf("Zero-padded:     %08d (decimal)\n", number);
    printf("Zero-padded hex: 0x%08x\n", number);
    printf("Right-aligned:   '%10d'\n", number);
    printf("Left-aligned:    '%-10d'\n", number);
    
    // Character representation (if printable)
    if (number >= 32 && number <= 126) {
        printf("ASCII character: '%c'\n", number);
    } else {
        printf("ASCII character: (not printable)\n");
    }
    
    // Demonstrate input in different bases
    printf("\n=== Input in Different Bases ===\n");
    
    int hex_input, octal_input;
    
    printf("Enter a hexadecimal number (e.g., ff): ");
    if (scanf("%x", &hex_input) == 1) {
        printf("Hex %x = Decimal %d\n", hex_input, hex_input);
    }
    
    printf("Enter an octal number (e.g., 77): ");
    if (scanf("%o", &octal_input) == 1) {
        printf("Octal %o = Decimal %d\n", octal_input, octal_input);
    }
    
    // Bitwise operations demonstration
    printf("\n=== Bitwise Operations ===\n");
    int a = 12;  // 1100 in binary
    int b = 10;  // 1010 in binary
    
    printf("a = %d (binary: ", a);
    print_binary(a);
    printf(")\n");
    
    printf("b = %d (binary: ", b);
    print_binary(b);
    printf(")\n");
    
    printf("a & b = %d (binary: ", a & b);
    print_binary(a & b);
    printf(")\n");
    
    printf("a | b = %d (binary: ", a | b);
    print_binary(a | b);
    printf(")\n");
    
    printf("a ^ b = %d (binary: ", a ^ b);
    print_binary(a ^ b);
    printf(")\n");
    
    return 0;
}