# Project Structure

## Organization Principles

- **Basic to Advanced Progression**: Each lesson builds naturally on previous concepts
- **Realistic Examples**: Real-world scenarios that frontend developers encounter
- **Self-Contained Lessons**: Each example runs independently with clear learning objectives
- **Practical Application**: Examples solve actual problems, not just demonstrate syntax

## Recommended Folder Structure

```
/
├── basics/                 # Foundation concepts with real examples
│   ├── lesson-1-hello-world/      # Program structure & compilation
│   ├── lesson-2-variables/        # Memory layout & data types
│   ├── lesson-3-input-output/     # User interaction (like form handling)
│   ├── lesson-4-control-flow/     # Logic & decision making
│   └── lesson-5-functions/        # Code organization & modularity
├── intermediate/           # Building practical skills
│   ├── lesson-6-arrays/           # Data collections (like JS arrays)
│   ├── lesson-7-strings/          # Text processing & manipulation
│   ├── lesson-8-pointers/         # Memory addresses & references
│   ├── lesson-9-structs/          # Custom data types (like objects)
│   └── lesson-10-file-handling/   # Reading/writing files
├── advanced/              # Systems programming concepts
│   ├── lesson-11-memory-mgmt/     # Manual memory management
│   ├── lesson-12-linked-lists/    # Dynamic data structures
│   ├── lesson-13-function-ptrs/   # Callbacks & higher-order functions
│   ├── lesson-14-preprocessor/    # Macros & conditional compilation
│   └── lesson-15-system-calls/    # OS interaction & processes
├── projects/              # Real-world applications
│   ├── json-parser/              # Parse JSON (familiar to frontend devs)
│   ├── http-server/              # Simple web server
│   ├── text-processor/           # File manipulation tool
│   └── memory-allocator/         # Custom malloc implementation
└── resources/             # Supporting materials
    ├── cheat-sheets/
    ├── debugging-guide/
    └── performance-tips/
```

## File Naming Conventions

- Use lowercase with hyphens for directories
- C source files: `*.c`
- Header files: `*.h`
- Makefiles: `Makefile` or `makefile`
- Documentation: `README.md` in each directory

## Example Structure

Each learning module should contain:

- `main.c` - Primary example code
- `README.md` - Explanation and learning objectives
- `Makefile` - Build instructions (when applicable)
- `example_output.txt` - Expected program output

## Documentation Standards

- Each directory must have a README explaining the concept
- Code comments should explain the "why" not just the "what"
- Include memory diagrams for pointer/memory concepts
- Provide compilation and execution instructions
