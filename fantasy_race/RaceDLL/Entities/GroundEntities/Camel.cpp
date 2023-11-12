#include "Camel.h"

Camel::Camel() : GroundEntity("Camel", 10, 30, {5, 8}) {}

double Camel::getTotalTravelTime(double distance) {
    return GroundEntity::getTotalTravelTime(distance);
}