/*
 * String Basics - Fundamental String Operations in C
 * 
 * This example demonstrates:
 * - String declaration and initialization
 * - Character array vs string literal differences
 * - Basic string operations and null termination
 * - String input/output operations
 * 
 * Understanding C strings is crucial because they're used
 * everywhere in C programming and system interfaces.
 */

#include <stdio.h>
#include <string.h>

int main() {
    printf("=== String Basics in C ===\n\n");
    
    // 1. String Declaration and Initialization
    printf("1. String Declaration and Initialization:\n");
    
    // Different ways to declare and initialize strings
    char str1[50] = "Hello World";           // Character array with string literal
    char str2[] = "C Programming";           // Size inferred from literal
    char str3[20];                           // Uninitialized buffer
    char str4[10] = {'H', 'i', '!', '\0'};  // Character by character
    char *str5 = "String Literal";           // Pointer to string literal (read-only)
    
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str4: %s\n", str4);
    printf("str5: %s\n", str5);
    printf("\n");
    
    // 2. String Length and Memory
    printf("2. String Length and Memory:\n");
    printf("str1 length: %zu characters\n", strlen(str1));
    printf("str1 buffer size: %zu bytes\n", sizeof(str1));
    printf("str2 length: %zu characters\n", strlen(str2));
    printf("str2 buffer size: %zu bytes\n", sizeof(str2));
    printf("\n");
    
    // 3. Null Termination Demonstration
    printf("3. Null Termination:\n");
    char demo[10] = {'A', 'B', 'C'};  // No null terminator initially
    printf("Without null terminator: ");
    // This might print garbage after 'ABC'
    for (int i = 0; i < 10; i++) {
        if (demo[i] == '\0') {
            printf("\\0");
            break;
        } else if (demo[i] >= 32 && demo[i] <= 126) {
            printf("%c", demo[i]);
        } else {
            printf("?");
        }
    }
    printf("\n");
    
    demo[3] = '\0';  // Add null terminator
    printf("With null terminator: %s\n", demo);
    printf("Length after adding \\0: %zu\n", strlen(demo));
    printf("\n");
    
    // 4. String Copying
    printf("4. String Copying:\n");
    strcpy(str3, "Copied String");
    printf("str3 after strcpy: %s\n", str3);
    
    // Safe copying with size limit
    char buffer[10];
    strncpy(buffer, "This is a very long string", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null termination
    printf("Safe copy to small buffer: %s\n", buffer);
    printf("\n");
    
    // 5. String Concatenation
    printf("5. String Concatenation:\n");
    char greeting[50] = "Hello";
    strcat(greeting, " ");
    strcat(greeting, "World");
    strcat(greeting, "!");
    printf("Concatenated string: %s\n", greeting);
    
    // Safe concatenation
    char result[20] = "Hi";
    strncat(result, " there, how are you today?", sizeof(result) - strlen(result) - 1);
    printf("Safe concatenation: %s\n", result);
    printf("\n");
    
    // 6. String Comparison
    printf("6. String Comparison:\n");
    char word1[] = "apple";
    char word2[] = "banana";
    char word3[] = "apple";
    
    printf("Comparing '%s' and '%s': %d\n", word1, word2, strcmp(word1, word2));
    printf("Comparing '%s' and '%s': %d\n", word1, word3, strcmp(word1, word3));
    printf("Comparing '%s' and '%s': %d\n", word2, word1, strcmp(word2, word1));
    
    if (strcmp(word1, word3) == 0) {
        printf("'%s' and '%s' are equal\n", word1, word3);
    }
    printf("\n");
    
    // 7. Character Access and Modification
    printf("7. Character Access and Modification:\n");
    char modifiable[] = "Hello";
    printf("Original: %s\n", modifiable);
    
    // Change individual characters
    modifiable[0] = 'h';  // Lowercase 'h'
    modifiable[4] = '!';  // Change 'o' to '!'
    printf("Modified: %s\n", modifiable);
    
    // Character-by-character processing
    printf("Characters with indices:\n");
    for (int i = 0; modifiable[i] != '\0'; i++) {
        printf("  [%d]: '%c' (ASCII: %d)\n", i, modifiable[i], modifiable[i]);
    }
    printf("\n");
    
    // 8. String Input (be careful with buffer sizes!)
    printf("8. String Input:\n");
    char userInput[100];
    
    printf("Enter your name: ");
    if (fgets(userInput, sizeof(userInput), stdin) != NULL) {
        // Remove newline if present
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
        }
        printf("Hello, %s!\n", userInput);
        printf("Your name has %zu characters.\n", strlen(userInput));
    }
    printf("\n");
    
    // 9. String Literals vs Character Arrays
    printf("9. String Literals vs Character Arrays:\n");
    char array[] = "Modifiable";    // Character array - can modify
    char *literal = "Read Only";    // String literal - should not modify
    
    printf("Array: %s\n", array);
    printf("Literal: %s\n", literal);
    
    // This is safe
    array[0] = 'm';
    printf("Modified array: %s\n", array);
    
    // This would be unsafe and might crash:
    // literal[0] = 'r';  // DON'T DO THIS!
    
    printf("Note: String literals should not be modified!\n");
    
    return 0;
}