#include "Quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double angle1, double angle2, double angle3,
                       double angle4)
        : Figure("Quadrangle"), sideA(a), sideB(b), sideC(c), sideD(d), angleA(angle1), angleB(angle2), angleC(angle3),
          angleD(angle4) {}

void Quadrangle::print_info() const {
    Figure::print_info();
    std::cout << "Sides: a=" << sideA << " b=" << sideB << " c=" << sideC << " d=" << sideD << std::endl;
    std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << std::endl;
}