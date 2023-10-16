#include "RightAngledTriangle.h"
#include "../exception/GeometryError.h"

RightAngledTriangle::RightAngledTriangle(double a, double b, double c, double angleA, double angleB)
        : Triangle(a, b, c, angleA, angleB, 90) {
    name = "RightAngledTriangle";
}

bool RightAngledTriangle::check() const {
    Triangle::check();
    if (angleC != 90) {
        throw GeometryError("Angle C is not equal to 90.");
    }
    return true;
}