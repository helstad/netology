#include "Broomstick.h"

Broomstick::Broomstick() : AirEntity("Broomstick", 20) {}

double Broomstick::getDistanceReduction(double distance) {
    const double COEFFICIENT = 0.01;

    return distance * (1.0 - COEFFICIENT * (static_cast<int>(distance) / 1000));
}