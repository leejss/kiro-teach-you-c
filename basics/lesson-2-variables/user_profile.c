/*
 * User Profile - Working with Multiple Data Types
 * 
 * This example demonstrates how to work with different C data types
 * together in a practical scenario. This is a common C programming
 * pattern for managing structured data.
 * 
 * Key C Programming Concepts:
 * - Using multiple data types together
 * - Variable scope and lifetime
 * - Basic data validation
 * - Formatted output with different types
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== User Profile Data Management ===\n\n");
    
    // User profile variables - different types for different data
    int user_id = 12345;
    char first_initial = 'J';
    char last_initial = 'D';
    int age = 28;
    double account_balance = 1250.75;
    float credit_score = 742.5f;
    bool is_premium_member = true;
    bool email_verified = false;
    int login_count = 47;
    
    // Display user profile
    printf("User Profile Information:\n");
    printf("User ID: %d\n", user_id);
    printf("Name: %c.%c.\n", first_initial, last_initial);
    printf("Age: %d years\n", age);
    printf("Account Balance: $%.2f\n", account_balance);
    printf("Credit Score: %.1f\n", credit_score);
    printf("Premium Member: %s\n", is_premium_member ? "Yes" : "No");
    printf("Email Verified: %s\n", email_verified ? "Yes" : "No");
    printf("Total Logins: %d\n", login_count);
    printf("\n");
    
    // Perform some operations on the data
    printf("=== Account Operations ===\n");
    
    // Simulate a transaction
    double transaction_amount = 125.50;
    account_balance -= transaction_amount;
    printf("Transaction: -$%.2f\n", transaction_amount);
    printf("New Balance: $%.2f\n", account_balance);
    
    // Update login count
    login_count++;
    printf("Login count updated: %d\n", login_count);
    
    // Age calculation
    int birth_year = 2024 - age;  // Assuming current year is 2024
    printf("Estimated birth year: %d\n", birth_year);
    printf("\n");
    
    // Data validation and status checks
    printf("=== Account Status Checks ===\n");
    
    bool account_in_good_standing = (account_balance > 0.0);
    bool frequent_user = (login_count > 30);
    bool adult_user = (age >= 18);
    bool good_credit = (credit_score >= 700.0f);
    
    printf("Account in good standing: %s\n", account_in_good_standing ? "Yes" : "No");
    printf("Frequent user: %s\n", frequent_user ? "Yes" : "No");
    printf("Adult user: %s\n", adult_user ? "Yes" : "No");
    printf("Good credit score: %s\n", good_credit ? "Yes" : "No");
    
    // Calculate eligibility for premium upgrade
    bool eligible_for_upgrade = account_in_good_standing && 
                               frequent_user && 
                               adult_user && 
                               !is_premium_member;
    
    printf("\nEligible for premium upgrade: %s\n", 
           eligible_for_upgrade ? "Yes" : "No");
    
    // Type conversion example
    printf("\n=== Type Conversions ===\n");
    int age_in_months = age * 12;
    double balance_in_cents = account_balance * 100.0;
    int credit_score_rounded = (int)credit_score;  // Explicit cast
    
    printf("Age in months: %d\n", age_in_months);
    printf("Balance in cents: %.0f\n", balance_in_cents);
    printf("Credit score (rounded): %d\n", credit_score_rounded);
    
    return 0;
}