/*
 * Scope Demonstration - Variable Scope and Lifetime
 * 
 * This example demonstrates:
 * - Local vs global variable scope
 * - Function parameter scope
 * - Variable lifetime and storage
 * - Scope resolution and shadowing
 * 
 * Understanding scope is crucial for C programming
 * and helps prevent common bugs and naming conflicts.
 */

#include <stdio.h>

// Global variables - accessible from any function
int global_counter = 0;
char global_message[] = "Global message";

// Function prototypes
void demonstrateLocalScope();
void demonstrateParameterScope(int parameter);
void demonstrateGlobalAccess();
void demonstrateStaticVariables();
void demonstrateShadowing();
void modifyGlobal();
void dontModifyParameter(int value);
void showVariableLifetime();

int main() {
    printf("=== Variable Scope Demonstration ===\n\n");
    
    // Local variables in main
    int main_variable = 100;
    printf("Main function - local variable: %d\n", main_variable);
    printf("Main function - global counter: %d\n", global_counter);
    printf("\n");
    
    // Demonstrate local scope
    printf("1. Local Scope Demonstration:\n");
    demonstrateLocalScope();
    printf("Back in main - main_variable still: %d\n", main_variable);
    printf("\n");
    
    // Demonstrate parameter scope
    printf("2. Parameter Scope Demonstration:\n");
    demonstrateParameterScope(42);
    printf("\n");
    
    // Demonstrate global access
    printf("3. Global Variable Access:\n");
    printf("Before function call - global_counter: %d\n", global_counter);
    demonstrateGlobalAccess();
    printf("After function call - global_counter: %d\n", global_counter);
    printf("\n");
    
    // Demonstrate static variables
    printf("4. Static Variables (multiple calls):\n");
    for (int i = 0; i < 3; i++) {
        printf("Call %d: ", i + 1);
        demonstrateStaticVariables();
    }
    printf("\n");
    
    // Demonstrate variable shadowing
    printf("5. Variable Shadowing:\n");
    demonstrateShadowing();
    printf("\n");
    
    // Demonstrate global modification
    printf("6. Global Variable Modification:\n");
    printf("Before modifyGlobal() - global_counter: %d\n", global_counter);
    modifyGlobal();
    printf("After modifyGlobal() - global_counter: %d\n", global_counter);
    printf("\n");
    
    // Demonstrate parameter passing (pass by value)
    printf("7. Parameter Passing (Pass by Value):\n");
    int test_value = 50;
    printf("Before function call - test_value: %d\n", test_value);
    dontModifyParameter(test_value);
    printf("After function call - test_value: %d\n", test_value);
    printf("\n");
    
    // Demonstrate variable lifetime
    printf("8. Variable Lifetime:\n");
    showVariableLifetime();
    
    return 0;
}

// Function definitions

void demonstrateLocalScope() {
    // Local variables - only accessible within this function
    int local_var1 = 10;
    int local_var2 = 20;
    
    printf("Inside demonstrateLocalScope():\n");
    printf("  local_var1: %d\n", local_var1);
    printf("  local_var2: %d\n", local_var2);
    
    // These variables will be destroyed when function ends
    local_var1 = 999;
    printf("  Modified local_var1: %d\n", local_var1);
}

void demonstrateParameterScope(int parameter) {
    printf("Inside demonstrateParameterScope():\n");
    printf("  parameter value: %d\n", parameter);
    
    // Modifying parameter only affects local copy
    parameter = 100;
    printf("  Modified parameter: %d\n", parameter);
    
    // Parameter goes out of scope when function ends
}

void demonstrateGlobalAccess() {
    printf("Inside demonstrateGlobalAccess():\n");
    printf("  Accessing global_counter: %d\n", global_counter);
    printf("  Accessing global_message: %s\n", global_message);
    
    // Can modify global variables
    global_counter += 10;
    printf("  Modified global_counter to: %d\n", global_counter);
}

void demonstrateStaticVariables() {
    // Static variable - retains value between function calls
    static int static_counter = 0;
    
    // Regular local variable - reinitialized each call
    int local_counter = 0;
    
    static_counter++;
    local_counter++;
    
    printf("static_counter: %d, local_counter: %d\n", 
           static_counter, local_counter);
}

void demonstrateShadowing() {
    // Local variable with same name as global
    int global_counter = 500;  // Shadows the global variable
    
    printf("Inside demonstrateShadowing():\n");
    printf("  Local global_counter: %d\n", global_counter);
    printf("  (This shadows the global variable)\n");
    
    // To access the actual global, we'd need to use extern or avoid shadowing
    
    {
        // Block scope - even more local
        int global_counter = 777;  // Shadows both global and function-level
        printf("  Inside block - global_counter: %d\n", global_counter);
    }
    
    printf("  Back in function - global_counter: %d\n", global_counter);
}

void modifyGlobal() {
    printf("Inside modifyGlobal():\n");
    printf("  Current global_counter: %d\n", global_counter);
    
    global_counter *= 2;
    printf("  Doubled global_counter to: %d\n", global_counter);
}

void dontModifyParameter(int value) {
    printf("Inside dontModifyParameter():\n");
    printf("  Received value: %d\n", value);
    
    value = 999;  // This only modifies the local copy
    printf("  Modified local copy to: %d\n", value);
    printf("  (Original variable in main is unchanged)\n");
}

void showVariableLifetime() {
    printf("Demonstrating variable lifetime:\n");
    
    for (int i = 0; i < 3; i++) {
        // These variables are created and destroyed each iteration
        int loop_var = i * 10;
        printf("  Iteration %d: loop_var = %d\n", i, loop_var);
        
        // Static variable persists across iterations
        static int persistent_var = 0;
        persistent_var += i;
        printf("  Iteration %d: persistent_var = %d\n", i, persistent_var);
    }
    
    // loop_var and i are no longer accessible here
    printf("Variables i and loop_var are now out of scope\n");
}