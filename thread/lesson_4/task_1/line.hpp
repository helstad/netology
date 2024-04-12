#pragma once

#include "shape.hpp"

class Line : public Shape {
public:
  Line(const std::vector<int> &coordinates);
  Type getType() const override { return Type::line; };
  double getVolume() const override { return 0.0; };
  double getSquare() const override { return 0.0; };
  const std::vector<int> &getCoordinates() const override {
    return coordinates;
  };
  void shift(int m, int n, int k) override;
  void scaleX(int a) override;
  void scaleY(int d) override;
  void scaleZ(int e) override;
  void scale(int s) override;

protected:
  std::vector<int> coordinates;
};