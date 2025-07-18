# Lesson 4: Control Flow

## Learning Objectives

By the end of this lesson, you'll understand:

- Conditional statements (if/else, switch) for decision making
- Loop structures (while, for, do-while) for repetition
- Logical operators and boolean expressions
- Control flow patterns in C programming

## Key Concepts for Frontend Developers

### JavaScript vs C: Control Structures

**JavaScript (Dynamic & Flexible):**

```javascript
if (score >= 90) {
  grade = "A";
} else if (score >= 80) {
  grade = "B";
}

for (let i = 0; i < 10; i++) {
  console.log(i);
}
```

**C (Static & Explicit):**

```c
if (score >= 90) {
    grade = 'A';
} else if (score >= 80) {
    grade = 'B';
}

for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

**Key Differences:**

- C requires explicit variable declarations in loop initialization
- Boolean expressions evaluate to integers (0 = false, non-zero = true)
- No automatic type conversion in conditions
- Switch statements require explicit break statements

## Control Flow Structures

### Conditional Statements

```c
// if-else statement
if (condition) {
    // code block
} else if (another_condition) {
    // code block
} else {
    // default code block
}

// switch statement
switch (variable) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // default code
}
```

### Loop Structures

```c
// while loop
while (condition) {
    // code block
}

// for loop
for (initialization; condition; increment) {
    // code block
}

// do-while loop
do {
    // code block
} while (condition);
```

### Logical Operators

```c
&&  // AND
||  // OR
!   // NOT
==  // Equal to
!=  // Not equal to
<   // Less than
<=  // Less than or equal
>   // Greater than
>=  // Greater than or equal
```

## Examples

1. `grade_calculator.c` - Grade assignment using if/else chains
2. `number_guessing_game.c` - Interactive game with loops and conditions
3. `menu_system.c` - Switch-based menu navigation
4. `loop_patterns.c` - Different loop types and patterns

## Real-World Applications

- **Decision Making**: Program logic and branching
- **Data Processing**: Iterating through collections
- **User Interfaces**: Menu systems and input validation
- **Algorithms**: Search, sort, and mathematical computations

## Compilation & Execution

```bash
# Build all examples
make all

# Run interactive examples
./grade_calculator
./number_guessing_game
./menu_system
```

## Next Steps

After mastering control flow, you'll learn about functions to organize code into reusable modules and understand variable scope.
