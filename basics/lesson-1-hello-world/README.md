# Lesson 1: Hello World & Program Structure

## Learning Objectives

By the end of this lesson, you'll understand:

- How C programs are structured differently from JavaScript
- The compilation process (source code → machine code)
- Basic C syntax and the `main()` function
- How memory and execution work at a low level

## Key Concepts for Frontend Developers

### JavaScript vs C: The Fundamental Difference

**JavaScript (Interpreted):**

```javascript
console.log("Hello, World!"); // Executed line by line by V8 engine
```

**C (Compiled):**

```c
#include <stdio.h>              // Preprocessor directive
int main() {                    // Entry point function
    printf("Hello, World!\n");  // Function call
    return 0;                   // Exit status
}
```

### Why This Matters

- **JavaScript**: Code is parsed and executed at runtime by an engine
- **C**: Code is compiled into machine instructions before execution
- **Performance**: C runs directly on CPU, no interpretation overhead
- **Memory**: You control memory allocation (no garbage collector)

## Program Structure Breakdown

### 1. Preprocessor Directives

```c
#include <stdio.h>  // Include standard input/output library
```

Think of this like `import` in JavaScript, but it literally copies code into your file before compilation.

### 2. The main() Function

```c
int main() {
    // Your code here
    return 0;  // Success status
}
```

This is your program's entry point - like the top level of a JavaScript file, but explicit.

### 3. Function Calls

```c
printf("Hello, World!\n");
```

Similar to `console.log()`, but `printf` is a C library function that writes to stdout.

## Examples

Run each example to see the concepts in action:

1. `basic_hello.c` - Minimal hello world
2. `detailed_hello.c` - With comments explaining each part
3. `multiple_outputs.c` - Multiple print statements
4. `return_codes.c` - Understanding program exit codes

## Compilation & Execution

```bash
# Compile a single file
gcc -o hello basic_hello.c

# Run the program
./hello

# Compile with debugging info and warnings
gcc -g -Wall -o hello basic_hello.c
```

## Next Steps

After completing this lesson, you'll move on to variables and data types, where you'll learn how C manages memory differently from JavaScript's automatic memory management.
