#ifndef TASK_3_ISOSCELESTRIANGLE_H
#define TASK_3_ISOSCELESTRIANGLE_H

#include "Triangle.h"
#include "ExportImport.h"

class FIGURES_API IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double angleA, double angleB);
};

#endif //TASK_3_ISOSCELESTRIANGLE_H