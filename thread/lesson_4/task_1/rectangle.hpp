#pragma once

#include "line.hpp"

class Rectangle : public Line {
public:
  Rectangle(const std::vector<int> &coordinates);
  Type getType() const override { return Type::rectangle; };
  double getSquare() const override;

  void shift(int m, int n, int k) override;
  void scaleX(int a) override;
  void scaleY(int d) override;
  void scaleZ(int e) override;
  void scale(int s) override;

protected:
  int calculateSideLength(int index1, int index2) const;
};