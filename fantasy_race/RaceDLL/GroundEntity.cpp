#include "GroundEntity.h"

GroundEntity::GroundEntity(std::string entityName, double entitySpeed, double travelTime,
                           const std::vector<double> &restDurations)
        : Entity(std::move(entityName), entitySpeed), travelTimeToRest(travelTime), restDurations(restDurations) {}

double GroundEntity::getTravelTimeToRest() const { return travelTimeToRest; }

double GroundEntity::getRestDuration() const {
    if (currentRestIndex < restDurations.size()) {
        return restDurations[currentRestIndex];
    } else {
        return restDurations.back();
    }
}