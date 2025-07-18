# Lesson 7: Strings & String Manipulation

## Learning Objectives

By the end of this lesson, you'll understand:

- C strings as null-terminated character arrays
- String declaration, initialization, and memory management
- Standard string library functions (string.h)
- Manual string processing and manipulation
- String input/output and validation

## Key Concepts for Frontend Developers

### JavaScript vs C: Strings

**JavaScript (String Objects):**

```javascript
let str = "Hello World"; // Immutable string object
let length = str.length; // Built-in property
let upper = str.toUpperCase(); // Built-in method
let substr = str.substring(0, 5); // Built-in slicing
let words = str.split(" "); // Built-in splitting
str += " JavaScript"; // Automatic concatenation
```

**C (Character Arrays):**

```c
char str[20] = "Hello World";   // Mutable character array
int length = strlen(str);       // Manual function call
// No built-in toUpperCase - must implement manually
char substr[6];                 // Manual substring extraction
strncpy(substr, str, 5);
substr[5] = '\0';               // Manual null termination
strcat(str, " C");              // Manual concatenation
```

**Key Differences:**

- C strings are mutable character arrays, not immutable objects
- No automatic memory management - you control the buffer size
- Manual null termination ('\0') required
- No built-in methods - use library functions or implement manually
- Buffer overflow risks if not careful with bounds

## C String Fundamentals

### String Declaration and Initialization

```c
// Different ways to declare strings
char str1[50];                    // Uninitialized buffer
char str2[20] = "Hello";          // Initialized with literal
char str3[] = "World";            // Size inferred from literal
char str4[10] = {'H','i','\0'};   // Character by character
char *str5 = "Constant";          // Pointer to string literal (read-only)
```

### String Memory Layout

```
String: "Hello"
Memory: |H|e|l|l|o|\0|
Index:   0 1 2 3 4  5

Buffer: char str[10] = "Hi";
Memory: |H|i|\0|?|?|?|?|?|?|?|
Index:   0 1  2 3 4 5 6 7 8 9
```

### Essential String Functions (string.h)

```c
strlen(str)              // Get string length
strcpy(dest, src)        // Copy string
strncpy(dest, src, n)    // Copy n characters
strcat(dest, src)        // Concatenate strings
strncat(dest, src, n)    // Concatenate n characters
strcmp(str1, str2)       // Compare strings
strncmp(str1, str2, n)   // Compare n characters
strchr(str, ch)          // Find character
strstr(str, substr)      // Find substring
```

## String Processing Patterns

### Safe String Operations

```c
// Always check buffer bounds
char buffer[100];
if (strlen(source) < sizeof(buffer)) {
    strcpy(buffer, source);
}

// Use safer alternatives
strncpy(buffer, source, sizeof(buffer) - 1);
buffer[sizeof(buffer) - 1] = '\0';
```

## Examples

1. `string_basics.c` - String declaration, initialization, and basic operations
2. `string_functions.c` - Standard library functions and their usage
3. `string_processing.c` - Manual string manipulation and algorithms
4. `text_analyzer.c` - Practical text analysis and processing

## Real-World Applications

- **Text Processing**: Log file analysis, configuration parsing
- **Data Validation**: Input sanitization and format checking
- **Protocol Implementation**: HTTP headers, network protocols
- **File Processing**: CSV parsing, text file manipulation

## Compilation & Execution

```bash
# Build all examples
make all

# Run individual examples
./string_basics
./string_functions
./string_processing
./text_analyzer
```

## Next Steps

After mastering strings, you'll learn about pointers, which will deepen your understanding of how strings work in memory and enable more advanced string manipulation techniques.
