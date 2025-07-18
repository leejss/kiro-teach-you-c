# Lesson 6: Arrays & Array Processing

## Learning Objectives

By the end of this lesson, you'll understand:

- Array declaration, initialization, and memory layout
- Array indexing and bounds checking
- Multi-dimensional arrays and their applications
- Array processing algorithms (searching, sorting, statistics)
- Arrays vs JavaScript arrays - fixed size vs dynamic

## Key Concepts for Frontend Developers

### JavaScript vs C: Arrays

**JavaScript (Dynamic Arrays):**

```javascript
let numbers = [1, 2, 3]; // Dynamic size
numbers.push(4); // Can grow
numbers.pop(); // Can shrink
numbers[10] = 100; // Sparse arrays allowed

// Built-in methods
numbers.map((x) => x * 2);
numbers.filter((x) => x > 5);
numbers.reduce((a, b) => a + b);
```

**C (Fixed Arrays):**

```c
int numbers[5] = {1, 2, 3, 4, 5};  // Fixed size at compile time
// numbers[5] = 6;                 // Buffer overflow - undefined behavior!

// Manual processing required
for (int i = 0; i < 5; i++) {
    numbers[i] *= 2;               // Manual map operation
}
```

**Key Differences:**

- C arrays have fixed size determined at compile time
- No bounds checking - accessing out-of-bounds is undefined behavior
- No built-in methods - you implement all operations manually
- Memory is contiguous and predictable
- Much faster access due to direct memory addressing

## Array Fundamentals

### Array Declaration and Initialization

```c
// Declaration with size
int numbers[10];                    // Uninitialized array

// Declaration with initialization
int scores[5] = {85, 92, 78, 96, 88};

// Size inferred from initializer
int values[] = {1, 2, 3, 4, 5};    // Size is 5

// Partial initialization (rest are zero)
int data[10] = {1, 2, 3};          // First 3 are 1,2,3, rest are 0
```

### Multi-dimensional Arrays

```c
// 2D array (matrix)
int matrix[3][4];                   // 3 rows, 4 columns

// 2D array with initialization
int grid[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Array Memory Layout

```
Single Array: [10][20][30][40][50]
Memory:       |10|20|30|40|50|
Addresses:    100 104 108 112 116  (assuming 4-byte integers)

2D Array: int arr[2][3]
Conceptual:   [1][2][3]
              [4][5][6]
Memory:       |1|2|3|4|5|6|  (row-major order)
```

## Examples

1. `array_basics.c` - Array declaration, initialization, and basic operations
2. `array_algorithms.c` - Searching and sorting algorithms
3. `matrix_operations.c` - 2D arrays and matrix processing
4. `array_statistics.c` - Statistical analysis of array data

## Real-World Applications

- **Data Processing**: Analyzing collections of numerical data
- **Image Processing**: 2D arrays represent pixel data
- **Game Development**: Game boards, collision detection grids
- **Scientific Computing**: Mathematical matrices and vectors

## Compilation & Execution

```bash
# Build all examples
make all

# Run individual examples
./array_basics
./array_algorithms
./matrix_operations
./array_statistics
```

## Next Steps

After mastering arrays, you'll learn about strings (which are character arrays in C) and string manipulation techniques.
