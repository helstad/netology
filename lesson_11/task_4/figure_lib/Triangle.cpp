#include "Triangle.h"

Triangle::Triangle(double a, double b, double c, double angleA, double angleB, double angleC) :
        Figure("Triangle"), sideA(a), sideB(b), sideC(c), angleA(angleA), angleB(angleB), angleC(angleC) {}

void Triangle::print_info() const {
    Figure::print_info();
    std::cout << "Sides: a=" << sideA << " b=" << sideB << " c=" << sideC << std::endl;
    std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << std::endl;
};