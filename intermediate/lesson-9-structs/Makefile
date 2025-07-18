# Makefile for Lesson 9: Structures & Custom Data Types
# Demonstrates structure concepts for C programming

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -lm
TARGET_DIR = .

# Source files
SOURCES = struct_basics.c nested_structures.c struct_arrays_pointers.c typedef_custom_types.c

# Executable targets
TARGETS = struct_basics nested_structures struct_arrays_pointers typedef_custom_types

# Default target
all: $(TARGETS)

# Individual targets
struct_basics: struct_basics.c
	$(CC) $(CFLAGS) -o $@ $<

nested_structures: nested_structures.c
	$(CC) $(CFLAGS) -o $@ $<

struct_arrays_pointers: struct_arrays_pointers.c
	$(CC) $(CFLAGS) -o $@ $<

typedef_custom_types: typedef_custom_types.c
	$(CC) $(CFLAGS) -o $@ $<

# Run all examples
run: all
	@echo "=== Running Structure Basics ==="
	./struct_basics
	@echo ""
	@echo "=== Running Nested Structures ==="
	./nested_structures
	@echo ""
	@echo "=== Running Structure Arrays and Pointers ==="
	./struct_arrays_pointers
	@echo ""
	@echo "=== Running Typedef and Custom Types ==="
	./typedef_custom_types

# Run individual examples
run-basics: struct_basics
	./struct_basics

run-nested: nested_structures
	./nested_structures

run-arrays: struct_arrays_pointers
	./struct_arrays_pointers

run-typedef: typedef_custom_types
	./typedef_custom_types

# Debug builds
debug: CFLAGS += -DDEBUG -O0
debug: all

# Clean up
clean:
	rm -f $(TARGETS)
	rm -rf *.dSYM

# Memory check with valgrind (if available)
memcheck: all
	@echo "Running memory checks..."
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "=== Memory check: struct_basics ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./struct_basics; \
		echo "=== Memory check: nested_structures ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./nested_structures; \
		echo "=== Memory check: struct_arrays_pointers ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./struct_arrays_pointers; \
		echo "=== Memory check: typedef_custom_types ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./typedef_custom_types; \
	else \
		echo "Valgrind not available. Install valgrind for memory checking."; \
	fi

# Static analysis (if available)
analyze: $(SOURCES)
	@if command -v cppcheck >/dev/null 2>&1; then \
		echo "Running static analysis..."; \
		cppcheck --enable=all --std=c99 $(SOURCES); \
	else \
		echo "cppcheck not available. Install cppcheck for static analysis."; \
	fi

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Build all examples"
	@echo "  run              - Build and run all examples"
	@echo "  run-basics       - Run structure basics example"
	@echo "  run-nested       - Run nested structures example"
	@echo "  run-arrays       - Run structure arrays and pointers example"
	@echo "  run-typedef      - Run typedef and custom types example"
	@echo "  debug            - Build with debug symbols"
	@echo "  memcheck         - Run memory leak detection (requires valgrind)"
	@echo "  analyze          - Run static code analysis (requires cppcheck)"
	@echo "  clean            - Remove compiled files"
	@echo "  help             - Show this help message"

.PHONY: all run run-basics run-nested run-arrays run-typedef debug clean memcheck analyze help