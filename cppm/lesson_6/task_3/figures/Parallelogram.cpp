#include "Parallelogram.h"

Parallelogram::Parallelogram(double a, double b, double angleA, double angleB)
        : Quadrangle(a, b, a, b, angleA, angleB, angleA, angleB) {
    name = "Parallelogram";
}