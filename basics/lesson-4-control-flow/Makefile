# Makefile for Lesson 4: Control Flow
# 
# Build and run authentic C control flow programming examples

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -lm

# List of all programs to build
PROGRAMS = grade_calculator number_guessing_game menu_system loop_patterns

# Default target - build all programs
all: $(PROGRAMS)

# Individual program targets
grade_calculator: grade_calculator.c
	$(CC) $(CFLAGS) -o $@ $<

number_guessing_game: number_guessing_game.c
	$(CC) $(CFLAGS) -o $@ $<

menu_system: menu_system.c
	$(CC) $(CFLAGS) -o $@ $<

loop_patterns: loop_patterns.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up compiled programs
clean:
	rm -f $(PROGRAMS)

# Run all examples (note: some are interactive)
run-all: all
	@echo "Note: Some programs are interactive and require user input"
	@echo "Run them individually to test:"
	@echo "  ./grade_calculator"
	@echo "  ./number_guessing_game"
	@echo "  ./menu_system"
	@echo "  ./loop_patterns"

# Individual run targets
run-grade: grade_calculator
	@echo "Running grade calculator..."
	./grade_calculator

run-game: number_guessing_game
	@echo "Running number guessing game..."
	./number_guessing_game

run-menu: menu_system
	@echo "Running menu system..."
	./menu_system

run-loops: loop_patterns
	@echo "Running loop patterns (non-interactive)..."
	./loop_patterns

# Demo target - runs non-interactive examples
demo: loop_patterns
	@echo "=== Loop Patterns Demo ==="
	./loop_patterns

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build all programs (default)"
	@echo "  clean        - Remove compiled programs"
	@echo "  run-grade    - Run grade calculator"
	@echo "  run-game     - Run number guessing game"
	@echo "  run-menu     - Run menu system"
	@echo "  run-loops    - Run loop patterns demo"
	@echo "  demo         - Run non-interactive examples"
	@echo "  help         - Show this help message"
	@echo ""
	@echo "Interactive programs: grade_calculator, number_guessing_game, menu_system"
	@echo "Non-interactive: loop_patterns"

.PHONY: all clean run-all run-grade run-game run-menu run-loops demo help