#include "Rhombus.h"

Rhombus::Rhombus(double a, double angleA, double angleB)
        : Quadrangle(a, a, a, a, angleA, angleB, angleA, angleB) {
    name = "Rhombus";
}