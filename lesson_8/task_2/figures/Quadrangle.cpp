#include "Quadrangle.h"
#include "../exception/GeometryError.h"

Quadrangle::Quadrangle(const std::string& name, double a, double b, double c, double d, double angle1, double angle2, double angle3,
                       double angle4)
        : Figure(name), sideA(a), sideB(b), sideC(c), sideD(d), angleA(angle1), angleB(angle2), angleC(angle3),
          angleD(angle4) {
    if (angleA + angleB + angleC + angleD != 360) {
        throw GeometryError(name,"Sum of angles is not equal to 360.");
    }
}

Quadrangle::Quadrangle(double a, double b, double c, double d, double angle1, double angle2, double angle3,
                       double angle4)
        : Figure("Quadrangle"), sideA(a), sideB(b), sideC(c), sideD(d), angleA(angle1), angleB(angle2), angleC(angle3),
          angleD(angle4) {
    if (angleA + angleB + angleC + angleD != 360) {
        throw GeometryError(name,"Sum of angles is not equal to 360.");
    }
}

void Quadrangle::print_info() const {
    Figure::print_info();
    std::cout << "sides: " << sideA << ", " << sideB << ", " << sideC << ", " << sideD << "\nangle: " << angleA << ", "
              << angleB << ", " << angleC << ", " << angleD << "\n- Being created" << std::endl;
}