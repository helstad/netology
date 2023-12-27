#include "Triangle.h"
#include "../exception/GeometryError.h"

Triangle::Triangle(const std::string& name, double a, double b, double c, double angleA, double angleB, double angleC) :
        Figure(name), sideA(a), sideB(b), sideC(c), angleA(angleA), angleB(angleB), angleC(angleC) {
    if (angleA + angleB + angleC != 180) {
        throw GeometryError(name, "Sum of angles is not equal to 180.");
    }
}

Triangle::Triangle(double a, double b, double c, double angleA, double angleB, double angleC) :
        Figure("Triangle"), sideA(a), sideB(b), sideC(c), angleA(angleA), angleB(angleB), angleC(angleC) {
    if (angleA + angleB + angleC != 180) {
        throw GeometryError(name, "Sum of angles is not equal to 180.");
    }
}

void Triangle::print_info() const {
    Figure::print_info();
    std::cout << "sides: " << sideA << ", " << sideB << ", " << sideC << "\nangle: " << angleA << ", " << angleB << ", "
              << angleC << "\n- Being created" << std::endl;
}