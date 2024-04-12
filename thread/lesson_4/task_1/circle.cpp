#include "circle.hpp"
#include <cmath>

Circle::Circle(int x, int y, double R)
    : coordinates({x, y, static_cast<int>(R)}) {}

double Circle::getSquare() const {
  double R = coordinates[2];
  return M_PI * R * R;
}

void Circle::shift(int m, int n, int k) {}

void Circle::scaleX(int a) {
  for (int &coord : coordinates) {
    if (coord % 2 == 0)
      coord *= a;
  }
}

void Circle::scaleY(int d) {
  for (int &coord : coordinates) {
    if ((coord + 1) % 3 == 0)
      coord *= d;
  }
}

void Circle::scaleZ(int e) {}

void Circle::scale(int s) {
  for (int &coord : coordinates) {
    coord /= s;
  }
}