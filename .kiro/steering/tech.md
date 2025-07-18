# Technology Stack

## Language

- **C Language**: Primary focus language for all examples and projects
- Target C99/C11 standards for modern compatibility

## Build System

- **GCC**: Primary compiler for examples
- **Make**: Build automation for multi-file projects
- **CMake**: For more complex project structures (advanced topics)

## Development Environment

- Cross-platform compatibility (Linux, macOS, Windows)
- Standard POSIX libraries where applicable
- Minimal external dependencies to focus on core C concepts

## Common Commands

### Compilation

```bash
# Single file compilation
gcc -o program program.c

# With debugging symbols
gcc -g -o program program.c

# With warnings enabled
gcc -Wall -Wextra -o program program.c

# C99 standard compliance
gcc -std=c99 -o program program.c
```

### Building Projects

```bash
# Using Make
make
make clean

# Manual multi-file compilation
gcc -o program main.c utils.c helper.c
```

### Debugging

```bash
# GDB debugging
gdb ./program

# Valgrind for memory checking
valgrind --leak-check=full ./program
```

## Code Standards

- Follow K&R or Linux kernel style guidelines
- Emphasize readability for educational purposes
- Include comprehensive comments explaining low-level concepts
