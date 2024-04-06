#include "transform.h"

Transform::Transform(const Shape &sh) : shape(sh) {}

Shape Transform::shift(int m, int n, int k) {
  std::vector<int> newCoordinates = shape.getCoordinates();
  for (int i = 0; i < newCoordinates.size(); i += 3) {
    newCoordinates[i] += m;
    newCoordinates[i + 1] += n;
    newCoordinates[i + 2] += k;
  }
  return Shape(shape.getType(), newCoordinates);
}

Shape Transform::scaleX(int a) {
  std::vector<int> newCoordinates = shape.getCoordinates();
  for (int i = 0; i < newCoordinates.size(); i += 3) {
    newCoordinates[i] *= a;
  }
  return Shape(shape.getType(), newCoordinates);
}

Shape Transform::scaleY(int d) {
  std::vector<int> newCoordinates = shape.getCoordinates();
  for (int i = 1; i < newCoordinates.size(); i += 3) {
    newCoordinates[i] *= d;
  }
  return Shape(shape.getType(), newCoordinates);
}

Shape Transform::scaleZ(int e) {
  std::vector<int> newCoordinates = shape.getCoordinates();
  for (int i = 2; i < newCoordinates.size(); i += 3) {
    newCoordinates[i] *= e;
  }
  return Shape(shape.getType(), newCoordinates);
}

Shape Transform::scale(int s) {
  std::vector<int> newCoordinates = shape.getCoordinates();
  for (int i = 0; i < newCoordinates.size(); ++i) {
    newCoordinates[i] /= s;
  }
  return Shape(shape.getType(), newCoordinates);
}