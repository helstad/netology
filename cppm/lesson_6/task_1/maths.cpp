#include "maths.h"
#include <iostream>
#include <cmath>

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        std::cout << "divide 0" << std::endl;
        return 0;
    }
    return a / b;
}

double exponentiation(double base, int exponent) {
    return std::pow(base, exponent);
}