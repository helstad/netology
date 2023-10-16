#ifndef TASK_3_PARALLELOGRAM_H
#define TASK_3_PARALLELOGRAM_H

#include "Quadrangle.h"

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double angleA, double angleB);
    bool check() const override;
};

#endif //TASK_3_PARALLELOGRAM_H