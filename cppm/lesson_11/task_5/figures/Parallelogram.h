#ifndef TASK_3_PARALLELOGRAM_H
#define TASK_3_PARALLELOGRAM_H

#include "Quadrangle.h"
#include "ExportImport.h"

class FIGURES_API Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double angleA, double angleB);
};

#endif //TASK_3_PARALLELOGRAM_H