#include "IsoscelesTriangle.h"
#include "../exception/GeometryError.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double angleA, double angleB)
        : Triangle("IsoscelesTriangle", a, b, a, angleA, angleB, angleA) {
    if (sideA != sideC) {
        throw GeometryError(name,"Sides A and C should be equal");
    }
    if (angleA != angleC) {
        throw GeometryError(name,"Angle A and C should be equal");
    }
}

