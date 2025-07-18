# Makefile for Lesson 3: Input & Output Operations
# 
# Build and run authentic C I/O programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# List of all programs to build
PROGRAMS = basic_io interactive_calculator number_converter input_validation

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
basic_io: basic_io.c
	$(CC) $(CFLAGS) -o $@ $<

interactive_calculator: interactive_calculator.c
	$(CC) $(CFLAGS) -o $@ $<

number_converter: number_converter.c
	$(CC) $(CFLAGS) -o $@ $<

input_validation: input_validation.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples (note: interactive programs need user input)
run-all: all
	@echo "Note: These are interactive programs that require user input"
	@echo "Run them individually to test:"
	@echo "  ./basic_io"
	@echo "  ./interactive_calculator"
	@echo "  ./number_converter"
	@echo "  ./input_validation"

# Individual run targets for testing
run-basic: basic_io
	@echo "Running basic I/O example..."
	./basic_io

run-calc: interactive_calculator
	@echo "Running interactive calculator..."
	./interactive_calculator

run-converter: number_converter
	@echo "Running number converter..."
	./number_converter

run-validation: input_validation
	@echo "Running input validation example..."
	./input_validation

# Help target
help:
	@echo "Available targets:"
	@echo "  all            - Build all programs (default)"
	@echo "  clean          - Remove compiled programs"
	@echo "  run-basic      - Run basic I/O example"
	@echo "  run-calc       - Run interactive calculator"
	@echo "  run-converter  - Run number converter"
	@echo "  run-validation - Run input validation example"
	@echo "  help           - Show this help message"
	@echo ""
	@echo "Note: All programs are interactive and require user input"

.PHONY: all clean run-all run-basic run-calc run-converter run-validation help