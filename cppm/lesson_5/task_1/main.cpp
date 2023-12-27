#include <iostream>
#include <string>

class Figure {
protected:
    int sides_count = 0;
    std::string name;

public:
    Figure(int sides = 0) : sides_count(sides), name("Figure") {}

    void print_info() const { std::cout << name << " have " << sides_count << " sides " << std::endl; }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) { name = "Triangle"; }
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) { name = "Quadrangle"; }
};

int main() {
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    figure.print_info();
    triangle.print_info();
    quadrangle.print_info();

    return EXIT_SUCCESS;
}