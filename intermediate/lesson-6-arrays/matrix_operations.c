/*
 * Matrix Operations - 2D Arrays and Matrix Processing
 * 
 * This example demonstrates:
 * - 2D array declaration and initialization
 * - Matrix operations (addition, multiplication, transpose)
 * - Row and column processing
 * - Practical applications of multi-dimensional arrays
 * 
 * 2D arrays are essential for many applications including
 * image processing, game development, and scientific computing.
 */

#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function prototypes
void printMatrix(int matrix[][MAX_COLS], int rows, int cols);
void initializeMatrix(int matrix[][MAX_COLS], int rows, int cols, int value);
void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int result[][MAX_COLS], int rows, int cols);
void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int result[][MAX_COLS], int rowsA, int colsA, int colsB);
void transposeMatrix(int matrix[][MAX_COLS], int transposed[][MAX_COLS], int rows, int cols);
int findMatrixSum(int matrix[][MAX_COLS], int rows, int cols);
void findRowSums(int matrix[][MAX_COLS], int rows, int cols, int rowSums[]);
void findColSums(int matrix[][MAX_COLS], int rows, int cols, int colSums[]);
int findMaxInMatrix(int matrix[][MAX_COLS], int rows, int cols);
int findMinInMatrix(int matrix[][MAX_COLS], int rows, int cols);

int main() {
    printf("=== Matrix Operations (2D Arrays) ===\n\n");
    
    // 1. Matrix Declaration and Initialization
    printf("1. Matrix Declaration and Initialization:\n");
    
    // Different ways to initialize 2D arrays
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int matrix2[3][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {9, 8, 7, 6}
    };
    
    printf("Matrix 1 (3x4):\n");
    printMatrix(matrix1, 3, 4);
    
    printf("Matrix 2 (3x4):\n");
    printMatrix(matrix2, 3, 4);
    printf("\n");
    
    // 2. Matrix Addition
    printf("2. Matrix Addition:\n");
    int sum[3][MAX_COLS];
    addMatrices(matrix1, matrix2, sum, 3, 4);
    printf("Matrix1 + Matrix2:\n");
    printMatrix(sum, 3, 4);
    printf("\n");
    
    // 3. Matrix Multiplication
    printf("3. Matrix Multiplication:\n");
    
    // Create matrices suitable for multiplication
    int matA[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int matB[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    printf("Matrix A (2x3):\n");
    printMatrix(matA, 2, 3);
    
    printf("Matrix B (3x2):\n");
    printMatrix(matB, 3, 2);
    
    int product[2][MAX_COLS];
    multiplyMatrices(matA, matB, product, 2, 3, 2);
    printf("A × B (2x2):\n");
    printMatrix(product, 2, 2);
    printf("\n");
    
    // 4. Matrix Transpose
    printf("4. Matrix Transpose:\n");
    int original[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int transposed[4][MAX_COLS];
    
    printf("Original Matrix (3x4):\n");
    printMatrix(original, 3, 4);
    
    transposeMatrix(original, transposed, 3, 4);
    printf("Transposed Matrix (4x3):\n");
    printMatrix(transposed, 4, 3);
    printf("\n");
    
    // 5. Matrix Statistics
    printf("5. Matrix Statistics:\n");
    int dataMatrix[4][5] = {
        {12, 23, 34, 45, 56},
        {67, 78, 89, 90, 11},
        {22, 33, 44, 55, 66},
        {77, 88, 99, 10, 21}
    };
    
    printf("Data Matrix (4x5):\n");
    printMatrix(dataMatrix, 4, 5);
    
    int totalSum = findMatrixSum(dataMatrix, 4, 5);
    printf("Total sum: %d\n", totalSum);
    printf("Average: %.2f\n", (double)totalSum / (4 * 5));
    
    int maxVal = findMaxInMatrix(dataMatrix, 4, 5);
    int minVal = findMinInMatrix(dataMatrix, 4, 5);
    printf("Maximum: %d\n", maxVal);
    printf("Minimum: %d\n", minVal);
    printf("\n");
    
    // 6. Row and Column Sums
    printf("6. Row and Column Analysis:\n");
    
    int rowSums[4];
    int colSums[5];
    
    findRowSums(dataMatrix, 4, 5, rowSums);
    findColSums(dataMatrix, 4, 5, colSums);
    
    printf("Row sums: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", rowSums[i]);
    }
    printf("\n");
    
    printf("Column sums: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", colSums[i]);
    }
    printf("\n\n");
    
    // 7. Identity Matrix
    printf("7. Identity Matrix:\n");
    int identity[4][MAX_COLS];
    initializeMatrix(identity, 4, 4, 0);
    
    // Set diagonal elements to 1
    for (int i = 0; i < 4; i++) {
        identity[i][i] = 1;
    }
    
    printf("4x4 Identity Matrix:\n");
    printMatrix(identity, 4, 4);
    printf("\n");
    
    // 8. Game Board Example
    printf("8. Game Board Example (Tic-Tac-Toe):\n");
    char gameBoard[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'X', 'O'}
    };
    
    printf("Tic-Tac-Toe Board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", gameBoard[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    
    return 0;
}

// Function definitions

void printMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void initializeMatrix(int matrix[][MAX_COLS], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}

void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int result[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int result[][MAX_COLS], int rowsA, int colsA, int colsB) {
    // Initialize result matrix to zero
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX_COLS], int transposed[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int findMatrixSum(int matrix[][MAX_COLS], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void findRowSums(int matrix[][MAX_COLS], int rows, int cols, int rowSums[]) {
    for (int i = 0; i < rows; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

void findColSums(int matrix[][MAX_COLS], int rows, int cols, int colSums[]) {
    for (int j = 0; j < cols; j++) {
        colSums[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSums[j] += matrix[i][j];
        }
    }
}

int findMaxInMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int findMinInMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    int min = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}