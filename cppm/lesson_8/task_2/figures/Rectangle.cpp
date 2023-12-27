#include "Rectangle.h"
#include "../exception/GeometryError.h"

Rectangle::Rectangle(double a, double b) : Quadrangle("Rectangle", a, b, a, b, 90, 90, 90, 90) {
    if (sideA != sideC) { throw GeometryError(name,"Side A and Side C must be equals"); }
    if (sideB != sideD) { throw GeometryError(name,"Side B and Side D must be equals"); }
    if (angleA != 90) { throw GeometryError(name,"Angle A is not equal to 90"); }
    if (angleB != 90) { throw GeometryError(name,"Angle B is not equal to 90"); }
    if (angleC != 90) { throw GeometryError(name,"Angle C is not equal to 90"); }
    if (angleD != 90) { throw GeometryError(name,"Angle D is not equal to 90"); }
}