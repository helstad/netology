#include <iostream>
#include <string>

#include "Figures.h"
#include "exception/GeometryError.h"

void printSuccessFigure(Figure *figure) {
    figure->print_info();
    std::cout << std::endl;
}

int main() {
    const int figure_count = 9;
    Figure *figures[figure_count] = {nullptr};

    try {
        figures[0] = new Triangle(10, 20, 30, 50, 60, 70);
        printSuccessFigure(figures[0]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[1] = new RightAngledTriangle(10, 20, 30, 30, 60);
        printSuccessFigure(figures[1]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[2] = new IsoscelesTriangle(10, 20, 50, 80);
        printSuccessFigure(figures[2]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[3] = new EquilateralTriangle(30);
        printSuccessFigure(figures[3]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[4] = new Quadrangle(30, 30, 30, 30, 90, 90, 90, 90);
        printSuccessFigure(figures[4]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[5] = new Rectangle(10, 20);
        printSuccessFigure(figures[5]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[6] = new Square(20);
        printSuccessFigure(figures[6]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[7] = new Parallelogram(20, 30, 90, 90);
        printSuccessFigure(figures[7]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        figures[8] = new Rhombus(20, 30, 4011);
        printSuccessFigure(figures[8]);
    } catch (const GeometryError &e) {
        std::cout << e.what() << std::endl;
    }

    for (const auto &fig: figures) {
        delete fig;
    }

    return EXIT_SUCCESS;
}