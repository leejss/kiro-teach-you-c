# Lesson 2: Variables & Data Types

## Learning Objectives

By the end of this lesson, you'll understand:

- C's static type system and how it differs from JavaScript's dynamic typing
- Fundamental data types and their memory requirements
- Variable declaration, initialization, and scope rules
- Type conversion and casting in C

## Key Concepts for Frontend Developers

### JavaScript vs C: Type Systems

**JavaScript (Dynamic Typing):**

```javascript
let value = 42; // Runtime determines this is a number
value = "hello"; // Type can change at runtime
value = true; // JavaScript handles type conversion automatically
```

**C (Static Typing):**

```c
int value = 42;        // Type declared at compile time
// value = "hello";    // Compile error - type cannot change
char* text = "hello";  // Different variable for different type
```

**Why This Matters:**

- C catches type errors at compile time (before your program runs)
- Memory usage is predictable and efficient
- No runtime type checking overhead

## C Data Types Explained

### Integer Types

```c
char c = 'A';          // 1 byte  - characters and small integers
short s = 1000;        // 2 bytes - small numbers
int i = 100000;        // 4 bytes - standard integers
long l = 1000000000L;  // 8 bytes - large numbers
```

### Floating Point Types

```c
float f = 3.14f;       // 4 bytes - single precision
double d = 3.14159265; // 8 bytes - double precision
```

### Memory Layout Visualization

```
Memory Layout (Stack):
┌─────────────────┐ ← Higher addresses
│ double d (8)    │
├─────────────────┤
│ float f (4)     │
├─────────────────┤
│ long l (8)      │
├─────────────────┤
│ int i (4)       │
├─────────────────┤
│ short s (2)     │
├─────────────────┤
│ char c (1)      │
└─────────────────┘ ← Lower addresses
```

## Examples

1. `basic_variables.c` - Variable declaration and basic operations
2. `calculator.c` - Simple arithmetic calculator
3. `memory_sizes.c` - Exploring data type sizes
4. `user_profile.c` - Working with different data types together

## Real-World Applications

- **System Programming**: Understanding exact memory usage
- **Performance**: Choosing appropriate data types for efficiency
- **Embedded Systems**: Memory-constrained environments
- **Game Development**: Fast arithmetic operations

## Compilation & Execution

```bash
# Build all examples
make all

# Run individual examples
./calculator
./memory_sizes
```

## Next Steps

After understanding variables and types, you'll learn about input/output operations to create interactive C programs.
