#include "Parallelogram.h"
#include "../exception/GeometryError.h"

Parallelogram::Parallelogram(double a, double b, double angleA, double angleB)
        : Quadrangle(a, b, a, b, angleA, angleB, angleA, angleB) {
    name = "Parallelogram";
}

bool Parallelogram::check() const {
    Quadrangle::check();
    if (sideA != sideC || sideB != sideD) {
        throw GeometryError("A parallelogram must have opposite sides equal.");
    }
    if (angleA != angleC || angleB != angleD) {
        throw GeometryError("A parallelogram must have opposite angles equal.");
    }

    return true;
}