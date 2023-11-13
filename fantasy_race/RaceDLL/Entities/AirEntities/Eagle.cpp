#include "Eagle.h"

Eagle::Eagle() : AirEntity("Eagle", 8) {}

double Eagle::getDistanceReduction(double distance) {
    const double COEFFICIENT = 0.94;

    return COEFFICIENT * distance;
}