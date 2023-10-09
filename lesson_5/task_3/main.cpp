#include <iostream>
#include <string>
#include <valarray>

class Figure {
protected:
    std::string name = "Figure";
    int sides{};

public:
    Figure() = default;

    Figure(const std::string &figureName, int countSides) : name(figureName), sides(countSides) {}

    virtual void print_info() const {
        std::cout << "- " << name << ":" << std::endl;
        std::cout << "Count sides: " << sides << std::endl;
    }

    virtual bool check() const {
        return sides == 0;
    }
};

class Triangle : public Figure {
protected:
    double sideA, sideB, sideC;
    double angleA{}, angleB{}, angleC{};

public:
    Triangle(double a, double b, double c, double A, double B, double C)
            : Figure("Triangle", 3), sideA(a), sideB(b), sideC(c), angleA(A), angleB(B), angleC(C) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Sides: a=" << sideA << " b=" << sideB << " c=" << sideC << std::endl;
        std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << std::endl;
    }

    bool check() const override {
        return sides == 3 && (angleA + angleB + angleC == 180);
    }
};

class RightAngledTriangle : public Triangle {
public:
    RightAngledTriangle(double a, double b) : Triangle(a, b, sqrt(a * a + b * b), 90, atan(b / a) * 180 / M_PI,
                                                       90) {
        name = "Right Angled Triangle";
    }

    bool check() const override {
        return sides == 3 && (angleA + angleB + angleC == 180) && (angleC == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double angle) : Triangle(a, a, 2 * a * sin(angle / 2), angle, angle, 180 - 2 * angle) {
        name = "Isosceles Triangle";
    }

    bool check() const override {
        return sides == 3 && (angleA + angleB + angleC == 180) && (sideA == sideC) && (angleA == angleC);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        name = "Equilateral Triangle";
    }

    bool check() const override {
        return sides == 3 && (angleA + angleB + angleC == 180) && (sideA == sideB) && (sideB == sideC) &&
               (angleA == angleB) && (angleB == angleC);
    }
};

class Quadrangle : public Figure {
protected:
    double sideA, sideB, sideC, sideD;
    double angleA, angleB, angleC, angleD;

public:
    Quadrangle(double a, double b, double c, double d, double angle1, double angle2, double angle3, double angle4) :
            Figure("Quadrangle", 4), sideA(a), sideB(b), sideC(c), sideD(d), angleA(angle1), angleB(angle2),
            angleC(angle3), angleD(angle4) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "Side lengths: a=" << sideA << " b=" << sideB << " c=" << sideC << " d=" << sideD << std::endl;
        std::cout << "Angles: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << std::endl;
    }

    bool check() const override {
        return sides == 4 && (angleA + angleB + angleC + angleD == 360);
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        name = "Rectangle";
    }

    bool check() const override {
        return sides == 4 && (angleA + angleB + angleC + angleD == 360) && (angleA == 90) && (angleB == 90) &&
               (angleC == 90) && (angleD == 90);
    }
};

class Square : public Quadrangle {
public:
    Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        name = "Square";
    }

    bool check() const override {
        return sides == 4 && (angleA + angleB + angleC + angleD == 360) && (angleA == 90) && (angleB == 90) &&
               (angleC == 90) && (angleD == 90) && (sideA == sideB) && (sideB == sideC) && (sideC == sideD);
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double angleA, double angleB) : Quadrangle(a, b, a, b, angleA, angleB, angleA,
                                                                                 angleB) {
        name = "Parallelogram";
    }

    bool check() const override {
        return sides == 4 && (angleA + angleB + angleC + angleD == 360) && (sideA == sideC) && (sideB == sideD) &&
               (angleA == angleC) && (angleB == angleD);
    }
};

class Rhombus : public Quadrangle {
public:
    Rhombus(double a, double angleA) : Quadrangle(a, a, a, a, angleA, 180 - angleA, angleA, 180 - angleA) {
        name = "Rhombus";
    }

    bool check() const override {
        return sides == 4 && (angleA + angleB + angleC + angleD == 360) && (sideA == sideB) && (sideB == sideC) &&
               (sideC == sideD) && (angleA == angleC) && (angleB == angleD);
    }
};


int main() {
    Figure figure;
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightAngledTriangle rightAngledTriangle(10, 20);
    IsoscelesTriangle isoscelesTriangle(10, 50);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30);

    Figure *figures[] = {
            &figure, &triangle, &rightAngledTriangle, &isoscelesTriangle, &equilateralTriangle, &quadrangle, &rectangle,
            &square, &parallelogram, &rhombus
    };

    for (const auto &fig: figures) {
        fig->print_info();
        std::cout << "Correct: " << std::boolalpha << fig->check() << std::endl;
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}