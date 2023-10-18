#include "Rhombus.h"
#include "../exception/GeometryError.h"

Rhombus::Rhombus(double a, double angleA, double angleB)
        : Quadrangle("Rhombus", a, a, a, a, angleA, angleB, angleA, angleB) {
    if (sideA != sideB || sideA != sideC || sideA != sideD) {
        throw GeometryError(name,"All sides must equal.");
    }
    if (angleA != angleC || angleB != angleD) {
        throw GeometryError(name,"A rhombus must have opposite angles equal.");
    }
}