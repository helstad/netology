#include "RightAngledTriangle.h"
#include "../exception/GeometryError.h"

RightAngledTriangle::RightAngledTriangle(double a, double b, double c, double angleA, double angleB)
        : Triangle("RightAngledTriangle", a, b, c, angleA, angleB, 90) {
    if (angleC != 90) {
        throw GeometryError(name, "Angle C is not equal to 90.");
    }
}