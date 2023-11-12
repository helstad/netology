#include "Broomstick.h"

Broomstick::Broomstick() : AirEntity("Broomstick", 20) {}

double Broomstick::getDistanceReduction(double distance) {
    return 1.0 + 0.01 * (static_cast<int>(distance) / 1000);
}