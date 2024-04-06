#include "shape.h"
#include <cmath>
#include <cstdlib>
#include <vector>

Shape::Shape(Type type, const std::vector<int> &coordinates)
    : type(type), coordinates(coordinates) {
  calculateVolumeAndSquare();
}

Shape::Shape(Type type, int x1, int y1, double R, double H)
    : type(type), coordinates({x1, y1}), volume(0.0), square(0.0) {
  if (type == Type::circle) {
    coordinates.push_back(static_cast<int>(R));
  } else if (type == Type::cylinder) {
    coordinates.push_back(static_cast<int>(R));
    coordinates.push_back(static_cast<int>(H));
  }
  calculateVolumeAndSquare();
}

void Shape::calculateVolumeAndSquare() {
  int size = coordinates.size();
  if (type == Type::line) {
    volume = 0.0;
    square = 0.0;
  } else if (type == Type::sqr) {
    int a = std::abs(coordinates[0] - coordinates[2]);
    int b = std::abs(coordinates[1] - coordinates[3]);
    volume = 0.0;
    square = a * b;
  } else if (type == Type::cube) {
    int a = std::abs(coordinates[0] - coordinates[6]);
    int b = std::abs(coordinates[1] - coordinates[7]);
    int c = std::abs(coordinates[2] - coordinates[8]);
    volume = a * b * c;
    square = 2 * (a * b + b * c + a * c);
  } else if (type == Type::circle) {
    double R = coordinates[2];
    square = M_PI * R * R;
    volume = 0.0;
  } else if (type == Type::cylinder) {
    double R = coordinates[2];
    double H = coordinates[3];
    square = 2 * M_PI * R * (R + H);
    volume = M_PI * R * R * H;
  }
}