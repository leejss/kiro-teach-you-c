/*
 * String Functions - Standard Library String Operations
 * 
 * This example demonstrates:
 * - Standard string.h library functions
 * - Safe string handling practices
 * - String searching and manipulation
 * - Character classification functions
 * 
 * These are the essential string functions that every
 * C programmer must know and use correctly.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes for custom string functions
void printStringInfo(const char* str, const char* name);
void demonstrateStringSearch(void);
void demonstrateCharacterFunctions(void);
void demonstrateStringTokenization(void);

int main() {
    printf("=== Standard String Functions ===\n\n");
    
    // 1. Basic String Information Functions
    printf("1. String Information Functions:\n");
    char text1[] = "Hello, World!";
    char text2[] = "C Programming";
    char text3[] = "";
    
    printStringInfo(text1, "text1");
    printStringInfo(text2, "text2");
    printStringInfo(text3, "text3 (empty)");
    printf("\n");
    
    // 2. String Copying Functions
    printf("2. String Copying Functions:\n");
    char source[] = "Source String";
    char dest1[50];
    char dest2[10];
    
    // strcpy - copies entire string
    strcpy(dest1, source);
    printf("strcpy result: '%s'\n", dest1);
    
    // strncpy - copies up to n characters
    strncpy(dest2, source, sizeof(dest2) - 1);
    dest2[sizeof(dest2) - 1] = '\0';  // Ensure null termination
    printf("strncpy result (9 chars): '%s'\n", dest2);
    printf("\n");
    
    // 3. String Concatenation Functions
    printf("3. String Concatenation Functions:\n");
    char buffer1[100] = "Hello";
    char buffer2[20] = "Hi";
    
    strcat(buffer1, " World");
    printf("strcat result: '%s'\n", buffer1);
    
    strncat(buffer2, " there, how are you?", sizeof(buffer2) - strlen(buffer2) - 1);
    printf("strncat result: '%s'\n", buffer2);
    printf("\n");
    
    // 4. String Comparison Functions
    printf("4. String Comparison Functions:\n");
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "apple";
    char str4[] = "Apple";
    
    printf("strcmp('%s', '%s') = %d\n", str1, str2, strcmp(str1, str2));
    printf("strcmp('%s', '%s') = %d\n", str1, str3, strcmp(str1, str3));
    printf("strcmp('%s', '%s') = %d\n", str1, str4, strcmp(str1, str4));
    
    // Compare first n characters
    printf("strncmp('%s', '%s', 3) = %d\n", str1, str2, strncmp(str1, str2, 3));
    printf("\n");
    
    // 5. String Searching Functions
    printf("5. String Searching Functions:\n");
    demonstrateStringSearch();
    printf("\n");
    
    // 6. Character Classification Functions
    printf("6. Character Classification Functions:\n");
    demonstrateCharacterFunctions();
    printf("\n");
    
    // 7. String Tokenization
    printf("7. String Tokenization (strtok):\n");
    demonstrateStringTokenization();
    printf("\n");
    
    // 8. Memory Functions for Strings
    printf("8. Memory Functions for Strings:\n");
    char mem1[20] = "Hello World";
    char mem2[20];
    
    // memcpy - copy memory block
    memcpy(mem2, mem1, strlen(mem1) + 1);
    printf("memcpy result: '%s'\n", mem2);
    
    // memset - set memory to specific value
    memset(mem1 + 5, '*', 3);  // Replace " Wo" with "***"
    printf("memset result: '%s'\n", mem1);
    
    // memcmp - compare memory blocks
    char block1[] = "ABCD";
    char block2[] = "ABCE";
    printf("memcmp result: %d\n", memcmp(block1, block2, 4));
    printf("\n");
    
    // 9. Safe String Handling Examples
    printf("9. Safe String Handling:\n");
    char safeBuffer[50];
    const char* longString = "This is a very long string that might overflow a small buffer";
    
    // Safe copying
    size_t maxCopy = sizeof(safeBuffer) - 1;
    strncpy(safeBuffer, longString, maxCopy);
    safeBuffer[maxCopy] = '\0';
    printf("Safely copied: '%s'\n", safeBuffer);
    
    // Safe concatenation
    char safeConcat[30] = "Start: ";
    size_t remaining = sizeof(safeConcat) - strlen(safeConcat) - 1;
    strncat(safeConcat, "Adding more text here", remaining);
    printf("Safely concatenated: '%s'\n", safeConcat);
    
    return 0;
}

// Function definitions

void printStringInfo(const char* str, const char* name) {
    printf("%s: '%s'\n", name, str);
    printf("  Length: %zu\n", strlen(str));
    printf("  First char: '%c' (ASCII: %d)\n", 
           str[0] ? str[0] : '?', str[0]);
    if (strlen(str) > 0) {
        printf("  Last char: '%c' (ASCII: %d)\n", 
               str[strlen(str) - 1], str[strlen(str) - 1]);
    }
}

void demonstrateStringSearch(void) {
    char text[] = "The quick brown fox jumps over the lazy dog";
    
    printf("Text: '%s'\n", text);
    
    // strchr - find first occurrence of character
    char* found = strchr(text, 'q');
    if (found) {
        printf("First 'q' found at position: %ld\n", found - text);
    }
    
    // strrchr - find last occurrence of character
    found = strrchr(text, 'o');
    if (found) {
        printf("Last 'o' found at position: %ld\n", found - text);
    }
    
    // strstr - find substring
    found = strstr(text, "fox");
    if (found) {
        printf("'fox' found at position: %ld\n", found - text);
    }
    
    // strpbrk - find first occurrence of any character from set
    found = strpbrk(text, "aeiou");
    if (found) {
        printf("First vowel '%c' found at position: %ld\n", *found, found - text);
    }
}

void demonstrateCharacterFunctions(void) {
    char testString[] = "Hello123 World!";
    
    printf("Analyzing string: '%s'\n", testString);
    printf("Character analysis:\n");
    
    for (int i = 0; testString[i] != '\0'; i++) {
        char ch = testString[i];
        printf("'%c': ", ch);
        
        if (isalpha(ch)) printf("letter ");
        if (isdigit(ch)) printf("digit ");
        if (isspace(ch)) printf("space ");
        if (ispunct(ch)) printf("punctuation ");
        if (isupper(ch)) printf("uppercase ");
        if (islower(ch)) printf("lowercase ");
        
        printf("\n");
    }
    
    // Character conversion
    printf("\nCharacter conversion:\n");
    char mixed[] = "HeLLo WoRLd";
    printf("Original: %s\n", mixed);
    
    // Convert to uppercase
    for (int i = 0; mixed[i] != '\0'; i++) {
        mixed[i] = toupper(mixed[i]);
    }
    printf("Uppercase: %s\n", mixed);
    
    // Convert to lowercase
    for (int i = 0; mixed[i] != '\0'; i++) {
        mixed[i] = tolower(mixed[i]);
    }
    printf("Lowercase: %s\n", mixed);
}

void demonstrateStringTokenization(void) {
    // Note: strtok modifies the original string
    char sentence[] = "apple,banana;orange:grape";
    char delimiters[] = ",;:";
    
    printf("Original string: '%s'\n", sentence);
    printf("Delimiters: '%s'\n", delimiters);
    printf("Tokens:\n");
    
    char* token = strtok(sentence, delimiters);
    int tokenCount = 0;
    
    while (token != NULL) {
        tokenCount++;
        printf("  Token %d: '%s'\n", tokenCount, token);
        token = strtok(NULL, delimiters);  // Continue tokenizing
    }
    
    printf("Total tokens found: %d\n", tokenCount);
    printf("Note: Original string was modified by strtok\n");
}