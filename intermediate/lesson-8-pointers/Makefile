# Makefile for Lesson 8: Pointers & Memory Addresses
# Demonstrates pointer concepts for C programming

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET_DIR = .

# Source files
SOURCES = pointer_basics.c pointer_arithmetic.c pointers_and_functions.c

# Executable targets
TARGETS = pointer_basics pointer_arithmetic pointers_and_functions

# Default target
all: $(TARGETS)

# Individual targets
pointer_basics: pointer_basics.c
	$(CC) $(CFLAGS) -o $@ $<

pointer_arithmetic: pointer_arithmetic.c
	$(CC) $(CFLAGS) -o $@ $<

pointers_and_functions: pointers_and_functions.c
	$(CC) $(CFLAGS) -o $@ $<

# Run all examples
run: all
	@echo "=== Running Pointer Basics ==="
	./pointer_basics
	@echo ""
	@echo "=== Running Pointer Arithmetic ==="
	./pointer_arithmetic
	@echo ""
	@echo "=== Running Pointers and Functions ==="
	./pointers_and_functions

# Run individual examples
run-basics: pointer_basics
	./pointer_basics

run-arithmetic: pointer_arithmetic
	./pointer_arithmetic

run-functions: pointers_and_functions
	./pointers_and_functions

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
		echo "=== Memory check: pointer_basics ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./pointer_basics; \
		echo "=== Memory check: pointer_arithmetic ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./pointer_arithmetic; \
		echo "=== Memory check: pointers_and_functions ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./pointers_and_functions; \
	else \
		echo "Valgrind not available. Install valgrind for memory checking."; \
	fi

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Build all examples"
	@echo "  run              - Build and run all examples"
	@echo "  run-basics       - Run pointer basics example"
	@echo "  run-arithmetic   - Run pointer arithmetic example"
	@echo "  run-functions    - Run pointers and functions example"
	@echo "  debug            - Build with debug symbols"
	@echo "  memcheck         - Run memory leak detection (requires valgrind)"
	@echo "  clean            - Remove compiled files"
	@echo "  help             - Show this help message"

.PHONY: all run run-basics run-arithmetic run-functions debug clean memcheck help