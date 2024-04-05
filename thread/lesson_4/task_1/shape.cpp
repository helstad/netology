#include "shape.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Shape::Shape() : type(Type::Line) {}

Shape::Shape(const std::initializer_list<int> &points) : type(Type::Square) {
  // Здесь будет логика для создания многоугольника
}

Shape::Shape(const Type &type, double r, double h)
    : type(type), radius(r), height(h) {
  switch (type) {
  case Type::Circle:
    volume = 4.0 / 3.0 * M_PI * radius * radius * radius;
    break;
  case Type::Cylinder:
    volume = M_PI * radius * radius * height;
    break;
  default:
    throw std::invalid_argument("Wrong type figure");
  }
}

Shape::Type Shape::getType() const { return type; }
