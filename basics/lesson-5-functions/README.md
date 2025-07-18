# Lesson 5: Functions & Scope

## Learning Objectives

By the end of this lesson, you'll understand:

- Function definition, declaration, and calling
- Parameter passing and return values
- Variable scope (local, global, function parameters)
- Function prototypes and header organization
- Recursive functions and their applications

## Key Concepts for Frontend Developers

### JavaScript vs C: Functions

**JavaScript (Dynamic & Flexible):**

```javascript
function calculateArea(radius) {
  return Math.PI * radius * radius;
}

const area = calculateArea(5);

// Arrow functions
const square = (x) => x * x;

// Functions are first-class objects
const operations = [add, subtract, multiply];
```

**C (Static & Explicit):**

```c
// Function prototype (declaration)
double calculateArea(double radius);

// Function definition
double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    double area = calculateArea(5.0);
    return 0;
}
```

**Key Differences:**

- C requires explicit type declarations for parameters and return values
- Function prototypes must be declared before use
- No function hoisting like JavaScript
- Pass-by-value semantics (copies of values, not references)

## Function Components

### Function Declaration (Prototype)

```c
return_type function_name(parameter_type parameter_name);

// Examples
int add(int a, int b);
double calculateCircleArea(double radius);
void printMessage(char* message);
```

### Function Definition

```c
return_type function_name(parameter_type parameter_name) {
    // function body
    return value; // if return_type is not void
}
```

### Function Call

```c
result = function_name(argument1, argument2);
```

## Variable Scope in C

### Local Variables

```c
void function() {
    int local_var = 10;  // Only accessible within this function
}
```

### Global Variables

```c
int global_var = 100;    // Accessible from any function

void function() {
    global_var = 200;    // Can modify global variables
}
```

### Function Parameters

```c
void function(int parameter) {
    parameter = 50;      // Changes local copy, not original
}
```

## Examples

1. `math_library.c` - Mathematical utility functions
2. `utility_functions.c` - Common programming utilities
3. `recursive_functions.c` - Recursion examples and patterns
4. `scope_demonstration.c` - Variable scope and lifetime

## Real-World Applications

- **Code Organization**: Breaking large programs into manageable functions
- **Reusability**: Creating utility libraries for common operations
- **Modularity**: Separating concerns and responsibilities
- **Testing**: Isolating functionality for easier debugging

## Compilation & Execution

```bash
# Build all examples
make all

# Run individual examples
./math_library
./utility_functions
./recursive_functions
./scope_demonstration
```

## Next Steps

After mastering functions and scope, you'll move to Phase 2 (Intermediate) starting with arrays, which will build on your function knowledge to process collections of data.
