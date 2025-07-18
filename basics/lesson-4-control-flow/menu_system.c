/*
 * Menu System - Switch Statements and Program Structure
 * 
 * This example demonstrates:
 * - switch statements for menu navigation
 * - do-while loops for menu repetition
 * - Function-like code organization within main
 * - Input validation and error handling
 * 
 * Menu-driven programs are a classic C programming pattern
 * used in many command-line utilities and system programs.
 */

#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    int continue_program = 1;
    
    printf("=== Calculator Menu System ===\n");
    
    // Main program loop
    do {
        // Display menu
        printf("\n--- Main Menu ---\n");
        printf("1. Basic Calculator\n");
        printf("2. Area Calculator\n");
        printf("3. Temperature Converter\n");
        printf("4. Number Analysis\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        // Get user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }
        
        // Process menu choice using switch statement
        switch (choice) {
            case 1: {
                // Basic Calculator
                printf("\n--- Basic Calculator ---\n");
                double num1, num2;
                char operation;
                
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter operation (+, -, *, /): ");
                scanf(" %c", &operation);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                
                switch (operation) {
                    case '+':
                        printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                        break;
                    case '-':
                        printf("Result: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                        break;
                    case '*':
                        printf("Result: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                        break;
                    case '/':
                        if (num2 != 0) {
                            printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                        } else {
                            printf("Error: Division by zero!\n");
                        }
                        break;
                    default:
                        printf("Error: Unknown operation '%c'\n", operation);
                }
                break;
            }
            
            case 2: {
                // Area Calculator
                printf("\n--- Area Calculator ---\n");
                printf("1. Rectangle\n");
                printf("2. Circle\n");
                printf("3. Triangle\n");
                printf("Choose shape: ");
                
                int shape_choice;
                scanf("%d", &shape_choice);
                
                switch (shape_choice) {
                    case 1: {
                        double length, width;
                        printf("Enter length: ");
                        scanf("%lf", &length);
                        printf("Enter width: ");
                        scanf("%lf", &width);
                        printf("Rectangle area: %.2f\n", length * width);
                        break;
                    }
                    case 2: {
                        double radius;
                        printf("Enter radius: ");
                        scanf("%lf", &radius);
                        printf("Circle area: %.2f\n", M_PI * radius * radius);
                        break;
                    }
                    case 3: {
                        double base, height;
                        printf("Enter base: ");
                        scanf("%lf", &base);
                        printf("Enter height: ");
                        scanf("%lf", &height);
                        printf("Triangle area: %.2f\n", 0.5 * base * height);
                        break;
                    }
                    default:
                        printf("Invalid shape choice!\n");
                }
                break;
            }
            
            case 3: {
                // Temperature Converter
                printf("\n--- Temperature Converter ---\n");
                printf("1. Celsius to Fahrenheit\n");
                printf("2. Fahrenheit to Celsius\n");
                printf("Choose conversion: ");
                
                int temp_choice;
                double temperature;
                scanf("%d", &temp_choice);
                
                switch (temp_choice) {
                    case 1:
                        printf("Enter temperature in Celsius: ");
                        scanf("%lf", &temperature);
                        printf("%.1f°C = %.1f°F\n", temperature, (temperature * 9.0/5.0) + 32);
                        break;
                    case 2:
                        printf("Enter temperature in Fahrenheit: ");
                        scanf("%lf", &temperature);
                        printf("%.1f°F = %.1f°C\n", temperature, (temperature - 32) * 5.0/9.0);
                        break;
                    default:
                        printf("Invalid conversion choice!\n");
                }
                break;
            }
            
            case 4: {
                // Number Analysis
                printf("\n--- Number Analysis ---\n");
                int number;
                printf("Enter an integer: ");
                scanf("%d", &number);
                
                printf("Analysis of %d:\n", number);
                
                // Even or odd
                if (number % 2 == 0) {
                    printf("- Even number\n");
                } else {
                    printf("- Odd number\n");
                }
                
                // Positive, negative, or zero
                if (number > 0) {
                    printf("- Positive number\n");
                } else if (number < 0) {
                    printf("- Negative number\n");
                } else {
                    printf("- Zero\n");
                }
                
                // Divisibility tests
                printf("- Divisible by 3: %s\n", (number % 3 == 0) ? "Yes" : "No");
                printf("- Divisible by 5: %s\n", (number % 5 == 0) ? "Yes" : "No");
                printf("- Divisible by 10: %s\n", (number % 10 == 0) ? "Yes" : "No");
                
                break;
            }
            
            case 5:
                printf("Thank you for using the calculator!\n");
                continue_program = 0;
                break;
                
            default:
                printf("Invalid choice! Please select 1-5.\n");
                break;
        }
        
        // Pause before showing menu again (except when exiting)
        if (continue_program) {
            printf("\nPress Enter to continue...");
            getchar(); // Consume newline from previous input
            getchar(); // Wait for user to press Enter
        }
        
    } while (continue_program);
    
    return 0;
}