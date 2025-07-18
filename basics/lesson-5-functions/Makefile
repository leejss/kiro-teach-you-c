# Makefile for Lesson 5: Functions & Scope
# 
# Build and run authentic C function programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -lm

# List of all programs to build
PROGRAMS = math_library utility_functions recursive_functions scope_demonstration

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
math_library: math_library.c
	$(CC) $(CFLAGS) -o $@ $<

utility_functions: utility_functions.c
	$(CC) $(CFLAGS) -o $@ $<

recursive_functions: recursive_functions.c
	$(CC) $(CFLAGS) -o $@ $<

scope_demonstration: scope_demonstration.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples (all are non-interactive)
run-all: all
	@echo "=== Running Math Library ==="
	./math_library
	@echo "\n=== Running Utility Functions ==="
	./utility_functions
	@echo "\n=== Running Recursive Functions ==="
	./recursive_functions
	@echo "\n=== Running Scope Demonstration ==="
	./scope_demonstration

# Individual run targets
run-math: math_library
	@echo "Running math library..."
	./math_library

run-utils: utility_functions
	@echo "Running utility functions..."
	./utility_functions

run-recursive: recursive_functions
	@echo "Running recursive functions..."
	./recursive_functions

run-scope: scope_demonstration
	@echo "Running scope demonstration..."
	./scope_demonstration

# Demo target - runs a quick demonstration
demo: math_library recursive_functions
	@echo "=== Quick Demo: Math Library ==="
	./math_library
	@echo "\n=== Quick Demo: Recursion ==="
	./recursive_functions

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Build all programs (default)"
	@echo "  clean         - Remove compiled programs"
	@echo "  run-all       - Run all examples"
	@echo "  run-math      - Run math library example"
	@echo "  run-utils     - Run utility functions example"
	@echo "  run-recursive - Run recursive functions example"
	@echo "  run-scope     - Run scope demonstration"
	@echo "  demo          - Run quick demonstration"
	@echo "  help          - Show this help message"
	@echo ""
	@echo "All programs are non-interactive and show output immediately"

.PHONY: all clean run-all run-math run-utils run-recursive run-scope demo help