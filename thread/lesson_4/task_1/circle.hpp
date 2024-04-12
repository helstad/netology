#pragma once

#include "shape.hpp"

class Circle : public Shape {
public:
  Circle(int x, int y, double R);
  Type getType() const override { return Type::circle; };
  double getVolume() const override { return 0.0; };
  double getSquare() const override;
  double getRadius() const { return coordinates[2]; }

  const std::vector<int> &getCoordinates() const override {
    return coordinates;
  }

  void shift(int m, int n, int k) override;
  void scaleX(int a) override;
  void scaleY(int d) override;
  void scaleZ(int e) override;
  void scale(int s) override;

private:
  std::vector<int> coordinates;
};