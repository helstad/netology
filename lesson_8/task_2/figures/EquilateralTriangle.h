#ifndef TASK_3_EQUILATERALTRIANGLE_H
#define TASK_3_EQUILATERALTRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a);
    bool check() const override;
};

#endif //TASK_3_EQUILATERALTRIANGLE_H