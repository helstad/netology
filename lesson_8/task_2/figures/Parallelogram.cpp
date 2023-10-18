#include "Parallelogram.h"
#include "../exception/GeometryError.h"

Parallelogram::Parallelogram(double a, double b, double angleA, double angleB)
        : Quadrangle("Parallelogram", a, b, a, b, angleA, angleB, angleA, angleB) {
    if (sideA != sideC || sideB != sideD) {
        throw GeometryError(name,"A parallelogram must have opposite sides equal.");
    }
    if (angleA != angleC || angleB != angleD) {
        throw GeometryError(name,"A parallelogram must have opposite angles equal.");
    }
}