#pragma once

#include <string>

class Shape {
public:
  enum class Type { Line, Square, Cube, Circle, Cylinder };

  Shape();
  Shape(const std::initializer_list<int> &points);
  Shape(const Type &type, double r, double h);

  Type getType() const;

private:
  Type type;
  double volume;
  double square;
  double height;
  double radius;
};