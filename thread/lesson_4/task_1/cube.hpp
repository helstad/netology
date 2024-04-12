#pragma once

#include "rectangle.hpp"

class Cube : public Rectangle {
public:
  Cube(const std::vector<int> &coordinates);
  Type getType() const override { return Type::cube; };
  double getVolume() const override;
  void shift(int m, int n, int k) override;
  void scaleX(int a) override;
  void scaleY(int d) override;
  void scaleZ(int e) override;
  void scale(int s) override;

private:
  int calculateSideLength(int index1, int index2) const;
};