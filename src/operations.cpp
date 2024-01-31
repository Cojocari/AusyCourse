//////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file      operations.cpp
/// @ingroup   Math operations
/// @author    Adrian Cojocari
/// @date      31/01/2024
/// @brief     Insert here a short description
///
/// @copyright Copyright (C) Insert Here All Rights Reserved.
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "../headers/operations.h"

int MathOperations::add(int num1, int num2) {
    return num1 + num2;
}

int MathOperations::subtract(int num1, int num2) {
    return num1 - num2;
}

int MathOperations::multiply(int num1, int num2) {
    return num1 * num2;
}

float MathOperations::divide(int num1, int num2) {
    if (num2 == 0) {
        std::cerr << "Error: Division by zero\n";
        return 0;
    }
    return static_cast<float>(num1) / num2;
}

// Utilize multiple functions from the base class to perform an advanced operation
int AdvancedMathOperations::performAdvancedOperation(int num1, int num2, int num3) {
    // For example, let's perform (num1 * num2) + (num2 - num3)
    int result1 = multiply(num1, num2);
    int result2 = subtract(num2, num3);
    return add(result1, result2);
}

// Calculate square root using Newton's method
double AdvancedMathOperations::squareRoot(double x, double epsilon) {
    if (x < 0) {
        std::cerr << "Error: Cannot calculate square root of a negative number\n";
        return 0.0;
    }

    double guess = x / 2.0;
    while (std::abs(guess * guess - x) >= epsilon) {
        guess = (guess + x / guess) / 2.0;
    }

    return guess;
}