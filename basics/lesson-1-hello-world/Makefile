# Makefile for Lesson 1: Hello World Examples
# 
# This makes it easy to compile all examples at once
# Usage: make all (or just 'make')

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# List of all programs to build
PROGRAMS = basic_hello detailed_hello multiple_outputs return_codes

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
basic_hello: basic_hello.c
	$(CC) $(CFLAGS) -o $@ $<

detailed_hello: detailed_hello.c
	$(CC) $(CFLAGS) -o $@ $<

multiple_outputs: multiple_outputs.c
	$(CC) $(CFLAGS) -o $@ $<

return_codes: return_codes.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples in sequence
run-all: all
	@echo "=== Running basic_hello ==="
	./basic_hello
	@echo "\n=== Running detailed_hello ==="
	./detailed_hello
	@echo "\n=== Running multiple_outputs ==="
	./multiple_outputs
	@echo "\n=== Running return_codes ==="
	./return_codes
	@echo "\nCheck the exit code with: echo $$?"

# Help target
help:
	@echo "Available targets:"
	@echo "  all        - Build all programs (default)"
	@echo "  clean      - Remove compiled programs"
	@echo "  run-all    - Build and run all examples"
	@echo "  help       - Show this help message"

.PHONY: all clean run-all help