#pragma once

#include "Entity.h"

class AirEntity : public Entity {
private:
    double distanceReduction;
public:
    AirEntity(std::string entityName, double entitySpeed, double reduction);
    [[nodiscard]] double getDistanceReduction() const;
};