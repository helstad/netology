#include <cmath>
#include "AirEntity.h"

AirEntity::AirEntity(std::string entityName, double entitySpeed)
        : Entity(std::move(entityName), entitySpeed) {}

double AirEntity::AroundToTwoDecimalPlaces(double num) {
    return std::round(num * 100.0) / 100.0;
}

double AirEntity::getTotalTravelTime(double distance) {
    double reducedDistance = getDistanceReduction(distance);
    return AroundToTwoDecimalPlaces(reducedDistance / getSpeed());
}

