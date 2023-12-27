#include "GroundEntity.h"

GroundEntity::GroundEntity(std::string entityName, double entitySpeed, double travelTime,
                           const std::vector<double> &restDurations)
        : Entity(std::move(entityName), entitySpeed), travelTimeToRest(travelTime), restDurations(restDurations), currentRestIndex(0) {}

double GroundEntity::getTravelTimeToRest() const { return travelTimeToRest; }

double GroundEntity::getRestDuration() const {
    if (currentRestIndex < restDurations.size()) {
        return restDurations[currentRestIndex];
    } else {
        return restDurations.back();
    }
}

double GroundEntity::getTotalTravelTime(double distance) {
    double totalTime = 0.0;

    while (distance > (getSpeed() * travelTimeToRest)) {
        totalTime += travelTimeToRest;
        distance -= getSpeed() * travelTimeToRest;

        totalTime += getRestDuration();
        incrementRestIndex();
    }

    totalTime += distance / getSpeed();

    return totalTime;
}

void GroundEntity::incrementRestIndex() {
    ++currentRestIndex;
}
