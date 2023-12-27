#ifndef TASK_3_TRIANGLE_H
#define TASK_3_TRIANGLE_H

#include "Figure.h"
#include "ExportImport.h"

class FIGURES_API Triangle : public Figure {
protected:
    double sideA, sideB, sideC;
    double angleA, angleB, angleC;

public:
    Triangle(double a, double b, double c, double angleA, double angleB, double angleC);
    void print_info() const override;
};

#endif //TASK_3_TRIANGLE_H
