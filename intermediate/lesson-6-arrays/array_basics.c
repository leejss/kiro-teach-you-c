/*
 * Array Basics - Fundamental Array Operations in C
 * 
 * This example demonstrates:
 * - Array declaration and initialization
 * - Array indexing and iteration
 * - Array size calculation
 * - Basic array operations
 * 
 * Arrays are fundamental data structures in C programming
 * and form the basis for more complex data manipulation.
 */

#include <stdio.h>

// Function prototypes
void printArray(int arr[], int size);
void fillArray(int arr[], int size, int value);
void copyArray(int source[], int dest[], int size);
int findElement(int arr[], int size, int target);
void reverseArray(int arr[], int size);

int main() {
    printf("=== Array Basics in C ===\n\n");
    
    // 1. Array declaration and initialization
    printf("1. Array Declaration and Initialization:\n");
    
    // Different ways to initialize arrays
    int numbers1[5] = {10, 20, 30, 40, 50};
    int numbers2[] = {1, 2, 3, 4, 5, 6};  // Size inferred
    int numbers3[8] = {1, 2, 3};          // Partial init, rest are 0
    int numbers4[5];                      // Uninitialized
    
    printf("numbers1: ");
    printArray(numbers1, 5);
    
    printf("numbers2: ");
    printArray(numbers2, 6);
    
    printf("numbers3 (partial init): ");
    printArray(numbers3, 8);
    
    // Initialize uninitialized array
    fillArray(numbers4, 5, 99);
    printf("numbers4 (filled with 99): ");
    printArray(numbers4, 5);
    printf("\n");
    
    // 2. Array size calculation
    printf("2. Array Size Calculation:\n");
    int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);
    printf("Array size: %d elements\n", arraySize);
    printf("Total bytes: %zu\n", sizeof(testArray));
    printf("Bytes per element: %zu\n", sizeof(testArray[0]));
    printf("\n");
    
    // 3. Array indexing and bounds
    printf("3. Array Indexing:\n");
    int scores[5] = {85, 92, 78, 96, 88};
    
    printf("Individual elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("scores[%d] = %d\n", i, scores[i]);
    }
    
    // Modify elements
    scores[0] = 90;  // Change first element
    scores[4] = 95;  // Change last element
    printf("After modification: ");
    printArray(scores, 5);
    printf("\n");
    
    // 4. Array processing patterns
    printf("4. Array Processing Patterns:\n");
    
    int data[] = {5, 12, 8, 23, 7, 15, 9, 18, 3, 11};
    int dataSize = sizeof(data) / sizeof(data[0]);
    
    printf("Original array: ");
    printArray(data, dataSize);
    
    // Find sum and average
    int sum = 0;
    for (int i = 0; i < dataSize; i++) {
        sum += data[i];
    }
    double average = (double)sum / dataSize;
    printf("Sum: %d, Average: %.2f\n", sum, average);
    
    // Find min and max
    int min = data[0], max = data[0];
    for (int i = 1; i < dataSize; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }
    printf("Min: %d, Max: %d\n", min, max);
    printf("\n");
    
    // 5. Array copying
    printf("5. Array Copying:\n");
    int original[] = {1, 4, 7, 2, 9, 5};
    int copy[6];
    
    copyArray(original, copy, 6);
    printf("Original: ");
    printArray(original, 6);
    printf("Copy: ");
    printArray(copy, 6);
    printf("\n");
    
    // 6. Searching in arrays
    printf("6. Array Searching:\n");
    int searchArray[] = {10, 25, 30, 45, 50, 65, 70, 85};
    int searchSize = sizeof(searchArray) / sizeof(searchArray[0]);
    
    printf("Search array: ");
    printArray(searchArray, searchSize);
    
    int target = 45;
    int position = findElement(searchArray, searchSize, target);
    if (position != -1) {
        printf("Found %d at index %d\n", target, position);
    } else {
        printf("%d not found in array\n", target);
    }
    
    target = 99;
    position = findElement(searchArray, searchSize, target);
    if (position != -1) {
        printf("Found %d at index %d\n", target, position);
    } else {
        printf("%d not found in array\n", target);
    }
    printf("\n");
    
    // 7. Array reversal
    printf("7. Array Reversal:\n");
    int reverseTest[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int reverseSize = sizeof(reverseTest) / sizeof(reverseTest[0]);
    
    printf("Before reversal: ");
    printArray(reverseTest, reverseSize);
    
    reverseArray(reverseTest, reverseSize);
    printf("After reversal: ");
    printArray(reverseTest, reverseSize);
    
    return 0;
}

// Function definitions

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index where found
        }
    }
    return -1;  // Not found
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // Swap elements from both ends
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}