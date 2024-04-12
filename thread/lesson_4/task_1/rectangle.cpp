#include "rectangle.hpp"
#include <cstdlib>

Rectangle::Rectangle(const std::vector<int> &coordinates) : Line(coordinates) {}

double Rectangle::getSquare() const {
  int a = calculateSideLength(0, 2);
  int b = calculateSideLength(1, 3);
  return a * b;
}

int Rectangle::calculateSideLength(int index1, int index2) const {
  return std::abs(coordinates[index1] - coordinates[index2]);
}

void Rectangle::shift(int m, int n, int k) {
  for (int &coord : coordinates) {
    coord += (coord % 2 == 0) ? m : ((coord + 1) % 3 == 0) ? n : k;
  }
}

void Rectangle::scaleX(int a) {
  for (int &coord : coordinates) {
    if (coord % 2 == 0)
      coord *= a;
  }
}

void Rectangle::scaleY(int d) {
  for (int &coord : coordinates) {
    if ((coord + 1) % 3 == 0)
      coord *= d;
  }
}

void Rectangle::scaleZ(int e) {}

void Rectangle::scale(int s) {}