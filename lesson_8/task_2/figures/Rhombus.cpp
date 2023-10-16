#include "Rhombus.h"
#include "../exception/GeometryError.h"

Rhombus::Rhombus(double a, double angleA, double angleB)
        : Quadrangle(a, a, a, a, angleA, angleB, angleA, angleB) {
    name = "Rhombus";
}

bool Rhombus::check() const {
    Quadrangle::check();
    if (sideA != sideB || sideA != sideC || sideA != sideD) {
        throw GeometryError("A rhombus must have all sides equal.");
    }
    if (angleA != angleC || angleB != angleD) {
        throw GeometryError("A rhombus must have opposite angles equal.");
    }

    return true;
}