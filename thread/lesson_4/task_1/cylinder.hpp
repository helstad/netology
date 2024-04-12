#pragma once

#include "circle.hpp"
#include <vector>

class Cylinder : public Circle {
public:
  Cylinder(int x, int y, double R, double H);
  Type getType() const override { return Type::cylinder; };
  double getVolume() const override;
  double getSquare() const override;
  double getHeight() const { return height; }

  void shift(int m, int n, int k) override;
  void scaleX(int a) override;
  void scaleY(int d) override;
  void scaleZ(int e) override;
  void scale(int s) override;

  const std::vector<int> &getCoordinates() const override;

private:
  double height;
  std::vector<int> coordinates;
};