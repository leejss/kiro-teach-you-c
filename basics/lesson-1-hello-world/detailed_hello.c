/*
 * Detailed Hello World - Understanding Each Component
 * 
 * This example breaks down every part of a C program
 * to help frontend developers understand the structure
 */

// Preprocessor directive - includes standard I/O functions
// Similar to: import { printf } from 'stdio' in JavaScript terms
#include <stdio.h>

/*
 * main() function - the entry point of every C program
 * 
 * - 'int' means this function returns an integer
 * - The returned value is the program's exit status
 * - 0 typically means "success", non-zero means "error"
 */
int main() {
    /*
     * printf() - formatted print function
     * 
     * - Writes text to standard output (usually terminal)
     * - \n is a newline character (like \n in JavaScript strings)
     * - Unlike console.log(), printf doesn't add newline automatically
     */
    printf("Hello, World!\n");
    
    /*
     * return statement - program exit status
     * 
     * - Returns 0 to indicate successful execution
     * - The operating system receives this value
     * - You can check this with: echo $? (after running the program)
     */
    return 0;
}