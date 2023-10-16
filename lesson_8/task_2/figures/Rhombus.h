#ifndef TASK_3_RHOMBUS_H
#define TASK_3_RHOMBUS_H

#include "Quadrangle.h"

class Rhombus : public Quadrangle {
public:
    Rhombus(double a, double angleA, double angleB);
    bool check() const override;
};

#endif //TASK_3_RHOMBUS_H