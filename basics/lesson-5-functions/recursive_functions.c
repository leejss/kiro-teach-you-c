/*
 * Recursive Functions - Recursion Patterns and Applications
 * 
 * This example demonstrates:
 * - Basic recursion concepts
 * - Mathematical recursion (factorial, fibonacci)
 * - String and array recursion
 * - Recursive problem-solving patterns
 * 
 * Recursion is a fundamental programming concept that's
 * essential for many algorithms and data structures.
 */

#include <stdio.h>
#include <string.h>

// Function prototypes
int factorialRecursive(int n);
int fibonacciRecursive(int n);
int powerRecursive(int base, int exponent);
int gcdRecursive(int a, int b);
int sumArrayRecursive(int array[], int size);
int findMaxRecursive(int array[], int size);
void printNumbersRecursive(int n);
void printReverseRecursive(int n);
int isPalindromeRecursive(char str[], int start, int end);
void towerOfHanoi(int n, char from, char to, char aux);
int binarySearchRecursive(int array[], int left, int right, int target);

int main() {
    printf("=== Recursive Functions Demonstration ===\n\n");
    
    // Mathematical recursion
    printf("Mathematical Recursion:\n");
    printf("Factorial of 6: %d\n", factorialRecursive(6));
    printf("Fibonacci of 8: %d\n", fibonacciRecursive(8));
    printf("Power 2^10: %d\n", powerRecursive(2, 10));
    printf("GCD of 48 and 18: %d\n", gcdRecursive(48, 18));
    printf("\n");
    
    // Array recursion
    printf("Array Recursion:\n");
    int numbers[] = {5, 12, 8, 23, 7, 15, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Sum: %d\n", sumArrayRecursive(numbers, size));
    printf("Maximum: %d\n", findMaxRecursive(numbers, size));
    printf("\n");
    
    // Number printing recursion
    printf("Number Printing Recursion:\n");
    printf("Numbers 1 to 5: ");
    printNumbersRecursive(5);
    printf("\n");
    
    printf("Numbers 5 to 1: ");
    printReverseRecursive(5);
    printf("\n\n");
    
    // String palindrome check
    printf("Palindrome Check (Recursive):\n");
    char word1[] = "racecar";
    char word2[] = "hello";
    
    printf("'%s': %s\n", word1, 
           isPalindromeRecursive(word1, 0, strlen(word1) - 1) ? "Palindrome" : "Not palindrome");
    printf("'%s': %s\n", word2, 
           isPalindromeRecursive(word2, 0, strlen(word2) - 1) ? "Palindrome" : "Not palindrome");
    printf("\n");
    
    // Tower of Hanoi
    printf("Tower of Hanoi (3 disks):\n");
    towerOfHanoi(3, 'A', 'C', 'B');
    printf("\n");
    
    // Binary search
    printf("Binary Search (Recursive):\n");
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 78};
    int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int target = 23;
    
    printf("Sorted array: [");
    for (int i = 0; i < arraySize; i++) {
        printf("%d", sortedArray[i]);
        if (i < arraySize - 1) printf(", ");
    }
    printf("]\n");
    
    int result = binarySearchRecursive(sortedArray, 0, arraySize - 1, target);
    if (result != -1) {
        printf("Found %d at index %d\n", target, result);
    } else {
        printf("%d not found in array\n", target);
    }
    
    return 0;
}

// Function definitions

int factorialRecursive(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorialRecursive(n - 1);
}

int fibonacciRecursive(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int powerRecursive(int base, int exponent) {
    // Base case
    if (exponent == 0) {
        return 1;
    }
    // Recursive case
    return base * powerRecursive(base, exponent - 1);
}

int gcdRecursive(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    // Recursive case
    return gcdRecursive(b, a % b);
}

int sumArrayRecursive(int array[], int size) {
    // Base case
    if (size <= 0) {
        return 0;
    }
    // Recursive case
    return array[size - 1] + sumArrayRecursive(array, size - 1);
}

int findMaxRecursive(int array[], int size) {
    // Base case
    if (size == 1) {
        return array[0];
    }
    
    // Recursive case
    int maxOfRest = findMaxRecursive(array, size - 1);
    return (array[size - 1] > maxOfRest) ? array[size - 1] : maxOfRest;
}

void printNumbersRecursive(int n) {
    // Base case
    if (n <= 0) {
        return;
    }
    
    // Recursive case - print smaller numbers first
    printNumbersRecursive(n - 1);
    printf("%d ", n);
}

void printReverseRecursive(int n) {
    // Base case
    if (n <= 0) {
        return;
    }
    
    // Print current number first, then recurse
    printf("%d ", n);
    printReverseRecursive(n - 1);
}

int isPalindromeRecursive(char str[], int start, int end) {
    // Base case - single character or empty string
    if (start >= end) {
        return 1;
    }
    
    // Check if characters match
    if (str[start] != str[end]) {
        return 0;
    }
    
    // Recursive case - check inner substring
    return isPalindromeRecursive(str, start + 1, end - 1);
}

void towerOfHanoi(int n, char from, char to, char aux) {
    // Base case
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, from, aux, to);
    
    // Move the largest disk from source to destination
    printf("Move disk %d from %c to %c\n", n, from, to);
    
    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}

int binarySearchRecursive(int array[], int left, int right, int target) {
    // Base case - element not found
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    // Base case - element found
    if (array[mid] == target) {
        return mid;
    }
    
    // Recursive cases
    if (target < array[mid]) {
        return binarySearchRecursive(array, left, mid - 1, target);
    } else {
        return binarySearchRecursive(array, mid + 1, right, target);
    }
}