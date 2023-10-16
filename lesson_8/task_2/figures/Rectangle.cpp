#include "Rectangle.h"
#include "../exception/GeometryError.h"

Rectangle::Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
    name = "Rectangle";
}

bool Rectangle::check() const {
    Quadrangle::check();

    if (sideA != sideC) { throw GeometryError("Side A and Side C should be equals"); }
    if (sideB != sideD) { throw GeometryError("Side B and Side D should be equals"); }
    if (angleA != 90) { throw GeometryError("Angle A is not equal to 90"); }
    if (angleB != 90) { throw GeometryError("Angle B is not equal to 90"); }
    if (angleC != 90) { throw GeometryError("Angle C is not equal to 90"); }
    if (angleD != 90) { throw GeometryError("Angle D is not equal to 90"); }

    return true;
}