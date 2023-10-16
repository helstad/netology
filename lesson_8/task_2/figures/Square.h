#ifndef TASK_3_SQUARE_H
#define TASK_3_SQUARE_H

#include "Quadrangle.h"

class Square : public Quadrangle {
public:
    Square(double a);
    bool check() const override;
};

#endif //TASK_3_SQUARE_H