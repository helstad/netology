#include "cube.hpp"
#include <cstdlib>

Cube::Cube(const std::vector<int> &coordinates) : Rectangle(coordinates) {}

double Cube::getVolume() const {
  int a = calculateSideLength(0, 6);
  int b = calculateSideLength(1, 7);
  int c = calculateSideLength(2, 8);
  return a * b * c;
}

int Cube::calculateSideLength(int index1, int index2) const {
  return std::abs(coordinates[index1] - coordinates[index2]);
}

void Cube::shift(int m, int n, int k) {
  for (int &coord : coordinates) {
    coord += (coord % 3 == 0) ? k : ((coord + 1) % 3 == 0) ? n : m;
  }
}

void Cube::scaleX(int a) {
  for (int &coord : coordinates) {
    if (coord % 3 == 0)
      coord *= a;
  }
}

void Cube::scaleY(int d) {
  for (int &coord : coordinates) {
    if ((coord + 1) % 3 == 0)
      coord *= d;
  }
}

void Cube::scaleZ(int e) {
  for (int &coord : coordinates) {
    if ((coord + 2) % 3 == 0)
      coord *= e;
  }
}

void Cube::scale(int s) {
  for (int &coord : coordinates) {
    coord /= s;
  }
}