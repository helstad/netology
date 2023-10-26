#include <iostream>
#include <string>

#include "figures/Figures.h"

int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightAngledTriangle rightAngledTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(20, 30, 40);

    Figure *figures[] = {
            &triangle, &rightAngledTriangle, &isoscelesTriangle, &equilateralTriangle, &quadrangle, &rectangle,
            &square, &parallelogram, &rhombus};

    for (const auto &fig : figures)
    {
        fig->print_info();
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}