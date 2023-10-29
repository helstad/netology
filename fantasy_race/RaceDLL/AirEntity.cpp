#include "AirEntity.h"

AirEntity::AirEntity(std::string entityName, double entitySpeed, double reduction)
        : Entity(std::move(entityName), entitySpeed), distanceReduction(reduction) {}

double AirEntity::getDistanceReduction() const { return distanceReduction; }