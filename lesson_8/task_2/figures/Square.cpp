#include "Square.h"
#include "../exception/GeometryError.h"

Square::Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
    name = "Square";
}

bool Square::check() const {
    Quadrangle::check();
    if (sideA != sideB || sideC != sideD || sideA != sideC || sideB != sideD) {
        throw GeometryError("A rectangle must have all sides equal.");
    }

    if (angleA != 90 || angleB != 90 || angleC != 90 || angleD != 90) {
        throw GeometryError("A rectangle must have all angles equal to 90 degrees.");
    }

    return true;
}