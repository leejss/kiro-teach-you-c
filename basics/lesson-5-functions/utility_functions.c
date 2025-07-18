/*
 * Utility Functions - Common Programming Patterns
 * 
 * This example demonstrates:
 * - Utility functions for common tasks
 * - String and array processing functions
 * - Input validation functions
 * - Helper functions for data processing
 * 
 * These are practical utility functions that appear in
 * real C programs and demonstrate good programming practices.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void printSeparator(char character, int length);
void printArray(int array[], int size);
int findMax(int array[], int size);
int findMin(int array[], int size);
double calculateAverage(int array[], int size);
int countDigits(int number);
int reverseNumber(int number);
int isPalindrome(int number);
void toLowerCase(char str[]);
void toUpperCase(char str[]);
int countWords(char str[]);
void printNumberInWords(int digit);
int validateRange(int value, int min, int max);

int main() {
    printf("=== Utility Functions Demonstration ===\n\n");
    
    // Array processing utilities
    printSeparator('=', 40);
    printf("Array Processing Utilities\n");
    printSeparator('=', 40);
    
    int numbers[] = {45, 23, 78, 12, 67, 34, 89, 56};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array: ");
    printArray(numbers, size);
    printf("Maximum: %d\n", findMax(numbers, size));
    printf("Minimum: %d\n", findMin(numbers, size));
    printf("Average: %.2f\n", calculateAverage(numbers, size));
    printf("\n");
    
    // Number utilities
    printSeparator('-', 40);
    printf("Number Utilities\n");
    printSeparator('-', 40);
    
    int testNumber = 12321;
    printf("Number: %d\n", testNumber);
    printf("Digit count: %d\n", countDigits(testNumber));
    printf("Reversed: %d\n", reverseNumber(testNumber));
    printf("Is palindrome: %s\n", isPalindrome(testNumber) ? "Yes" : "No");
    printf("\n");
    
    // String utilities
    printSeparator('-', 40);
    printf("String Utilities\n");
    printSeparator('-', 40);
    
    char text1[] = "Hello World Programming";
    char text2[] = "CONVERT TO LOWERCASE";
    
    printf("Original: %s\n", text1);
    printf("Word count: %d\n", countWords(text1));
    
    toLowerCase(text2);
    printf("Lowercase: %s\n", text2);
    
    strcpy(text2, "convert to uppercase");
    toUpperCase(text2);
    printf("Uppercase: %s\n", text2);
    printf("\n");
    
    // Number to words
    printSeparator('-', 40);
    printf("Number to Words\n");
    printSeparator('-', 40);
    
    printf("Digits 0-9 in words:\n");
    for (int i = 0; i <= 9; i++) {
        printf("%d: ", i);
        printNumberInWords(i);
        printf("\n");
    }
    printf("\n");
    
    // Validation utilities
    printSeparator('-', 40);
    printf("Validation Utilities\n");
    printSeparator('-', 40);
    
    int testValues[] = {5, 15, 25, 35, 45};
    int min = 10, max = 30;
    
    printf("Validating range [%d, %d]:\n", min, max);
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", testValues[i], 
               validateRange(testValues[i], min, max) ? "Valid" : "Invalid");
    }
    
    return 0;
}

// Function definitions

void printSeparator(char character, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", character);
    }
    printf("\n");
}

void printArray(int array[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int findMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMin(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

double calculateAverage(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

int countDigits(int number) {
    if (number == 0) return 1;
    
    int count = 0;
    number = abs(number); // Handle negative numbers
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

int reverseNumber(int number) {
    int reversed = 0;
    int isNegative = (number < 0);
    number = abs(number);
    
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    
    return isNegative ? -reversed : reversed;
}

int isPalindrome(int number) {
    return (number == reverseNumber(number));
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

int countWords(char str[]) {
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    
    return count;
}

void printNumberInWords(int digit) {
    switch (digit) {
        case 0: printf("Zero"); break;
        case 1: printf("One"); break;
        case 2: printf("Two"); break;
        case 3: printf("Three"); break;
        case 4: printf("Four"); break;
        case 5: printf("Five"); break;
        case 6: printf("Six"); break;
        case 7: printf("Seven"); break;
        case 8: printf("Eight"); break;
        case 9: printf("Nine"); break;
        default: printf("Invalid digit");
    }
}

int validateRange(int value, int min, int max) {
    return (value >= min && value <= max);
}