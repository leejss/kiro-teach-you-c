# Makefile for Lesson 10: File Input/Output Operations
# Demonstrates file handling concepts for C programming

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET_DIR = .

# Source files
SOURCES = file_basics.c binary_file_operations.c file_processing.c

# Executable targets
TARGETS = file_basics binary_file_operations file_processing

# Default target
all: $(TARGETS)

# Individual targets
file_basics: file_basics.c
	$(CC) $(CFLAGS) -o $@ $<

binary_file_operations: binary_file_operations.c
	$(CC) $(CFLAGS) -o $@ $<

file_processing: file_processing.c
	$(CC) $(CFLAGS) -o $@ $<

# Create test files for examples
test-files:
	@echo "Creating test files for examples..."
	@echo "This is a test file for file operations." > test_input.txt
	@echo "Line 1: Hello World" >> test_input.txt
	@echo "Line 2: File I/O in C" >> test_input.txt
	@echo "Line 3: Implementation details matter" >> test_input.txt
	@echo "Test files created"

# Run all examples
run: all test-files
	@echo "=== Running File Basics ==="
	./file_basics
	@echo ""
	@echo "=== Running Binary File Operations ==="
	./binary_file_operations
	@echo ""
	@echo "=== Running File Processing ==="
	./file_processing

# Run individual examples
run-basics: file_basics test-files
	./file_basics

run-binary: binary_file_operations
	./binary_file_operations

run-processing: file_processing
	./file_processing

# Debug builds
debug: CFLAGS += -DDEBUG -O0
debug: all

# Performance optimized builds
optimize: CFLAGS += -O3 -DNDEBUG
optimize: all

# Clean up
clean:
	rm -f $(TARGETS)
	rm -rf *.dSYM
	rm -f *.txt *.bin *.dat *.csv *.log *.conf

# Clean only executables (keep test files)
clean-exe:
	rm -f $(TARGETS)
	rm -rf *.dSYM

# Memory check with valgrind (if available)
memcheck: all
	@echo "Running memory checks..."
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "=== Memory check: file_basics ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./file_basics; \
		echo "=== Memory check: binary_file_operations ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./binary_file_operations; \
		echo "=== Memory check: file_processing ==="; \
		valgrind --leak-check=full --show-leak-kinds=all ./file_processing; \
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

# Performance testing
perf-test: optimize
	@echo "Running performance tests..."
	@echo "Creating large test file (1MB)..."
	@dd if=/dev/zero of=large_test.txt bs=1024 count=1024 2>/dev/null
	@echo "Testing file operations performance..."
	@time ./file_basics > /dev/null
	@time ./binary_file_operations > /dev/null
	@rm -f large_test.txt

# Show file system usage
disk-usage:
	@echo "Disk usage of generated files:"
	@ls -lh *.txt *.bin *.dat *.csv *.log *.conf 2>/dev/null || echo "No files found"

# Help target
help:
	@echo "Available targets:"
	@echo "  all              - Build all examples"
	@echo "  run              - Build and run all examples"
	@echo "  run-basics       - Run file basics example"
	@echo "  run-binary       - Run binary file operations example"
	@echo "  run-processing   - Run file processing example"
	@echo "  test-files       - Create test files for examples"
	@echo "  debug            - Build with debug symbols"
	@echo "  optimize         - Build with optimizations"
	@echo "  memcheck         - Run memory leak detection (requires valgrind)"
	@echo "  analyze          - Run static code analysis (requires cppcheck)"
	@echo "  perf-test        - Run performance tests"
	@echo "  disk-usage       - Show disk usage of generated files"
	@echo "  clean            - Remove compiled files and test files"
	@echo "  clean-exe        - Remove only executables (keep test files)"
	@echo "  help             - Show this help message"

.PHONY: all run run-basics run-binary run-processing test-files debug optimize clean clean-exe memcheck analyze perf-test disk-usage help