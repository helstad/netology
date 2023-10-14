#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;

public:
    Figure(const std::string& figureName) : name(figureName) {}

    virtual void print_info() const {
        std::cout << name << ":" << std::endl;
    }
};

class Triangle : public Figure {
protected:
    double sideA, sideB, sideC;
    double angleA, angleB, angleC;

public:
    Triangle(double a, double b, double c, double angleA, double angleB, double angleC) :
            Figure("Triangle"), sideA(a), sideB(b), sideC(c), angleA(angleA), angleB(angleB), angleC(angleC) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Sides: a=" << sideA << " b=" << sideB << " c=" << sideC << std::endl;
        std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << std::endl;
    }
};

class RightAngledTriangle : public Triangle {
public:
    RightAngledTriangle(double a, double b, double c, double angleA, double angleB) : Triangle(a, b, c, angleA, angleB, 90) {
        name = "RightAngledTriangle";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double angleA, double angleB) : Triangle(a, b, a, angleA, angleB, angleA) {
        name = "IsoscelesTriangle";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        name = "EquilateralTriangle";
    }
};

class Quadrangle : public Figure {
protected:
    double sideA, sideB, sideC, sideD;
    double angleA, angleB, angleC, angleD;

public:
    Quadrangle(double a, double b, double c, double d, double angle1, double angle2, double angle3, double angle4) :
            Figure("Quadrangle"), sideA(a), sideB(b), sideC(c), sideD(d), angleA(angle1), angleB(angle2), angleC(angle3), angleD(angle4) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Sides: a=" << sideA << " b=" << sideB << " c=" << sideC << " d=" << sideD << std::endl;
        std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << std::endl;
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Rectangle";
    }
};

class Square : public Quadrangle {
public:
    Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        name = "Square";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double angleA, double angleB) : Quadrangle(a, b, a, b, angleA, angleB, angleA, angleB) {
        name = "Parallelogram";
    }
};

class Rhombus : public Quadrangle {
public:
    Rhombus(double a, double angleA, double angleB) : Quadrangle(a, a, a, a, angleA, angleB, angleA, angleB) {
        name = "Rhombus";
    }
};

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