#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double angleA, double angleB)
        : Triangle(a, b, a, angleA, angleB, angleA) { name = "IsoscelesTriangle"; }