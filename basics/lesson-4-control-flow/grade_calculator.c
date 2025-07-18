/*
 * Grade Calculator - Conditional Statements in C
 * 
 * This is a classic C programming exercise that demonstrates:
 * - if/else if/else chains
 * - Logical operators and comparisons
 * - Input validation with conditions
 * - Multiple condition evaluation
 * 
 * This type of conditional logic is fundamental in C programming
 * and appears in virtually every C program.
 */

#include <stdio.h>

int main() {
    printf("=== Grade Calculator ===\n\n");
    
    int score;
    char letter_grade;
    
    // Get score from user
    printf("Enter your test score (0-100): ");
    if (scanf("%d", &score) != 1) {
        printf("Error: Please enter a valid number\n");
        return 1;
    }
    
    // Input validation
    if (score < 0 || score > 100) {
        printf("Error: Score must be between 0 and 100\n");
        return 1;
    }
    
    // Grade calculation using if/else if chain
    if (score >= 90) {
        letter_grade = 'A';
        printf("Excellent work!\n");
    } else if (score >= 80) {
        letter_grade = 'B';
        printf("Good job!\n");
    } else if (score >= 70) {
        letter_grade = 'C';
        printf("Satisfactory.\n");
    } else if (score >= 60) {
        letter_grade = 'D';
        printf("Needs improvement.\n");
    } else {
        letter_grade = 'F';
        printf("Please study harder.\n");
    }
    
    printf("Score: %d\n", score);
    printf("Grade: %c\n\n", letter_grade);
    
    // Additional analysis using logical operators
    printf("=== Grade Analysis ===\n");
    
    // Multiple conditions with logical operators
    if (score >= 90 && score <= 100) {
        printf("Honor roll student!\n");
    }
    
    if (score >= 70 && score < 80) {
        printf("Close to a B grade - keep trying!\n");
    }
    
    if (score < 60 || score == 0) {
        printf("Consider retaking the test.\n");
    }
    
    // Nested conditions
    if (score >= 60) {
        printf("Status: PASS\n");
        
        if (score >= 85) {
            printf("Eligible for advanced courses.\n");
        } else {
            printf("Standard course progression.\n");
        }
    } else {
        printf("Status: FAIL\n");
        printf("Must retake the course.\n");
    }
    
    // Grade point calculation
    float gpa;
    if (score >= 90) {
        gpa = 4.0f;
    } else if (score >= 80) {
        gpa = 3.0f;
    } else if (score >= 70) {
        gpa = 2.0f;
    } else if (score >= 60) {
        gpa = 1.0f;
    } else {
        gpa = 0.0f;
    }
    
    printf("GPA equivalent: %.1f\n", gpa);
    
    // Percentage analysis
    printf("\nPercentage Analysis:\n");
    if (score == 100) {
        printf("Perfect score!\n");
    } else if (score >= 95) {
        printf("Nearly perfect!\n");
    } else if (score >= 50) {
        printf("Above 50%% - good effort\n");
    } else {
        printf("Below 50%% - significant improvement needed\n");
    }
    
    return 0;
}