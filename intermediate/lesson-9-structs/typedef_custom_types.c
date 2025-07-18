/*
 * Typedef and Custom Types - Creating Clean, Reusable Data Types
 * 
 * This program demonstrates:
 * - typedef for structure aliases
 * - Creating custom data types
 * - Function pointers with typedef
 * - Complex type definitions
 * 
 * For frontend developers: Like creating custom TypeScript interfaces,
 * but with compile-time type checking and memory layout control.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Basic typedef examples
typedef int StudentID;
typedef double Currency;
typedef char* String;

// Structure typedefs - cleaner syntax
typedef struct {
    double x;
    double y;
} Point2D;

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

typedef struct {
    double real;
    double imaginary;
} Complex;

// Advanced typedef for function pointers
typedef double (*MathOperation)(double a, double b);
typedef void (*PrintFunction)(const char* message);
typedef int (*CompareFunction)(const void* a, const void* b);

// Game development example with typedef
typedef struct {
    Point2D position;
    Point2D velocity;
    double health;
    double damage;
    char name[50];
} Player;

typedef struct {
    Point2D position;
    double radius;
    Currency value;
    int collected;
} Coin;

typedef struct {
    Player* players;
    Coin* coins;
    int player_count;
    int coin_count;
    double time_elapsed;
} GameState;

// Financial system example
typedef struct {
    Currency balance;
    Currency credit_limit;
    char account_number[20];
    char holder_name[100];
} BankAccount;

typedef enum {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER,
    INTEREST
} TransactionType;

typedef struct {
    TransactionType type;
    Currency amount;
    char description[100];
    char timestamp[20];
} Transaction;

// Function prototypes
double add_numbers(double a, double b);
double multiply_numbers(double a, double b);
void print_info(const char* message);
void print_warning(const char* message);
int compare_points(const void* a, const void* b);

void demonstrate_basic_typedef(void) {
    printf("=== Basic Typedef Usage ===\n");
    
    // Using typedef aliases
    StudentID student1 = 12345;
    StudentID student2 = 67890;
    Currency price = 29.99;
    Currency tax = 2.40;
    String product_name = "Wireless Mouse";
    
    printf("Student Management:\n");
    printf("  Student ID 1: %d\n", student1);
    printf("  Student ID 2: %d\n", student2);
    
    printf("\nProduct Information:\n");
    printf("  Product: %s\n", product_name);
    printf("  Price: $%.2f\n", price);
    printf("  Tax: $%.2f\n", tax);
    printf("  Total: $%.2f\n", price + tax);
    
    // Type safety demonstration
    printf("\nType Safety:\n");
    printf("  StudentID is really an int: %zu bytes\n", sizeof(StudentID));
    printf("  Currency is really a double: %zu bytes\n", sizeof(Currency));
    printf("  String is really a char*: %zu bytes\n", sizeof(String));
}

void demonstrate_structure_typedef(void) {
    printf("\n=== Structure Typedef ===\n");
    
    // Create points using typedef
    Point2D origin = {0.0, 0.0};
    Point2D destination = {10.5, 8.3};
    Point3D space_point = {5.0, 3.0, 7.2};
    
    printf("2D Points:\n");
    printf("  Origin: (%.1f, %.1f)\n", origin.x, origin.y);
    printf("  Destination: (%.1f, %.1f)\n", destination.x, destination.y);
    
    // Calculate distance
    double dx = destination.x - origin.x;
    double dy = destination.y - origin.y;
    double distance = sqrt(dx * dx + dy * dy);
    printf("  Distance: %.2f units\n", distance);
    
    printf("\n3D Point:\n");
    printf("  Space point: (%.1f, %.1f, %.1f)\n", 
           space_point.x, space_point.y, space_point.z);
    
    // Complex number operations
    Complex num1 = {3.0, 4.0};
    Complex num2 = {1.0, -2.0};
    Complex sum = {num1.real + num2.real, num1.imaginary + num2.imaginary};
    
    printf("\nComplex Numbers:\n");
    printf("  num1: %.1f + %.1fi\n", num1.real, num1.imaginary);
    printf("  num2: %.1f + %.1fi\n", num2.real, num2.imaginary);
    printf("  sum: %.1f + %.1fi\n", sum.real, sum.imaginary);
    
    // Calculate magnitude
    double magnitude1 = sqrt(num1.real * num1.real + num1.imaginary * num1.imaginary);
    printf("  |num1| = %.2f\n", magnitude1);
}

void demonstrate_function_pointer_typedef(void) {
    printf("\n=== Function Pointer Typedef ===\n");
    
    // Array of math operations
    MathOperation operations[] = {add_numbers, multiply_numbers};
    const char* operation_names[] = {"Addition", "Multiplication"};
    
    double a = 15.0, b = 4.0;
    
    printf("Mathematical Operations with a=%.1f, b=%.1f:\n", a, b);
    for (int i = 0; i < 2; i++) {
        double result = operations[i](a, b);
        printf("  %s: %.1f\n", operation_names[i], result);
    }
    
    // Array of print functions
    PrintFunction printers[] = {print_info, print_warning};
    const char* messages[] = {"System operational", "Low memory warning"};
    
    printf("\nMessage System:\n");
    for (int i = 0; i < 2; i++) {
        printers[i](messages[i]);
    }
    
    // Dynamic function selection
    printf("\nDynamic Function Selection:\n");
    MathOperation current_op = add_numbers;
    printf("  Current operation result: %.1f\n", current_op(10.0, 5.0));
    
    current_op = multiply_numbers;
    printf("  Switched operation result: %.1f\n", current_op(10.0, 5.0));
}

void demonstrate_game_system(void) {
    printf("\n=== Game Development with Typedef ===\n");
    
    // Create game state
    GameState game = {0};
    game.player_count = 2;
    game.coin_count = 3;
    game.time_elapsed = 0.0;
    
    // Allocate memory for players and coins
    game.players = malloc(game.player_count * sizeof(Player));
    game.coins = malloc(game.coin_count * sizeof(Coin));
    
    if (game.players == NULL || game.coins == NULL) {
        printf("Failed to allocate game memory\n");
        return;
    }
    
    // Initialize players
    Player* p1 = &game.players[0];
    strcpy(p1->name, "Alice");
    p1->position = (Point2D){0.0, 0.0};
    p1->velocity = (Point2D){2.0, 1.5};
    p1->health = 100.0;
    p1->damage = 25.0;
    
    Player* p2 = &game.players[1];
    strcpy(p2->name, "Bob");
    p2->position = (Point2D){10.0, 5.0};
    p2->velocity = (Point2D){-1.0, 2.0};
    p2->health = 100.0;
    p2->damage = 30.0;
    
    // Initialize coins
    for (int i = 0; i < game.coin_count; i++) {
        game.coins[i].position = (Point2D){i * 5.0 + 2.0, i * 3.0 + 1.0};
        game.coins[i].radius = 0.5;
        game.coins[i].value = 10.0 + i * 5.0;
        game.coins[i].collected = 0;
    }
    
    printf("Game State Initialized:\n");
    printf("  Players: %d\n", game.player_count);
    for (int i = 0; i < game.player_count; i++) {
        Player* p = &game.players[i];
        printf("    %s: pos(%.1f,%.1f), vel(%.1f,%.1f), health=%.0f\n",
               p->name, p->position.x, p->position.y, 
               p->velocity.x, p->velocity.y, p->health);
    }
    
    printf("  Coins: %d\n", game.coin_count);
    for (int i = 0; i < game.coin_count; i++) {
        Coin* c = &game.coins[i];
        printf("    Coin %d: pos(%.1f,%.1f), value=$%.0f, radius=%.1f\n",
               i + 1, c->position.x, c->position.y, c->value, c->radius);
    }
    
    // Simulate game update
    printf("\nSimulating game update (1 second):\n");
    game.time_elapsed += 1.0;
    
    // Update player positions
    for (int i = 0; i < game.player_count; i++) {
        Player* p = &game.players[i];
        p->position.x += p->velocity.x;
        p->position.y += p->velocity.y;
        printf("  %s moved to (%.1f, %.1f)\n", p->name, p->position.x, p->position.y);
    }
    
    // Check coin collection (simple distance check)
    for (int i = 0; i < game.coin_count; i++) {
        if (!game.coins[i].collected) {
            for (int j = 0; j < game.player_count; j++) {
                double dx = game.players[j].position.x - game.coins[i].position.x;
                double dy = game.players[j].position.y - game.coins[i].position.y;
                double distance = sqrt(dx * dx + dy * dy);
                
                if (distance <= game.coins[i].radius + 1.0) {  // Player radius = 1.0
                    printf("  %s collected coin %d worth $%.0f!\n", 
                           game.players[j].name, i + 1, game.coins[i].value);
                    game.coins[i].collected = 1;
                }
            }
        }
    }
    
    printf("  Game time: %.1f seconds\n", game.time_elapsed);
    
    // Clean up
    free(game.players);
    free(game.coins);
}

void demonstrate_financial_system(void) {
    printf("\n=== Financial System with Typedef ===\n");
    
    // Create bank accounts
    BankAccount accounts[] = {
        {1500.00, 5000.00, "ACC-001", "John Smith"},
        {2750.50, 10000.00, "ACC-002", "Jane Doe"},
        {500.25, 2000.00, "ACC-003", "Bob Wilson"}
    };
    
    int account_count = sizeof(accounts) / sizeof(accounts[0]);
    
    printf("Bank Account Summary:\n");
    for (int i = 0; i < account_count; i++) {
        BankAccount* acc = &accounts[i];
        printf("  %s (%s): Balance $%.2f, Credit Limit $%.2f\n",
               acc->holder_name, acc->account_number, acc->balance, acc->credit_limit);
        printf("    Available Credit: $%.2f\n", acc->credit_limit - acc->balance);
    }
    
    // Create transactions
    Transaction transactions[] = {
        {DEPOSIT, 200.00, "Salary deposit", "2024-01-15"},
        {WITHDRAWAL, 50.00, "ATM withdrawal", "2024-01-16"},
        {TRANSFER, 100.00, "Transfer to savings", "2024-01-17"},
        {INTEREST, 15.50, "Monthly interest", "2024-01-31"}
    };
    
    int transaction_count = sizeof(transactions) / sizeof(transactions[0]);
    
    printf("\nRecent Transactions:\n");
    const char* type_names[] = {"Deposit", "Withdrawal", "Transfer", "Interest"};
    
    for (int i = 0; i < transaction_count; i++) {
        Transaction* t = &transactions[i];
        printf("  %s: %s $%.2f - %s (%s)\n",
               t->timestamp, type_names[t->type], t->amount, 
               t->description, t->timestamp);
    }
    
    // Calculate total by transaction type
    Currency totals[4] = {0.0, 0.0, 0.0, 0.0};
    for (int i = 0; i < transaction_count; i++) {
        totals[transactions[i].type] += transactions[i].amount;
    }
    
    printf("\nTransaction Totals:\n");
    for (int i = 0; i < 4; i++) {
        if (totals[i] > 0) {
            printf("  %s: $%.2f\n", type_names[i], totals[i]);
        }
    }
}

// Helper function implementations
double add_numbers(double a, double b) {
    return a + b;
}

double multiply_numbers(double a, double b) {
    return a * b;
}

void print_info(const char* message) {
    printf("  [INFO] %s\n", message);
}

void print_warning(const char* message) {
    printf("  [WARNING] %s\n", message);
}

int compare_points(const void* a, const void* b) {
    const Point2D* p1 = (const Point2D*)a;
    const Point2D* p2 = (const Point2D*)b;
    
    double dist1 = sqrt(p1->x * p1->x + p1->y * p1->y);
    double dist2 = sqrt(p2->x * p2->x + p2->y * p2->y);
    
    if (dist1 < dist2) return -1;
    if (dist1 > dist2) return 1;
    return 0;
}

int main(void) {
    printf("Typedef and Custom Types - Clean, Reusable Data Types\n");
    printf("===================================================\n");
    
    demonstrate_basic_typedef();
    demonstrate_structure_typedef();
    demonstrate_function_pointer_typedef();
    demonstrate_game_system();
    demonstrate_financial_system();
    
    printf("\n=== Key Takeaways ===\n");
    printf("1. typedef creates cleaner, more readable type names\n");
    printf("2. Structure typedef eliminates need for 'struct' keyword\n");
    printf("3. Function pointer typedef enables callback systems\n");
    printf("4. Custom types improve code organization and maintainability\n");
    printf("5. typedef doesn't create new types, just aliases existing ones\n");
    
    return 0;
}