#ifndef TASK_3_RECTANGLE_H
#define TASK_3_RECTANGLE_H

#include "Quadrangle.h"

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b);
    bool check() const override;
};

#endif //TASK_3_RECTANGLE_H