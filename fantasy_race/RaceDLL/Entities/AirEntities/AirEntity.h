#pragma once

#include "../Entity.h"
#include <vector>

class AirEntity : public Entity {
public:
    AirEntity(std::string entityName, double entitySpeed);

//    [[nodiscard]] virtual double getDistanceReduction(double distance) const = 0;
};