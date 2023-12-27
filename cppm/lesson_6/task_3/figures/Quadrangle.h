#ifndef TASK_3_QUADRANGLE_H
#define TASK_3_QUADRANGLE_H

#include "Figure.h"

class Quadrangle : public Figure {
protected:
    double sideA, sideB, sideC, sideD;
    double angleA, angleB, angleC, angleD;

public:
    Quadrangle(double a, double b, double c, double d, double angle1, double angle2, double angle3, double angle4);
    void print_info() const override;
};

#endif //TASK_3_QUADRANGLE_H