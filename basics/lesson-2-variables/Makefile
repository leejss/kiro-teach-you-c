# Makefile for Lesson 2: Variables & Memory Layout
# 
# Build and run realistic examples demonstrating C variables

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# List of all programs to build
PROGRAMS = basic_variables calculator user_profile memory_sizes

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
basic_variables: basic_variables.c
	$(CC) $(CFLAGS) -o $@ $<

calculator: calculator.c
	$(CC) $(CFLAGS) -o $@ $<

user_profile: user_profile.c
	$(CC) $(CFLAGS) -o $@ $<

memory_sizes: memory_sizes.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples in sequence
run-all: all
	@echo "=== Running basic_variables ==="
	./basic_variables
	@echo "\n=== Running calculator ==="
	./calculator
	@echo "\n=== Running user_profile ==="
	./user_profile
	@echo "\n=== Running memory_sizes ==="
	./memory_sizes

# Run specific examples
run-calculator: calculator
	./calculator

run-profile: user_profile
	./user_profile

run-memory: memory_sizes
	./memory_sizes

# Help target
help:
	@echo "Available targets:"
	@echo "  all           - Build all programs (default)"
	@echo "  clean         - Remove compiled programs"
	@echo "  run-all       - Build and run all examples"
	@echo "  run-calculator - Run calculator example"
	@echo "  run-profile   - Run user profile example"
	@echo "  run-memory    - Run memory sizes example"
	@echo "  help          - Show this help message"

.PHONY: all clean run-all run-calculator run-profile run-memory help