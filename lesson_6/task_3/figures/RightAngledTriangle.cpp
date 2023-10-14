#include "RightAngledTriangle.h"

RightAngledTriangle::RightAngledTriangle(double a, double b, double c, double angleA, double angleB)
        : Triangle(a, b, c, angleA, angleB, 90) {
    name = "RightAngledTriangle";
}