/*
 * Nested Structures - Complex Data Organization
 * 
 * This program demonstrates:
 * - Nested structure definitions
 * - Complex data hierarchies
 * - Accessing nested members
 * - Real-world data modeling
 * 
 * For frontend developers: Like nested JavaScript objects,
 * but with fixed structure and compile-time type checking.
 */

#include <stdio.h>
#include <string.h>

// Define nested structures for a company employee system
struct Address {
    char street[100];
    char city[50];
    char state[20];
    int zip_code;
    char country[30];
};

struct Date {
    int day;
    int month;
    int year;
};

struct Contact {
    char email[100];
    char phone[20];
    char emergency_contact[50];
    char emergency_phone[20];
};

struct Department {
    char name[50];
    char code[10];
    char manager[50];
    int employee_count;
};

struct Employee {
    int id;
    char first_name[30];
    char last_name[30];
    struct Date birth_date;
    struct Date hire_date;
    struct Address home_address;
    struct Contact contact_info;
    struct Department department;
    double salary;
    char position[50];
};

// Product catalog system
struct Dimensions {
    double length;
    double width;
    double height;
    char unit[10];  // "cm", "in", etc.
};

struct Price {
    double amount;
    char currency[5];  // "USD", "EUR", etc.
    double discount_percent;
};

struct Manufacturer {
    char name[50];
    char country[30];
    int established_year;
};

struct Product {
    char name[100];
    char sku[20];
    struct Dimensions size;
    struct Price pricing;
    struct Manufacturer maker;
    int stock_quantity;
    char category[30];
};

void demonstrate_employee_system(void) {
    printf("=== Employee Management System ===\n");
    
    // Create employee record with nested initialization
    struct Employee emp = {
        .id = 12345,
        .first_name = "Sarah",
        .last_name = "Johnson",
        .birth_date = {15, 3, 1990},  // March 15, 1990
        .hire_date = {1, 9, 2020},    // September 1, 2020
        .home_address = {
            .street = "123 Oak Street",
            .city = "San Francisco",
            .state = "CA",
            .zip_code = 94102,
            .country = "USA"
        },
        .contact_info = {
            .email = "sarah.johnson@company.com",
            .phone = "(555) 123-4567",
            .emergency_contact = "Mike Johnson",
            .emergency_phone = "(555) 987-6543"
        },
        .department = {
            .name = "Software Engineering",
            .code = "SE",
            .manager = "Alice Chen",
            .employee_count = 25
        },
        .salary = 95000.00,
        .position = "Senior Software Engineer"
    };
    
    // Display employee information
    printf("Employee Information:\n");
    printf("  ID: %d\n", emp.id);
    printf("  Name: %s %s\n", emp.first_name, emp.last_name);
    printf("  Position: %s\n", emp.position);
    printf("  Salary: $%.2f\n", emp.salary);
    
    printf("\nBirth Date: %d/%d/%d\n", 
           emp.birth_date.month, emp.birth_date.day, emp.birth_date.year);
    printf("Hire Date: %d/%d/%d\n", 
           emp.hire_date.month, emp.hire_date.day, emp.hire_date.year);
    
    printf("\nHome Address:\n");
    printf("  %s\n", emp.home_address.street);
    printf("  %s, %s %d\n", emp.home_address.city, 
           emp.home_address.state, emp.home_address.zip_code);
    printf("  %s\n", emp.home_address.country);
    
    printf("\nContact Information:\n");
    printf("  Email: %s\n", emp.contact_info.email);
    printf("  Phone: %s\n", emp.contact_info.phone);
    printf("  Emergency: %s (%s)\n", emp.contact_info.emergency_contact,
           emp.contact_info.emergency_phone);
    
    printf("\nDepartment:\n");
    printf("  %s (%s)\n", emp.department.name, emp.department.code);
    printf("  Manager: %s\n", emp.department.manager);
    printf("  Team Size: %d employees\n", emp.department.employee_count);
}

void demonstrate_product_catalog(void) {
    printf("\n=== Product Catalog System ===\n");
    
    // Create product entries
    struct Product products[] = {
        {
            .name = "Wireless Bluetooth Headphones",
            .sku = "WBH-2024-001",
            .size = {18.5, 15.2, 8.0, "cm"},
            .pricing = {149.99, "USD", 15.0},
            .maker = {"AudioTech", "Germany", 1995},
            .stock_quantity = 250,
            .category = "Electronics"
        },
        {
            .name = "Ergonomic Office Chair",
            .sku = "EOC-2024-002",
            .size = {65.0, 65.0, 120.0, "cm"},
            .pricing = {299.99, "USD", 10.0},
            .maker = {"ComfortSeating", "USA", 1987},
            .stock_quantity = 45,
            .category = "Furniture"
        }
    };
    
    int product_count = sizeof(products) / sizeof(products[0]);
    
    printf("Product Catalog (%d items):\n", product_count);
    
    for (int i = 0; i < product_count; i++) {
        struct Product* p = &products[i];
        
        printf("\n--- Product %d ---\n", i + 1);
        printf("Name: %s\n", p->name);
        printf("SKU: %s\n", p->sku);
        printf("Category: %s\n", p->category);
        
        printf("Dimensions: %.1f x %.1f x %.1f %s\n",
               p->size.length, p->size.width, p->size.height, p->size.unit);
        
        // Calculate discounted price
        double discounted_price = p->pricing.amount * (1.0 - p->pricing.discount_percent / 100.0);
        printf("Price: %.2f %s", p->pricing.amount, p->pricing.currency);
        if (p->pricing.discount_percent > 0) {
            printf(" (%.0f%% off: %.2f %s)", 
                   p->pricing.discount_percent, discounted_price, p->pricing.currency);
        }
        printf("\n");
        
        printf("Manufacturer: %s (%s, est. %d)\n",
               p->maker.name, p->maker.country, p->maker.established_year);
        printf("Stock: %d units\n", p->stock_quantity);
        
        // Calculate volume
        double volume = p->size.length * p->size.width * p->size.height;
        printf("Volume: %.2f cubic %s\n", volume, p->size.unit);
    }
}

