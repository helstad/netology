#include "EquilateralTriangle.h"
#include "../exception/GeometryError.h"

EquilateralTriangle::EquilateralTriangle(double a)
        : Triangle(a, a, a, 60, 60, 60) {
    name = "EquilateralTriangle";
}

bool EquilateralTriangle::check() const {
    Triangle::check();

    if (sideA != sideB || sideB != sideC || sideA != sideC) { throw GeometryError("All sides of an equilateral triangle must be equal."); }
    if (angleA != 60) { throw GeometryError("All angles of an equilateral triangle must be equal 60. Angle A != 60"); }
    if (angleB != 60) { throw GeometryError("All angles of an equilateral triangle must be equal 60. Angle B != 60"); }
    if (angleC != 60) { throw GeometryError("All angles of an equilateral triangle must be equal 60. Angle C != 60"); }

    return true;
}