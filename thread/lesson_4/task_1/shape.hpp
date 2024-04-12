#pragma once
#include <vector>

class Shape {
public:
  enum class Type { line, rectangle, cube, circle, cylinder };

  virtual ~Shape(){};

  virtual Type getType() const = 0;
  virtual double getVolume() const = 0;
  virtual double getSquare() const = 0;
  virtual const std::vector<int> &getCoordinates() const = 0;

  virtual void shift(int m, int n, int k) = 0;
  virtual void scaleX(int a) = 0;
  virtual void scaleY(int d) = 0;
  virtual void scaleZ(int e) = 0;
  virtual void scale(int s) = 0;
};