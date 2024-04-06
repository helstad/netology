#pragma once
#include <string>
#include <vector>

class Shape {
public:
  enum class Type { line, sqr, cube, circle, cylinder };

  Shape(Type type, const std::vector<int> &coordinates);
  Shape(Type type, int x1, int y1, double R, double H);

  Type getType() const { return type; };
  double getVolume() const { return volume; };
  double getSquare() const { return square; };
  const std::vector<int> &getCoordinates() const { return coordinates; }

private:
  Type type;
  std::vector<int> coordinates;
  double volume;
  double square;

  void calculateVolumeAndSquare();
};