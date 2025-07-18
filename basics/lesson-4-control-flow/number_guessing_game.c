/*
 * Number Guessing Game - Loops and Conditions
 * 
 * This is a classic C programming exercise that demonstrates:
 * - while loops for repetition
 * - Conditional statements for game logic
 * - User input validation
 * - Loop control with break and continue
 * 
 * This type of interactive program is a staple of C programming
 * education and shows practical use of control structures.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("=== Number Guessing Game ===\n\n");
    
    // Initialize random number generator
    srand(time(NULL));
    
    // Generate random number between 1 and 100
    int secret_number = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    int max_attempts = 7;
    
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n\n", max_attempts);
    
    // Main game loop
    while (attempts < max_attempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, max_attempts);
        
        // Input validation
        if (scanf("%d", &guess) != 1) {
            printf("Please enter a valid number!\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;  // Skip to next iteration
        }
        
        attempts++;
        
        // Check the guess
        if (guess == secret_number) {
            printf("\n🎉 Congratulations! You guessed it!\n");
            printf("The number was %d\n", secret_number);
            printf("You won in %d attempts!\n", attempts);
            break;  // Exit the loop
        } else if (guess < secret_number) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }
        
        // Provide hints based on how close they are
        int difference = abs(guess - secret_number);
        if (difference <= 5) {
            printf("You're very close!\n");
        } else if (difference <= 15) {
            printf("You're getting warmer.\n");
        } else {
            printf("You're cold.\n");
        }
        
        // Show remaining attempts
        int remaining = max_attempts - attempts;
        if (remaining > 0) {
            printf("You have %d attempts left.\n\n", remaining);
        }
    }
    
    // Check if player ran out of attempts
    if (attempts >= max_attempts && guess != secret_number) {
        printf("\n😞 Game Over! You've used all your attempts.\n");
        printf("The number was %d\n", secret_number);
    }
    
    // Game statistics
    printf("\n=== Game Statistics ===\n");
    printf("Secret number: %d\n", secret_number);
    printf("Your final guess: %d\n", guess);
    printf("Total attempts: %d\n", attempts);
    
    if (guess == secret_number) {
        if (attempts == 1) {
            printf("Rating: INCREDIBLE! First try!\n");
        } else if (attempts <= 3) {
            printf("Rating: EXCELLENT! Very few attempts!\n");
        } else if (attempts <= 5) {
            printf("Rating: GOOD! Nice guessing!\n");
        } else {
            printf("Rating: OKAY! You made it!\n");
        }
    } else {
        printf("Rating: Better luck next time!\n");
    }
    
    // Ask if they want to play again
    char play_again;
    printf("\nWould you like to play again? (y/n): ");
    scanf(" %c", &play_again);
    
    if (play_again == 'y' || play_again == 'Y') {
        printf("Great! Run the program again to play!\n");
    } else {
        printf("Thanks for playing!\n");
    }
    
    return 0;
}