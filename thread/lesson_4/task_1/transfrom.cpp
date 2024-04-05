#include "transform.h"

transform::transform(const Shape &sh) { shape = sh; }

Shape transform::shift(int m, int n, int k) {
  int *coords[] = {&shape.x1, &shape.y1, &shape.z1, &shape.x2, &shape.y2,
                   &shape.z2, &shape.x3, &shape.y3, &shape.z3, &shape.x4,
                   &shape.y4, &shape.z4, &shape.x5, &shape.y5, &shape.z5,
                   &shape.x6, &shape.y6, &shape.z6, &shape.x7, &shape.y7,
                   &shape.z7, &shape.x8, &shape.y8, &shape.z8};
  for (int i = 0; i < 24; i++)
    *coords[i] += (i % 3 == 0) ? m : (i % 3 == 1) ? n : k;
  return shape;
}

Shape transform::scaleX(int a) {
  int *coords[] = {&shape.x1, &shape.x2, &shape.x3, &shape.x4,
                   &shape.x5, &shape.x6, &shape.x7, &shape.x8};
  for (int i = 0; i < 8; i++)
    *coords[i] *= a;
  return shape;
}

Shape transform::scaleY(int d) {
  int *coords[] = {&shape.y1, &shape.y2, &shape.y3, &shape.y4,
                   &shape.y5, &shape.y6, &shape.y7, &shape.y8};
  for (int i = 0; i < 8; i++)
    *coords[i] *= d;
  return shape;
}

Shape transform::scaleZ(int e) {
  int *coords[] = {&shape.z1, &shape.z2, &shape.z3, &shape.z4,
                   &shape.z5, &shape.z6, &shape.z7, &shape.z8};
  for (int i = 0; i < 8; i++)
    *coords[i] *= e;
  return shape;
}

Shape transform::scale(int s) {
  int *coords[9] = {&shape.x1, &shape.y1, &shape.z1, &shape.x2, &shape.y2,
                    &shape.z2, &shape.x3, &shape.y3, &shape.z3};
  switch (shape.getType()) {
  case Shape::line:
    coords[2] = coords[1] + 2;
    break;
  case Shape::sqr:
    coords[6] = coords[4] + 2;
    coords[7] = coords[5] + 2;
    coords[8] = coords[6] + 2;
    break;
  case Shape::cube:
    coords[6] = coords[4] + 3;
    coords[7] = coords[5] + 3;
    coords[8] = coords[6] + 3;
    break;
  }
  for (int i = 0; i < (shape.getType() == Shape::line ? 4 : 9); i++)
    *coords[i] /= s;

  return shape;
}