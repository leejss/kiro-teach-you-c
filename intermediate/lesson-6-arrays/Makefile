# Makefile for Lesson 6: Arrays & Array Processing
# 
# Build and run authentic C array programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -lm

# List of all programs to build
PROGRAMS = array_basics array_algorithms matrix_operations

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
array_basics: array_basics.c
	$(CC) $(CFLAGS) -o $@ $<

array_algorithms: array_algorithms.c
	$(CC) $(CFLAGS) -o $@ $<

matrix_operations: matrix_operations.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples (all are non-interactive)
run-all: all
	@echo "=== Running Array Basics ==="
	./array_basics
	@echo "\n=== Running Array Algorithms ==="
	./array_algorithms
	@echo "\n=== Running Matrix Operations ==="
	./matrix_operations

# Individual run targets
run-basics: array_basics
	@echo "Running array basics..."
	./array_basics

run-algorithms: array_algorithms
	@echo "Running array algorithms..."
	./array_algorithms

run-matrix: matrix_operations
	@echo "Running matrix operations..."
	./matrix_operations

# Demo target - runs a quick demonstration
demo: array_basics array_algorithms
	@echo "=== Quick Demo: Array Basics ==="
	./array_basics
	@echo "\n=== Quick Demo: Sorting Algorithms ==="
	./array_algorithms

# Performance test - focus on algorithm performance
perf-test: array_algorithms
	@echo "=== Performance Test: Array Algorithms ==="
	./array_algorithms

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Build all programs (default)"
	@echo "  clean         - Remove compiled programs"
	@echo "  run-all       - Run all examples"
	@echo "  run-basics    - Run array basics example"
	@echo "  run-algorithms - Run array algorithms example"
	@echo "  run-matrix    - Run matrix operations example"
	@echo "  demo          - Run quick demonstration"
	@echo "  perf-test     - Run performance tests"
	@echo "  help          - Show this help message"
	@echo ""
	@echo "All programs are non-interactive and show output immediately"

.PHONY: all clean run-all run-basics run-algorithms run-matrix demo perf-test help