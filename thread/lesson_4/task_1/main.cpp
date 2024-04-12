#include "circle.hpp"
#include "cube.hpp"
#include "cylinder.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include <iostream>

int main() {
  Line line({0, 0, 1, 1});
  Rectangle rectangle({0, 0, 1, 1, 2, 2, 3, 3});
  Cube cube({0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5});
  Circle circle(0, 0, 5.0);
  Cylinder cylinder(0, 0, 5.0, 10.0);

  std::cout << "Line coordinates: ";
  for (int coord : line.getCoordinates()) {
    std::cout << coord << " ";
  }
  std::cout << std::endl;
  std::cout << "Rectangle square: " << rectangle.getSquare() << std::endl;
  std::cout << "Cube volume: " << cube.getVolume() << std::endl;
  std::cout << "Circle square: " << circle.getSquare() << std::endl;
  std::cout << "Cylinder volume: " << cylinder.getVolume() << std::endl;

  line.shift(1, 1, 1);
  rectangle.scaleX(2);
  cube.scale(2);
  circle.scaleY(2);
  cylinder.scaleZ(2);

  std::cout << "Shifted line coordinates: ";
  for (int coord : line.getCoordinates()) {
    std::cout << coord << " ";
  }
  std::cout << std::endl;
  std::cout << "Scaled rectangle square: " << rectangle.getSquare()
            << std::endl;
  std::cout << "Scaled cube volume: " << cube.getVolume() << std::endl;
  std::cout << "Scaled circle square: " << circle.getSquare() << std::endl;
  std::cout << "Scaled cylinder volume: " << cylinder.getVolume() << std::endl;

  return 0;
}
