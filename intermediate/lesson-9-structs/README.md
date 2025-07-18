# Lesson 9: Structures & Custom Data Types

## Learning Objectives

By the end of this lesson, you'll understand:

- Structure definition and member access
- Nested structures and structure arrays
- Structures with pointers and dynamic allocation
- typedef for creating custom data types
- Structure initialization and best practices

## Key Concepts for Frontend Developers

### JavaScript vs C: Object-like Data Structures

**JavaScript (Dynamic Objects):**

```javascript
// Dynamic object creation
let student = {
  name: "Alice Johnson",
  age: 20,
  gpa: 3.85,
  courses: ["Math", "Physics", "CS"],
};

// Dynamic property addition
student.email = "alice@university.edu";
student.graduationYear = 2025;

// Object methods
student.getInfo = function () {
  return `${this.name}, Age: ${this.age}`;
};
```

**C (Static Structures):**

```c
// Static structure definition
struct Student {
    char name[50];
    int age;
    double gpa;
    char courses[5][20];  // Fixed-size array
};

// Structure initialization
struct Student student = {
    .name = "Alice Johnson",
    .age = 20,
    .gpa = 3.85,
    .courses = {"Math", "Physics", "CS"}
};

// No dynamic property addition - structure is fixed
// Functions operate on structures, not embedded in them
```

**Key Differences:**

- C structures have fixed layout defined at compile time
- No dynamic property addition - all members must be declared
- Memory layout is predictable and efficient
- Functions are separate from data (no methods inside structs)
- Explicit memory management for dynamic structures
- Type safety enforced at compile time

## Structure Fundamentals

### Basic Structure Definition

```c
// Define a structure type
struct Point {
    double x;
    double y;
};

// Create structure variables
struct Point origin = {0.0, 0.0};
struct Point center = {10.5, 20.3};

// Access members using dot operator
printf("Origin: (%.1f, %.1f)\n", origin.x, origin.y);
center.x = 15.0;  // Modify member
```

### Structure Initialization Methods

```c
struct Rectangle {
    double width;
    double height;
    char color[20];
};

// Method 1: Designated initializers (C99)
struct Rectangle rect1 = {
    .width = 10.0,
    .height = 5.0,
    .color = "blue"
};

// Method 2: Positional initialization
struct Rectangle rect2 = {8.0, 6.0, "red"};

// Method 3: Partial initialization (rest set to zero)
struct Rectangle rect3 = {.width = 12.0};  // height = 0.0, color = ""
```

### Structures and Pointers

```c
struct Point point = {3.0, 4.0};
struct Point* ptr = &point;

// Two ways to access members through pointer
printf("X coordinate: %.1f\n", (*ptr).x);  // Dereference first
printf("Y coordinate: %.1f\n", ptr->y);    // Arrow operator (preferred)

// Modifying through pointer
ptr->x = 7.0;
ptr->y = 9.0;
```

## Advanced Structure Concepts

### Nested Structures

```c
struct Address {
    char street[100];
    char city[50];
    char state[20];
    int zip_code;
};

struct Person {
    char name[50];
    int age;
    struct Address home_address;    // Nested structure
    struct Address work_address;
};

// Accessing nested members
struct Person employee;
strcpy(employee.home_address.city, "San Francisco");
employee.home_address.zip_code = 94102;
```

### Structure Arrays

```c
struct Student class_roster[30];  // Array of 30 students

// Initialize array elements
for (int i = 0; i < 30; i++) {
    class_roster[i].age = 0;
    class_roster[i].gpa = 0.0;
    strcpy(class_roster[i].name, "");
}

// Access specific student
strcpy(class_roster[0].name, "John Doe");
class_roster[0].age = 19;
```

### typedef for Custom Types

```c
// Create type alias for cleaner code
typedef struct {
    double real;
    double imaginary;
} Complex;

// Now use Complex instead of struct Complex
Complex number1 = {3.0, 4.0};
Complex number2 = {1.0, -2.0};

// Function using typedef
Complex add_complex(Complex a, Complex b) {
    Complex result = {a.real + b.real, a.imaginary + b.imaginary};
    return result;
}
```

## Memory Layout and Alignment

### Structure Memory Layout

```c
struct Example {
    char c;      // 1 byte
    int i;       // 4 bytes (may have padding before)
    double d;    // 8 bytes (may have padding before)
};

// Memory might look like:
// [c][pad][pad][pad][i][i][i][i][d][d][d][d][d][d][d][d]
//  1   1   1   1   4   4   4   4   8   8   8   8   8   8   8   8

printf("Size of struct: %zu bytes\n", sizeof(struct Example));
```

## Examples

1. `struct_basics.c` - Structure definition, initialization, and member access
2. `nested_structures.c` - Complex data organization with nested structures
3. `struct_arrays_pointers.c` - Arrays of structures and pointer manipulation
4. `typedef_custom_types.c` - Creating custom data types and type aliases

## Real-World Applications

- **Data Records**: Student records, employee information, product catalogs
- **Geometric Objects**: Points, rectangles, circles for graphics programming
- **Network Protocols**: Packet headers, message structures
- **File Formats**: Binary file headers, configuration data
- **System Programming**: Process information, file metadata

## Common Patterns

### Structure Copying

```c
struct Point p1 = {1.0, 2.0};
struct Point p2 = p1;  // Entire structure copied (shallow copy)
```

### Structure Comparison

```c
// Structures cannot be compared directly
// if (p1 == p2)  // ERROR: Invalid operation

// Must compare member by member or use memcmp
int points_equal(struct Point a, struct Point b) {
    return (a.x == b.x) && (a.y == b.y);
}
```

### Structure Functions

```c
// Pass by value (copy entire structure)
double calculate_distance(struct Point p1, struct Point p2);

// Pass by reference (more efficient for large structures)
void print_point(const struct Point* p);
void move_point(struct Point* p, double dx, double dy);
```

## Best Practices

- Use `typedef` for cleaner type names
- Pass large structures by pointer to avoid copying
- Use `const` for read-only structure parameters
- Initialize all structure members to avoid garbage values
- Consider memory alignment for performance-critical code
- Use designated initializers for clarity

## Compilation & Execution

```bash
# Build all examples
make all

# Run all examples in sequence
make run

# Run individual examples
./struct_basics
./nested_structures
./struct_arrays_pointers
./typedef_custom_types

# Memory checking (if valgrind is available)
make memcheck
```

## Next Steps

After mastering structures, you'll learn about file input/output operations, where structures become essential for reading and writing complex data formats to files, preparing you for real-world data processing applications.
