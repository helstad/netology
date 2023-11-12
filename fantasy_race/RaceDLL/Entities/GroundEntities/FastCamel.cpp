#include "FastCamel.h"

FastCamel::FastCamel() : GroundEntity("Fast Camel", 40, 10, {5, 6.5, 8}) {}

double FastCamel::getTotalTravelTime(double distance) {
    return GroundEntity::getTotalTravelTime(distance);
}