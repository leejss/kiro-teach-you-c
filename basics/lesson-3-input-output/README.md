# Lesson 3: Input & Output Operations

## Learning Objectives

By the end of this lesson, you'll understand:

- Standard input/output functions in C (scanf, printf, getchar)
- Format specifiers and their proper usage
- Input validation and error handling
- Building interactive C programs

## Key Concepts for Frontend Developers

### JavaScript vs C: Input/Output

**JavaScript (Browser/Node.js):**

```javascript
// Browser
let name = prompt("Enter your name:");
console.log(`Hello, ${name}!`);

// Node.js
const readline = require("readline");
// Complex async setup for input...
```

**C (Direct System I/O):**

```c
char name[50];
printf("Enter your name: ");
scanf("%s", name);
printf("Hello, %s!\n", name);
```

**Why This Matters:**

- C provides direct, synchronous I/O operations
- No event loops or async handling needed for basic I/O
- Format specifiers give precise control over data formatting
- Lower-level access to system input/output streams

## Essential I/O Functions

### Output Functions

```c
printf("Hello, World!\n");           // Formatted output
puts("Simple string output");        // String + newline
putchar('A');                       // Single character
```

### Input Functions

```c
scanf("%d", &number);               // Formatted input
gets(buffer);                       // String input (deprecated)
fgets(buffer, size, stdin);         // Safe string input
getchar();                          // Single character
```

### Format Specifiers

```c
printf("%d", 42);                   // Integer
printf("%f", 3.14);                 // Float
printf("%c", 'A');                  // Character
printf("%s", "Hello");              // String
printf("%x", 255);                  // Hexadecimal
printf("%.2f", 3.14159);           // 2 decimal places
```

## Input Validation in C

Unlike JavaScript's automatic type conversion, C requires explicit validation:

```c
int number;
if (scanf("%d", &number) != 1) {
    printf("Invalid input!\n");
    // Clear input buffer
    while (getchar() != '\n');
}
```

## Examples

1. `basic_io.c` - Fundamental input/output operations
2. `interactive_calculator.c` - Calculator with user input
3. `number_converter.c` - Convert between number bases
4. `input_validation.c` - Proper input validation techniques

## Real-World Applications

- **Command Line Tools**: Interactive utilities and system programs
- **Embedded Systems**: Direct hardware I/O without abstraction layers
- **System Programming**: Low-level I/O operations
- **Performance**: Direct system calls without runtime overhead

## Compilation & Execution

```bash
# Build all examples
make all

# Run interactive examples
./interactive_calculator
./number_converter
```

## Next Steps

After mastering I/O operations, you'll learn about control flow (if/else, loops) to build more complex interactive programs.
