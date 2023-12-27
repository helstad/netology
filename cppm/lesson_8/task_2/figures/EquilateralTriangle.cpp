#include "EquilateralTriangle.h"
#include "../exception/GeometryError.h"

EquilateralTriangle::EquilateralTriangle(double a)
        : Triangle("EquilateralTriangle", a, a, a, 60, 60, 60) {
    if (sideA != sideB || sideB != sideC || sideA != sideC) { throw GeometryError(name, "All sides must be equal."); }
    if (angleA != 60) { throw GeometryError(name, "All angles must be equal 60. Angle A != 60"); }
    if (angleB != 60) { throw GeometryError(name, "All angles must be equal 60. Angle B != 60"); }
    if (angleC != 60) { throw GeometryError(name, "All angles must be equal 60. Angle C != 60"); }
}