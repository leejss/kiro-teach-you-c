/*
 * Return Codes - Understanding Program Exit Status
 * 
 * This example demonstrates how C programs communicate
 * success or failure to the operating system
 */

#include <stdio.h>

int main() {
    printf("This program demonstrates return codes\n");
    printf("Run this program and then check: echo $?\n");
    printf("You should see: 0\n\n");
    
    printf("Try modifying the return value to see different exit codes:\n");
    printf("- return 0;  // Success\n");
    printf("- return 1;  // General error\n");
    printf("- return 42; // Custom error code\n\n");
    
    // Return 0 for success
    // In shell scripting and system programming, this is how
    // programs communicate their status to other programs
    return 0;
    
    // Try changing to: return 1; or return 42; to see different exit codes
}