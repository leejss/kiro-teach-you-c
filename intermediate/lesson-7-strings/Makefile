# Makefile for Lesson 7: Strings & String Manipulation
# 
# Build and run authentic C string programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# List of all programs to build
PROGRAMS = string_basics string_functions string_processing

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
string_basics: string_basics.c
	$(CC) $(CFLAGS) -o $@ $<

string_functions: string_functions.c
	$(CC) $(CFLAGS) -o $@ $<

string_processing: string_processing.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples (string_basics is interactive)
run-all: all
	@echo "Note: string_basics requires user input"
	@echo "Running non-interactive examples first:"
	@echo "\n=== Running String Functions ==="
	./string_functions
	@echo "\n=== Running String Processing ==="
	./string_processing
	@echo "\nTo run string_basics (interactive): make run-basics"

# Individual run targets
run-basics: string_basics
	@echo "Running string basics (interactive)..."
	./string_basics

run-functions: string_functions
	@echo "Running string functions..."
	./string_functions

run-processing: string_processing
	@echo "Running string processing..."
	./string_processing

# Demo target - runs non-interactive examples
demo: string_functions string_processing
	@echo "=== String Functions Demo ==="
	./string_functions
	@echo "\n=== String Processing Demo ==="
	./string_processing

# Quick test - focus on core concepts
quick-test: string_functions
	@echo "=== Quick String Functions Test ==="
	./string_functions

# Help target
help:
	@echo "Available targets:"
	@echo "  all            - Build all programs (default)"
	@echo "  clean          - Remove compiled programs"
	@echo "  run-all        - Run non-interactive examples"
	@echo "  run-basics     - Run string basics (interactive)"
	@echo "  run-functions  - Run string functions example"
	@echo "  run-processing - Run string processing example"
	@echo "  demo           - Run non-interactive demonstration"
	@echo "  quick-test     - Run quick string functions test"
	@echo "  help           - Show this help message"
	@echo ""
	@echo "Interactive: string_basics (requires user input)"
	@echo "Non-interactive: string_functions, string_processing"

.PHONY: all clean run-all run-basics run-functions run-processing demo quick-test help