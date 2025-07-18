/*
 * Math Library - Function Definition and Organization
 * 
 * This example demonstrates:
 * - Function prototypes and definitions
 * - Parameter passing and return values
 * - Creating a simple math utility library
 * - Function organization and modularity
 * 
 * This is a classic C programming pattern for organizing
 * related functions into logical modules.
 */

#include <stdio.h>

// Function prototypes (declarations)
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
int power(int base, int exponent);
int factorial(int n);
int gcd(int a, int b);
int lcm(int a, int b);
double circleArea(double radius);
double circleCircumference(double radius);
int isEven(int number);
int isPrime(int number);

int main() {
    printf("=== Math Library Demonstration ===\n\n");
    
    // Basic arithmetic operations
    printf("Basic Arithmetic:\n");
    printf("add(15, 25) = %d\n", add(15, 25));
    printf("subtract(50, 18) = %d\n", subtract(50, 18));
    printf("multiply(7, 8) = %d\n", multiply(7, 8));
    printf("divide(22.0, 7.0) = %.3f\n", divide(22.0, 7.0));
    printf("\n");
    
    // Power and factorial
    printf("Power and Factorial:\n");
    printf("power(2, 8) = %d\n", power(2, 8));
    printf("factorial(6) = %d\n", factorial(6));
    printf("\n");
    
    // GCD and LCM
    printf("GCD and LCM:\n");
    int num1 = 48, num2 = 18;
    printf("gcd(%d, %d) = %d\n", num1, num2, gcd(num1, num2));
    printf("lcm(%d, %d) = %d\n", num1, num2, lcm(num1, num2));
    printf("\n");
    
    // Circle calculations
    printf("Circle Calculations (radius = 5.0):\n");
    double radius = 5.0;
    printf("Area = %.2f\n", circleArea(radius));
    printf("Circumference = %.2f\n", circleCircumference(radius));
    printf("\n");
    
    // Number properties
    printf("Number Properties:\n");
    for (int i = 10; i <= 15; i++) {
        printf("%d: %s, %s\n", i, 
               isEven(i) ? "Even" : "Odd",
               isPrime(i) ? "Prime" : "Not Prime");
    }
    
    return 0;
}

// Function definitions

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0.0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        return 0.0;
    }
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int factorial(int n) {
    if (n < 0) {
        return -1; // Error: negative number
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int gcd(int a, int b) {
    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

double circleArea(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

double circleCircumference(double radius) {
    const double PI = 3.14159265359;
    return 2 * PI * radius;
}

int isEven(int number) {
    return (number % 2 == 0);
}

int isPrime(int number) {
    if (number < 2) {
        return 0; // Not prime
    }
    
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}