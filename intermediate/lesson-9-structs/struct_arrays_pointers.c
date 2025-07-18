/*
 * Structure Arrays and Pointers - Dynamic Data Management
 * 
 * This program demonstrates:
 * - Arrays of structures
 * - Pointers to structures
 * - Dynamic structure allocation
 * - Structure pointer arithmetic
 * 
 * For frontend developers: Like arrays of JavaScript objects,
 * but with explicit memory management and pointer manipulation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures for a library management system
struct Book {
    int id;
    char title[100];
    char author[50];
    int year;
    double price;
    int pages;
    char genre[30];
    int available;  // 1 = available, 0 = checked out
};

struct Library {
    char name[100];
    struct Book* books;  // Dynamic array of books
    int book_count;
    int capacity;
    char location[100];
};

// Function prototypes
void print_book(const struct Book* book);
void print_library_stats(const struct Library* lib);
struct Book* find_book_by_id(struct Book* books, int count, int id);
struct Book* find_books_by_author(struct Book* books, int count, const char* author, int* found_count);
void sort_books_by_year(struct Book* books, int count);

void demonstrate_structure_arrays(void) {
    printf("=== Arrays of Structures ===\n");
    
    // Create array of books
    struct Book library_books[] = {
        {1, "The C Programming Language", "Kernighan & Ritchie", 1978, 45.99, 272, "Programming", 1},
        {2, "Clean Code", "Robert Martin", 2008, 39.99, 464, "Programming", 1},
        {3, "The Pragmatic Programmer", "Hunt & Thomas", 1999, 42.50, 352, "Programming", 0},
        {4, "Design Patterns", "Gang of Four", 1994, 54.99, 395, "Programming", 1},
        {5, "Algorithms", "Sedgewick & Wayne", 2011, 89.99, 976, "Computer Science", 1}
    };
    
    int book_count = sizeof(library_books) / sizeof(library_books[0]);
    
    printf("Library Collection (%d books):\n", book_count);
    for (int i = 0; i < book_count; i++) {
        printf("  %d. ", i + 1);
        print_book(&library_books[i]);
    }
    
    // Calculate collection statistics
    double total_value = 0.0;
    int total_pages = 0;
    int available_count = 0;
    
    for (int i = 0; i < book_count; i++) {
        total_value += library_books[i].price;
        total_pages += library_books[i].pages;
        if (library_books[i].available) {
            available_count++;
        }
    }
    
    printf("\nCollection Statistics:\n");
    printf("  Total value: $%.2f\n", total_value);
    printf("  Total pages: %d\n", total_pages);
    printf("  Available books: %d/%d\n", available_count, book_count);
    printf("  Average price: $%.2f\n", total_value / book_count);
    printf("  Average pages: %.1f\n", (double)total_pages / book_count);
}

void demonstrate_structure_pointers(void) {
    printf("\n=== Structure Pointers ===\n");
    
    struct Book book = {
        .id = 100,
        .title = "Advanced C Programming",
        .author = "Peter van der Linden",
        .year = 1994,
        .price = 49.99,
        .pages = 384,
        .genre = "Programming",
        .available = 1
    };
    
    // Pointer to structure
    struct Book* book_ptr = &book;
    
    printf("Accessing structure through pointer:\n");
    printf("  Direct access: %s by %s\n", book.title, book.author);
    printf("  Pointer access: %s by %s\n", book_ptr->title, book_ptr->author);
    printf("  Alternative syntax: %s (year %d)\n", (*book_ptr).title, (*book_ptr).year);
    
    // Modify through pointer
    book_ptr->price = 44.99;  // Apply discount
    book_ptr->available = 0;  // Check out book
    
    printf("\nAfter modification through pointer:\n");
    printf("  New price: $%.2f\n", book.price);
    printf("  Available: %s\n", book.available ? "Yes" : "No");
    
    // Demonstrate pointer arithmetic with array
    struct Book books[] = {
        {1, "Book One", "Author A", 2020, 25.99, 200, "Fiction", 1},
        {2, "Book Two", "Author B", 2021, 29.99, 250, "Fiction", 1},
        {3, "Book Three", "Author C", 2022, 32.99, 300, "Fiction", 0}
    };
    
    struct Book* ptr = books;  // Points to first book
    
    printf("\nPointer arithmetic with structure array:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Book %d: %s ($%.2f)\n", (ptr + i)->id, (ptr + i)->title, (ptr + i)->price);
    }
    
    // Alternative traversal
    printf("\nAlternative traversal:\n");
    ptr = books;
    for (int i = 0; i < 3; i++) {
        printf("  %s - %s\n", ptr->title, ptr->author);
        ptr++;  // Move to next structure
    }
}

void demonstrate_dynamic_structures(void) {
    printf("\n=== Dynamic Structure Allocation ===\n");
    
    // Allocate memory for library
    struct Library* lib = malloc(sizeof(struct Library));
    if (lib == NULL) {
        printf("Failed to allocate memory for library\n");
        return;
    }
    
    // Initialize library
    strcpy(lib->name, "Central Public Library");
    strcpy(lib->location, "Downtown Main Street");
    lib->capacity = 10;
    lib->book_count = 0;
    
    // Allocate memory for books array
    lib->books = malloc(lib->capacity * sizeof(struct Book));
    if (lib->books == NULL) {
        printf("Failed to allocate memory for books\n");
        free(lib);
        return;
    }
    
    printf("Created library: %s\n", lib->name);
    printf("Location: %s\n", lib->location);
    printf("Capacity: %d books\n", lib->capacity);
    
    // Add books to library
    struct Book new_books[] = {
        {101, "Dynamic Programming", "Author X", 2023, 55.99, 400, "Computer Science", 1},
        {102, "Memory Management", "Author Y", 2023, 48.99, 350, "Computer Science", 1},
        {103, "Data Structures", "Author Z", 2022, 52.99, 450, "Computer Science", 1}
    };
    
    int new_book_count = sizeof(new_books) / sizeof(new_books[0]);
    
    // Copy books to library (check capacity)
    for (int i = 0; i < new_book_count && lib->book_count < lib->capacity; i++) {
        lib->books[lib->book_count] = new_books[i];
        lib->book_count++;
    }
    
    printf("\nAdded %d books to library:\n", lib->book_count);
    for (int i = 0; i < lib->book_count; i++) {
        printf("  ");
        print_book(&lib->books[i]);
    }
    
    print_library_stats(lib);
    
    // Clean up memory
    free(lib->books);
    free(lib);
    printf("\nMemory cleaned up successfully\n");
}

void demonstrate_structure_search(void) {
    printf("\n=== Structure Search Operations ===\n");
    
    struct Book catalog[] = {
        {201, "C Primer Plus", "Stephen Prata", 2013, 49.99, 1080, "Programming", 1},
        {202, "Expert C Programming", "Peter van der Linden", 1994, 44.99, 384, "Programming", 1},
        {203, "C Traps and Pitfalls", "Andrew Koenig", 1989, 39.99, 154, "Programming", 0},
        {204, "The C Answer Book", "Clovis Tondo", 1989, 34.99, 208, "Programming", 1},
        {205, "C Programming FAQs", "Steve Summit", 1995, 42.99, 432, "Programming", 1}
    };
    
    int catalog_size = sizeof(catalog) / sizeof(catalog[0]);
    
    // Search by ID
    printf("Searching for book with ID 203:\n");
    struct Book* found_book = find_book_by_id(catalog, catalog_size, 203);
    if (found_book != NULL) {
        printf("  Found: ");
        print_book(found_book);
    } else {
        printf("  Book not found\n");
    }
    
    // Search by author
    printf("\nSearching for books by 'Peter van der Linden':\n");
    int found_count = 0;
    struct Book* author_books = find_books_by_author(catalog, catalog_size, "Peter van der Linden", &found_count);
    
    if (author_books != NULL && found_count > 0) {
        printf("  Found %d book(s):\n", found_count);
        for (int i = 0; i < found_count; i++) {
            printf("    ");
            print_book(&author_books[i]);
        }
        free(author_books);  // Clean up allocated memory
    } else {
        printf("  No books found by this author\n");
    }
    
    // Sort books by year
    printf("\nSorting books by publication year:\n");
    sort_books_by_year(catalog, catalog_size);
    for (int i = 0; i < catalog_size; i++) {
        printf("  %d: ", catalog[i].year);
        print_book(&catalog[i]);
    }
}

// Helper function implementations
void print_book(const struct Book* book) {
    printf("\"%s\" by %s (%d) - $%.2f [%s]\n",
           book->title, book->author, book->year, book->price,
           book->available ? "Available" : "Checked out");
}

void print_library_stats(const struct Library* lib) {
    printf("\nLibrary Statistics for %s:\n", lib->name);
    printf("  Books: %d/%d\n", lib->book_count, lib->capacity);
    
    if (lib->book_count > 0) {
        double total_value = 0.0;
        int available_count = 0;
        
        for (int i = 0; i < lib->book_count; i++) {
            total_value += lib->books[i].price;
            if (lib->books[i].available) {
                available_count++;
            }
        }
        
        printf("  Total collection value: $%.2f\n", total_value);
        printf("  Available books: %d\n", available_count);
        printf("  Average book price: $%.2f\n", total_value / lib->book_count);
    }
}

struct Book* find_book_by_id(struct Book* books, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            return &books[i];
        }
    }
    return NULL;
}

struct Book* find_books_by_author(struct Book* books, int count, const char* author, int* found_count) {
    // First pass: count matches
    *found_count = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].author, author) != NULL) {
            (*found_count)++;
        }
    }
    
    if (*found_count == 0) {
        return NULL;
    }
    
    // Allocate memory for results
    struct Book* results = malloc(*found_count * sizeof(struct Book));
    if (results == NULL) {
        *found_count = 0;
        return NULL;
    }
    
    // Second pass: copy matches
    int result_index = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].author, author) != NULL) {
            results[result_index] = books[i];
            result_index++;
        }
    }
    
    return results;
}

void sort_books_by_year(struct Book* books, int count) {
    // Simple bubble sort by year
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].year > books[j + 1].year) {
                // Swap entire structures
                struct Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    printf("Structure Arrays and Pointers - Dynamic Data Management\n");
    printf("======================================================\n");
    
    demonstrate_structure_arrays();
    demonstrate_structure_pointers();
    demonstrate_dynamic_structures();
    demonstrate_structure_search();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Arrays of structures organize collections of related data\n");
    printf("2. Use -> operator for pointer-to-structure member access\n");
    printf("3. Dynamic allocation enables flexible data structures\n");
    printf("4. Always check malloc return values and free allocated memory\n");
    printf("5. Structure pointers enable efficient data manipulation\n");
    
    return 0;
}