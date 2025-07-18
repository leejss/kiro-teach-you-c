/*
 * Array Algorithms - Searching and Sorting
 * 
 * This example demonstrates:
 * - Linear and binary search algorithms
 * - Bubble sort and selection sort
 * - Algorithm complexity and performance
 * - Practical array processing techniques
 * 
 * These are fundamental algorithms that every C programmer
 * should understand and implement.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function prototypes
void printArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void copyArray(int source[], int dest[], int size);
void generateRandomArray(int arr[], int size, int maxValue);
double measureSortTime(void (*sortFunc)(int[], int), int arr[], int size);

int main() {
    printf("=== Array Algorithms ===\n\n");
    
    // 1. Linear Search
    printf("1. Linear Search:\n");
    int searchArray[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int searchSize = sizeof(searchArray) / sizeof(searchArray[0]);
    
    printf("Array: ");
    printArray(searchArray, searchSize);
    
    int target = 22;
    int position = linearSearch(searchArray, searchSize, target);
    printf("Linear search for %d: ", target);
    if (position != -1) {
        printf("Found at index %d\n", position);
    } else {
        printf("Not found\n");
    }
    printf("\n");
    
    // 2. Binary Search (requires sorted array)
    printf("2. Binary Search:\n");
    int sortedArray[] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 78};
    int sortedSize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    
    printf("Sorted array: ");
    printArray(sortedArray, sortedSize);
    
    target = 23;
    position = binarySearch(sortedArray, sortedSize, target);
    printf("Binary search for %d: ", target);
    if (position != -1) {
        printf("Found at index %d\n", position);
    } else {
        printf("Not found\n");
    }
    printf("\n");
    
    // 3. Sorting Algorithms Demonstration
    printf("3. Sorting Algorithms:\n");
    
    int originalArray[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 33, 77};
    int arraySize = sizeof(originalArray) / sizeof(originalArray[0]);
    
    printf("Original array: ");
    printArray(originalArray, arraySize);
    printf("\n");
    
    // Bubble Sort
    int bubbleArray[12];
    copyArray(originalArray, bubbleArray, arraySize);
    printf("Bubble Sort:\n");
    printf("Before: ");
    printArray(bubbleArray, arraySize);
    bubbleSort(bubbleArray, arraySize);
    printf("After:  ");
    printArray(bubbleArray, arraySize);
    printf("\n");
    
    // Selection Sort
    int selectionArray[12];
    copyArray(originalArray, selectionArray, arraySize);
    printf("Selection Sort:\n");
    printf("Before: ");
    printArray(selectionArray, arraySize);
    selectionSort(selectionArray, arraySize);
    printf("After:  ");
    printArray(selectionArray, arraySize);
    printf("\n");
    
    // Insertion Sort
    int insertionArray[12];
    copyArray(originalArray, insertionArray, arraySize);
    printf("Insertion Sort:\n");
    printf("Before: ");
    printArray(insertionArray, arraySize);
    insertionSort(insertionArray, arraySize);
    printf("After:  ");
    printArray(insertionArray, arraySize);
    printf("\n");
    
    // 4. Performance Comparison
    printf("4. Performance Comparison (1000 random elements):\n");
    const int LARGE_SIZE = 1000;
    int largeArray[LARGE_SIZE];
    int testArray[LARGE_SIZE];
    
    // Generate random data
    generateRandomArray(largeArray, LARGE_SIZE, 1000);
    
    // Test Bubble Sort
    copyArray(largeArray, testArray, LARGE_SIZE);
    double bubbleTime = measureSortTime(bubbleSort, testArray, LARGE_SIZE);
    printf("Bubble Sort:    %.6f seconds\n", bubbleTime);
    
    // Test Selection Sort
    copyArray(largeArray, testArray, LARGE_SIZE);
    double selectionTime = measureSortTime(selectionSort, testArray, LARGE_SIZE);
    printf("Selection Sort: %.6f seconds\n", selectionTime);
    
    // Test Insertion Sort
    copyArray(largeArray, testArray, LARGE_SIZE);
    double insertionTime = measureSortTime(insertionSort, testArray, LARGE_SIZE);
    printf("Insertion Sort: %.6f seconds\n", insertionTime);
    printf("\n");
    
    // 5. Search Performance Comparison
    printf("5. Search Performance Comparison:\n");
    
    // Create a large sorted array for testing
    int searchTestArray[LARGE_SIZE];
    for (int i = 0; i < LARGE_SIZE; i++) {
        searchTestArray[i] = i * 2;  // Even numbers 0, 2, 4, 6, ...
    }
    
    target = 1500;  // Search for this value
    
    // Linear Search
    clock_t start = clock();
    position = linearSearch(searchTestArray, LARGE_SIZE, target);
    clock_t end = clock();
    double linearTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Binary Search
    start = clock();
    int binaryPos = binarySearch(searchTestArray, LARGE_SIZE, target);
    end = clock();
    double binaryTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Searching for %d in array of %d elements:\n", target, LARGE_SIZE);
    printf("Linear Search: %.8f seconds (found at index %d)\n", linearTime, position);
    printf("Binary Search: %.8f seconds (found at index %d)\n", binaryTime, binaryPos);
    
    if (linearTime > 0 && binaryTime > 0) {
        printf("Binary search is %.1fx faster\n", linearTime / binaryTime);
    }
    
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

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in remaining array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap minimum element with first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void generateRandomArray(int arr[], int size, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxValue;
    }
}

double measureSortTime(void (*sortFunc)(int[], int), int arr[], int size) {
    clock_t start = clock();
    sortFunc(arr, size);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}