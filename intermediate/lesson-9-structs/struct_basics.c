/*
 * Structure Basics - Defining and Using Custom Data Types
 * 
 * This program demonstrates:
 * - Structure definition and declaration
 * - Member access using dot operator
 * - Structure initialization methods
 * - Memory layout and sizeof
 * 
 * For frontend developers: Think of structures like JavaScript objects,
 * but with fixed properties defined at compile time.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

// Define basic structures
struct Point {
    double x;
    double y;
};

struct Rectangle {
    double width;
    double height;
    char color[20];
};

struct Student {
    char name[50];
    int age;
    double gpa;
    int graduation_year;
};

void demonstrate_basic_structures(void) {
    printf("=== Basic Structure Definition and Usage ===\n");
    
    // Create and initialize structures
    struct Point origin = {0.0, 0.0};
    struct Point center = {10.5, 15.3};
    
    printf("Point structures:\n");
    printf("  Origin: (%.1f, %.1f)\n", origin.x, origin.y);
    printf("  Center: (%.1f, %.1f)\n", center.x, center.y);
    
    // Modify structure members
    center.x = 20.0;
    center.y = 25.0;
    printf("  Modified center: (%.1f, %.1f)\n", center.x, center.y);
    
    // Calculate distance between points
    double dx = center.x - origin.x;
    double dy = center.y - origin.y;
    double distance = sqrt(dx * dx + dy * dy);
    printf("  Distance from origin to center: %.2f\n", distance);
}

void demonstrate_structure_initialization(void) {
    printf("\n=== Structure Initialization Methods ===\n");
    
    // Method 1: Designated initializers (C99 - recommended)
    struct Rectangle rect1 = {
        .width = 10.0,
        .height = 5.0,
        .color = "blue"
    };
    
    // Method 2: Positional initialization
    struct Rectangle rect2 = {8.0, 6.0, "red"};
    
    // Method 3: Partial initialization (rest becomes zero/empty)
    struct Rectangle rect3 = {.width = 12.0};
    
    // Method 4: Zero initialization
    struct Rectangle rect4 = {0};
    
    printf("Rectangle initialization methods:\n");
    printf("  rect1 (designated): %.1f x %.1f, color: %s\n", 
           rect1.width, rect1.height, rect1.color);
    printf("  rect2 (positional): %.1f x %.1f, color: %s\n", 
           rect2.width, rect2.height, rect2.color);
    printf("  rect3 (partial): %.1f x %.1f, color: '%s'\n", 
           rect3.width, rect3.height, rect3.color);
    printf("  rect4 (zero): %.1f x %.1f, color: '%s'\n", 
           rect4.width, rect4.height, rect4.color);
    
    // Runtime initialization
    struct Rectangle rect5;
    rect5.width = 15.0;
    rect5.height = 8.0;
    strcpy(rect5.color, "green");
    
    printf("  rect5 (runtime): %.1f x %.1f, color: %s\n", 
           rect5.width, rect5.height, rect5.color);
}

void demonstrate_student_records(void) {
    printf("\n=== Student Record Management ===\n");
    
    // Create student records
    struct Student students[3] = {
        {"Alice Johnson", 20, 3.85, 2025},
        {"Bob Smith", 19, 3.42, 2026},
        {.name = "Carol Davis", .age = 21, .gpa = 3.91, .graduation_year = 2024}
    };
    
    printf("Student roster:\n");
    for (int i = 0; i < 3; i++) {
        printf("  %d. %s (Age: %d, GPA: %.2f, Graduates: %d)\n",
               i + 1, students[i].name, students[i].age, 
               students[i].gpa, students[i].graduation_year);
    }
    
    // Find student with highest GPA
    int best_student_index = 0;
    for (int i = 1; i < 3; i++) {
        if (students[i].gpa > students[best_student_index].gpa) {
            best_student_index = i;
        }
    }
    
    printf("\nHighest GPA: %s with %.2f\n", 
           students[best_student_index].name, 
           students[best_student_index].gpa);
    
    // Update student information
    students[1].age = 20;  // Bob had a birthday
    students[1].gpa = 3.55;  // Bob improved his grades
    
    printf("Updated Bob's record: Age %d, GPA %.2f\n", 
           students[1].age, students[1].gpa);
}

void demonstrate_structure_copying(void) {
    printf("\n=== Structure Copying and Assignment ===\n");
    
    struct Point original = {5.0, 10.0};
    struct Point copy;
    
    // Structure assignment copies all members
    copy = original;
    
    printf("Original point: (%.1f, %.1f)\n", original.x, original.y);
    printf("Copied point: (%.1f, %.1f)\n", copy.x, copy.y);
    
    // Modify copy - original unchanged
    copy.x = 100.0;
    copy.y = 200.0;
    
    printf("After modifying copy:\n");
    printf("  Original: (%.1f, %.1f)\n", original.x, original.y);
    printf("  Copy: (%.1f, %.1f)\n", copy.x, copy.y);
    
    // Demonstrate that structures are copied by value
    printf("Structure assignment creates independent copies\n");
}

void demonstrate_memory_layout(void) {
    printf("\n=== Structure Memory Layout ===\n");
    
    struct Point point;
    struct Rectangle rect;
    struct Student student;
    
    printf("Structure sizes:\n");
    printf("  Point (2 doubles): %zu bytes\n", sizeof(struct Point));
    printf("  Rectangle (2 doubles + 20 chars): %zu bytes\n", sizeof(struct Rectangle));
    printf("  Student (50 chars + int + double + int): %zu bytes\n", sizeof(struct Student));
    
    printf("\nMember offsets in Student structure:\n");
    printf("  name offset: %zu bytes\n", offsetof(struct Student, name));
    printf("  age offset: %zu bytes\n", offsetof(struct Student, age));
    printf("  gpa offset: %zu bytes\n", offsetof(struct Student, gpa));
    printf("  graduation_year offset: %zu bytes\n", offsetof(struct Student, graduation_year));
    
    // Demonstrate memory addresses
    printf("\nMemory addresses of point members:\n");
    printf("  point address: %p\n", (void*)&point);
    printf("  point.x address: %p\n", (void*)&point.x);
    printf("  point.y address: %p\n", (void*)&point.y);
    printf("  Difference: %ld bytes\n", (char*)&point.y - (char*)&point.x);
}

// Helper function to calculate rectangle area
double calculate_area(struct Rectangle rect) {
    return rect.width * rect.height;
}

// Helper function to print point information
void print_point_info(struct Point p, const char* label) {
    printf("%s: (%.2f, %.2f)\n", label, p.x, p.y);
}

void demonstrate_structure_functions(void) {
    printf("\n=== Structures with Functions ===\n");
    
    struct Rectangle room = {12.5, 8.0, "white"};
    struct Point corners[4] = {
        {0.0, 0.0},      // Bottom-left
        {room.width, 0.0},  // Bottom-right
        {room.width, room.height},  // Top-right
        {0.0, room.height}   // Top-left
    };
    
    printf("Room dimensions: %.1f x %.1f (%s)\n", 
           room.width, room.height, room.color);
    printf("Room area: %.2f square units\n", calculate_area(room));
    
    printf("\nRoom corners:\n");
    print_point_info(corners[0], "Bottom-left");
    print_point_info(corners[1], "Bottom-right");
    print_point_info(corners[2], "Top-right");
    print_point_info(corners[3], "Top-left");
    
    // Calculate room perimeter using corner points
    double perimeter = 2 * (room.width + room.height);
    printf("Room perimeter: %.2f units\n", perimeter);
}

int main(void) {
    printf("Structure Basics - Custom Data Types in C\n");
    printf("========================================\n");
    
    demonstrate_basic_structures();
    demonstrate_structure_initialization();
    demonstrate_student_records();
    demonstrate_structure_copying();
    demonstrate_memory_layout();
    demonstrate_structure_functions();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Structures group related data into single units\n");
    printf("2. Use designated initializers for clarity\n");
    printf("3. Structure assignment copies all members\n");
    printf("4. Members are accessed with dot operator\n");
    printf("5. Structures have predictable memory layout\n");
    
    return 0;
}