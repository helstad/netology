#pragma once

#include "Entity.h"
#include <vector>

class GroundEntity : public Entity {
private:
    double travelTimeToRest{};
    std::vector<double> restDurations;
    int currentRestIndex{};
public:
    GroundEntity(std::string entityName, double entitySpeed, double travelTime,
                 const std::vector<double> &restDurations);

    [[nodiscard]] double getTravelTimeToRest() const;

    [[nodiscard]] double getRestDuration() const;
};
