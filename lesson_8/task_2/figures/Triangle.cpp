#include "Triangle.h"
#include "../exception/GeometryError.h"

Triangle::Triangle(double a, double b, double c, double angleA, double angleB, double angleC) :
        Figure("Triangle"), sideA(a), sideB(b), sideC(c), angleA(angleA), angleB(angleB), angleC(angleC) {}

void Triangle::print_info() const {
    Figure::print_info();
    std::cout << "sides: " << sideA << ", " << sideB << ", " << sideC << "\nangle: " << angleA << ", " << angleB << ", "
              << angleC << "\n- Being created" << std::endl;
}

bool Triangle::check() const {
    if (angleA + angleB + angleC != 180) {
        throw GeometryError("Sum of angles is not equal to 180.");
    }
  return true;
}