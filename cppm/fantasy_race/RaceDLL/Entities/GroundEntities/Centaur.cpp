#include "Centaur.h"

Centaur::Centaur() : GroundEntity("Centaur", 15, 8, {2}) {}

double Centaur::getTotalTravelTime(double distance) {
    return GroundEntity::getTotalTravelTime(distance);
}