/*
 * String Processing - Manual String Manipulation and Algorithms
 * 
 * This example demonstrates:
 * - Custom string processing functions
 * - String algorithms and patterns
 * - Text manipulation techniques
 * - Performance considerations
 * 
 * These manual implementations show how string operations
 * work under the hood and are essential for system programming.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
int customStrlen(const char* str);
void customStrcpy(char* dest, const char* src);
int customStrcmp(const char* str1, const char* str2);
void reverseString(char* str);
bool isPalindrome(const char* str);
void removeSpaces(char* str);
void replaceChar(char* str, char oldChar, char newChar);
int countWords(const char* str);
void capitalizeWords(char* str);
void trimWhitespace(char* str);
int findSubstring(const char* text, const char* pattern);
void stringToUpper(char* str);
void stringToLower(char* str);

int main() {
    printf("=== String Processing and Algorithms ===\n\n");
    
    // 1. Custom String Functions
    printf("1. Custom String Function Implementations:\n");
    char test[] = "Hello World";
    char copy[50];
    
    printf("Original string: '%s'\n", test);
    printf("Custom strlen: %d\n", customStrlen(test));
    printf("Standard strlen: %zu\n", strlen(test));
    
    customStrcpy(copy, test);
    printf("Custom strcpy result: '%s'\n", copy);
    
    printf("Custom strcmp('apple', 'banana'): %d\n", customStrcmp("apple", "banana"));
    printf("Custom strcmp('hello', 'hello'): %d\n", customStrcmp("hello", "hello"));
    printf("\n");
    
    // 2. String Reversal
    printf("2. String Reversal:\n");
    char reversible[] = "Programming";
    printf("Original: '%s'\n", reversible);
    reverseString(reversible);
    printf("Reversed: '%s'\n", reversible);
    printf("\n");
    
    // 3. Palindrome Detection
    printf("3. Palindrome Detection:\n");
    char* testWords[] = {"racecar", "hello", "madam", "programming", "level"};
    int numWords = sizeof(testWords) / sizeof(testWords[0]);
    
    for (int i = 0; i < numWords; i++) {
        printf("'%s': %s\n", testWords[i], 
               isPalindrome(testWords[i]) ? "Palindrome" : "Not palindrome");
    }
    printf("\n");
    
    // 4. String Cleaning and Formatting
    printf("4. String Cleaning and Formatting:\n");
    
    char spacedText[] = "  Hello   World   Programming  ";
    printf("Original: '%s'\n", spacedText);
    
    char copy1[100], copy2[100], copy3[100];
    strcpy(copy1, spacedText);
    strcpy(copy2, spacedText);
    strcpy(copy3, spacedText);
    
    removeSpaces(copy1);
    printf("Spaces removed: '%s'\n", copy1);
    
    trimWhitespace(copy2);
    printf("Whitespace trimmed: '%s'\n", copy2);
    
    capitalizeWords(copy3);
    printf("Words capitalized: '%s'\n", copy3);
    printf("\n");
    
    // 5. Character Replacement
    printf("5. Character Replacement:\n");
    char replaceTest[] = "Hello World Programming";
    printf("Original: '%s'\n", replaceTest);
    
    replaceChar(replaceTest, 'o', '*');
    printf("Replace 'o' with '*': '%s'\n", replaceTest);
    printf("\n");
    
    // 6. Word Counting
    printf("6. Word Counting:\n");
    char* sentences[] = {
        "Hello world",
        "The quick brown fox jumps",
        "C programming is powerful",
        "   Multiple   spaces   between   words   ",
        ""
    };
    
    for (int i = 0; i < 5; i++) {
        printf("'%s' -> %d words\n", sentences[i], countWords(sentences[i]));
    }
    printf("\n");
    
    // 7. Case Conversion
    printf("7. Case Conversion:\n");
    char upperTest[] = "Hello World 123!";
    char lowerTest[] = "PROGRAMMING IN C";
    
    printf("Original: '%s'\n", upperTest);
    stringToUpper(upperTest);
    printf("To upper: '%s'\n", upperTest);
    
    printf("Original: '%s'\n", lowerTest);
    stringToLower(lowerTest);
    printf("To lower: '%s'\n", lowerTest);
    printf("\n");
    
    // 8. Substring Search
    printf("8. Substring Search:\n");
    char searchText[] = "The quick brown fox jumps over the lazy dog";
    char* patterns[] = {"fox", "cat", "the", "jump", "dog"};
    
    printf("Text: '%s'\n", searchText);
    for (int i = 0; i < 5; i++) {
        int pos = findSubstring(searchText, patterns[i]);
        if (pos != -1) {
            printf("'%s' found at position %d\n", patterns[i], pos);
        } else {
            printf("'%s' not found\n", patterns[i]);
        }
    }
    printf("\n");
    
    // 9. String Statistics
    printf("9. String Statistics:\n");
    char statsText[] = "Hello World! How are you today? 123";
    
    int letters = 0, digits = 0, spaces = 0, punctuation = 0;
    
    for (int i = 0; statsText[i] != '\0'; i++) {
        if (isalpha(statsText[i])) letters++;
        else if (isdigit(statsText[i])) digits++;
        else if (isspace(statsText[i])) spaces++;
        else if (ispunct(statsText[i])) punctuation++;
    }
    
    printf("Text: '%s'\n", statsText);
    printf("Statistics:\n");
    printf("  Total characters: %d\n", customStrlen(statsText));
    printf("  Letters: %d\n", letters);
    printf("  Digits: %d\n", digits);
    printf("  Spaces: %d\n", spaces);
    printf("  Punctuation: %d\n", punctuation);
    printf("  Words: %d\n", countWords(statsText));
    
    return 0;
}

// Function definitions

int customStrlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void customStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int customStrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }
    
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

bool isPalindrome(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(str[i]) != tolower(str[length - 1 - i])) {
            return false;
        }
    }
    return true;
}

void removeSpaces(char* str) {
    int writeIndex = 0;
    for (int readIndex = 0; str[readIndex] != '\0'; readIndex++) {
        if (str[readIndex] != ' ') {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }
    str[writeIndex] = '\0';
}

void replaceChar(char* str, char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    
    return count;
}

void capitalizeWords(char* str) {
    bool newWord = true;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            newWord = true;
        } else if (newWord) {
            str[i] = toupper(str[i]);
            newWord = false;
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void trimWhitespace(char* str) {
    // Trim leading whitespace
    int start = 0;
    while (isspace(str[start])) {
        start++;
    }
    
    // Shift string left
    int writeIndex = 0;
    for (int i = start; str[i] != '\0'; i++) {
        str[writeIndex] = str[i];
        writeIndex++;
    }
    str[writeIndex] = '\0';
    
    // Trim trailing whitespace
    int end = strlen(str) - 1;
    while (end >= 0 && isspace(str[end])) {
        str[end] = '\0';
        end--;
    }
}

int findSubstring(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    
    if (patternLen == 0) return 0;
    if (patternLen > textLen) return -1;
    
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            return i;  // Found at position i
        }
    }
    
    return -1;  // Not found
}

void stringToUpper(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void stringToLower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}