void demonstrate_data_analysis(void) {
    printf("\n=== Data Analysis with Nested Structures ===\n");
    
    // Create a small employee database
    struct Employee team[] = {
        {
            .id = 1001, .first_name = "John", .last_name = "Doe",
            .hire_date = {1, 1, 2020}, .salary = 75000.00,
            .department = {"Engineering", "ENG", "Alice Smith", 15}
        },
        {
            .id = 1002, .first_name = "Jane", .last_name = "Smith",
            .hire_date = {15, 6, 2019}, .salary = 82000.00,
            .department = {"Engineering", "ENG", "Alice Smith", 15}
        },
        {
            .id = 1003, .first_name = "Bob", .last_name = "Wilson",
            .hire_date = {10, 3, 2021}, .salary = 68000.00,
            .department = {"Marketing", "MKT", "Carol Johnson", 8}
        }
    };
    
    int team_size = sizeof(team) / sizeof(team[0]);
    
    // Calculate average salary
    double total_salary = 0.0;
    for (int i = 0; i < team_size; i++) {
        total_salary += team[i].salary;
    }
    double average_salary = total_salary / team_size;
    
    printf("Team Analysis:\n");
    printf("  Total employees: %d\n", team_size);
    printf("  Average salary: $%.2f\n", average_salary);
    
    // Find senior employees (hired before 2021)
    printf("\nSenior employees (hired before 2021):\n");
    for (int i = 0; i < team_size; i++) {
        if (team[i].hire_date.year < 2021) {
            printf("  %s %s (hired %d/%d/%d, salary: $%.2f)\n",
                   team[i].first_name, team[i].last_name,
                   team[i].hire_date.month, team[i].hire_date.day, team[i].hire_date.year,
                   team[i].salary);
        }
    }
    
    // Group by department
    printf("\nDepartment breakdown:\n");
    printf("  Engineering: ");
    for (int i = 0; i < team_size; i++) {
        if (strcmp(team[i].department.code, "ENG") == 0) {
            printf("%s %s ", team[i].first_name, team[i].last_name);
        }
    }
    printf("\n  Marketing: ");
    for (int i = 0; i < team_size; i++) {
        if (strcmp(team[i].department.code, "MKT") == 0) {
            printf("%s %s ", team[i].first_name, team[i].last_name);
        }
    }
    printf("\n");
}

void demonstrate_structure_modification(void) {
    printf("\n=== Modifying Nested Structures ===\n");
    
    struct Employee emp = {
        .id = 2001,
        .first_name = "Alex",
        .last_name = "Rodriguez",
        .salary = 70000.00,
        .department = {"Sales", "SAL", "Tom Brown", 12}
    };
    
    printf("Original employee data:\n");
    printf("  %s %s - %s Department\n", 
           emp.first_name, emp.last_name, emp.department.name);
    printf("  Salary: $%.2f\n", emp.salary);
    
    // Promote employee - change department and salary
    strcpy(emp.department.name, "Management");
    strcpy(emp.department.code, "MGT");
    strcpy(emp.department.manager, "CEO");
    emp.department.employee_count = 5;
    emp.salary = 95000.00;
    strcpy(emp.position, "Department Manager");
    
    printf("\nAfter promotion:\n");
    printf("  %s %s - %s (%s)\n", 
           emp.first_name, emp.last_name, emp.position, emp.department.name);
    printf("  Salary: $%.2f\n", emp.salary);
    printf("  Reports to: %s\n", emp.department.manager);
    printf("  Team size: %d\n", emp.department.employee_count);
    
    // Update contact information
    strcpy(emp.contact_info.email, "alex.rodriguez@company.com");
    strcpy(emp.contact_info.phone, "(555) 234-5678");
    
    printf("  New email: %s\n", emp.contact_info.email);
    printf("  New phone: %s\n", emp.contact_info.phone);
}

int main(void) {
    printf("Nested Structures - Complex Data Organization\n");
    printf("============================================\n");
    
    demonstrate_employee_system();
    demonstrate_product_catalog();
    demonstrate_data_analysis();
    demonstrate_structure_modification();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. Nested structures model complex real-world data\n");
    printf("2. Use dot notation to access nested members\n");
    printf("3. Designated initializers make complex initialization clear\n");
    printf("4. Structures can contain arrays and other structures\n");
    printf("5. Organize related data logically for maintainable code\n");
    
    return 0;
}