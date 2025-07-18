/*
 * Basic Input/Output - Fundamental C I/O Operations
 * 
 * This example demonstrates the core input/output functions in C.
 * These are essential C programming skills for any interactive program.
 * 
 * Key C Programming Concepts:
 * - printf() for formatted output
 * - scanf() for formatted input
 * - Format specifiers (%d, %f, %c, %s)
 * - Input/output streams (stdin, stdout)
 */

#include <stdio.h>

int main() {
    printf("=== Basic Input/Output in C ===\n\n");
    
    // Basic output with printf
    printf("Different output methods:\n");
    printf("Simple text\n");
    puts("Using puts() - automatically adds newline");
    putchar('A');
    putchar('\n');  // Manual newline after putchar
    printf("\n");
    
    // Formatted output with different types
    int age = 25;
    float height = 5.9f;
    char grade = 'A';
    
    printf("Formatted Output Examples:\n");
    printf("Age: %d years\n", age);
    printf("Height: %.1f feet\n", height);
    printf("Grade: %c\n", grade);
    printf("Hexadecimal age: %x\n", age);
    printf("Age with padding: %05d\n", age);  // Pad with zeros
    printf("\n");
    
    // Getting input from user
    int user_age;
    float user_height;
    char user_grade;
    
    printf("=== Input Examples ===\n");
    printf("Enter your age: ");
    scanf("%d", &user_age);  // Note: & is address-of operator
    
    printf("Enter your height (feet): ");
    scanf("%f", &user_height);
    
    printf("Enter your grade (A-F): ");
    scanf(" %c", &user_grade);  // Space before %c to skip whitespace
    
    // Display the input back
    printf("\nYou entered:\n");
    printf("Age: %d\n", user_age);
    printf("Height: %.1f feet\n", user_height);
    printf("Grade: %c\n", user_grade);
    
    // Calculations with input
    int birth_year = 2024 - user_age;
    float height_in_inches = user_height * 12.0f;
    
    printf("\nCalculated values:\n");
    printf("Estimated birth year: %d\n", birth_year);
    printf("Height in inches: %.1f\n", height_in_inches);
    
    // Character input/output
    printf("\nPress any key and Enter: ");
    char key = getchar();  // Read single character
    getchar();  // Consume the newline left by previous scanf
    
    printf("You pressed: %c (ASCII: %d)\n", key, key);
    
    return 0;
}