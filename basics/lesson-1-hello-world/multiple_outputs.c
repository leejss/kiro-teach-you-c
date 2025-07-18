/*
 * Multiple Outputs - Understanding Program Flow
 * 
 * This example shows how C programs execute sequentially
 * and demonstrates different ways to output text
 */

#include <stdio.h>

int main() {
    // Sequential execution - each line runs in order
    printf("Starting the program...\n");
    
    // Multiple printf calls (no automatic newlines)
    printf("This is ");
    printf("all on ");
    printf("one line.\n");
    
    // Using different format specifiers
    printf("Line 1\n");
    printf("Line 2\n");
    printf("Line 3\n");
    
    // Demonstrating that printf returns a value (number of characters printed)
    int chars_printed = printf("This line has some characters\n");
    printf("Previous line printed %d characters\n", chars_printed);
    
    printf("Program finished successfully!\n");
    
    return 0;
}