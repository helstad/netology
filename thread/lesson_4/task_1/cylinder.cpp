#include "cylinder.hpp"
#include "circle.hpp"
#include <cmath>

Cylinder::Cylinder(int x, int y, double R, double H)
    : Circle(x, y, R), height(H), coordinates({x, y}) {}

double Cylinder::getVolume() const {
  double R = getRadius();
  return M_PI * R * R * height;
}

double Cylinder::getSquare() const {
  double R = getRadius();
  return 2 * M_PI * R * (R + height);
}

void Cylinder::shift(int m, int n, int k) {
  coordinates[0] += m;
  coordinates[1] += n;
  height += k;
}

void Cylinder::scaleX(int a) { Circle::scaleX(a); }

void Cylinder::scaleY(int d) { Circle::scaleY(d); }

void Cylinder::scaleZ(int e) { height *= e; }

void Cylinder::scale(int s) {
  Circle::scale(s);
  height *= s * s;
}

const std::vector<int> &Cylinder::getCoordinates() const {
  return Circle::getCoordinates();
}