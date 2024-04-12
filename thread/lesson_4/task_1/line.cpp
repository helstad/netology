#include "line.hpp"

Line::Line(const std::vector<int> &coordinates) : coordinates(coordinates) {}

void Line::shift(int m, int n, int k) {
  for (int &coord : coordinates) {
    coord += (coord % 2 == 0) ? m : ((coord + 1) % 3 == 0) ? n : k;
  }
}

void Line::scaleX(int a) {
  for (int &coord : coordinates) {
    if (coord % 2 == 0)
      coord *= a;
  }
}

void Line::scaleY(int d) {
  for (int &coord : coordinates) {
    if ((coord + 1) % 3 == 0)
      coord *= d;
  }
}

void Line::scaleZ(int e) {}

void Line::scale(int s) {}