#include "Eagle.h"

Eagle::Eagle() : AirEntity("Eagle", 8) {}

double Eagle::getDistanceReduction(double distance) {
    return 0.94;
}