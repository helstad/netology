#include "IsoscelesTriangle.h"
#include "../exception/GeometryError.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double angleA, double angleB)
        : Triangle(a, b, a, angleA, angleB, angleA) { name = "IsoscelesTriangle"; }


bool IsoscelesTriangle::check() const {
    Triangle::check();
    if (sideA != sideC) {
        throw GeometryError("Sides A and C should be equal");
    }
    if (angleA != angleC) {
        throw GeometryError("Angle A and C should be equal");
    }

    return true;
}