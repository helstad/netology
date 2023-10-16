#include <iostream>
#include <string>

#include "Figures.h"
#include "exception/GeometryError.h"

int main() {
    try {
        Triangle triangle(10, 20, 30, 50, 60, 70);
        RightAngledTriangle rightAngledTriangle(10, 20, 30, 30, 60);
        IsoscelesTriangle isoscelesTriangle(10, 20, 50, 80);
        EquilateralTriangle equilateralTriangle(30);
        Quadrangle quadrangle(30, 30, 30, 30, 90, 90, 90, 90);
        Rectangle rectangle(10, 20);
        Square square(20);
        Parallelogram parallelogram(20, 30, 90, 90);
        Rhombus rhombus(20, 30, 40);

        Figure *figures[] = {
                &triangle, &rightAngledTriangle, &isoscelesTriangle, &equilateralTriangle, &quadrangle, &rectangle,
                &square, &parallelogram, &rhombus};

        for (const auto &fig: figures) {
            fig->print_info();
            fig->check();
            std::cout << std::endl;
        }

    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}