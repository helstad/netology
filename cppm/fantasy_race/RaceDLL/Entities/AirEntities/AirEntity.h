#pragma once

#include "../Entity.h"
#include <vector>

class AirEntity : public Entity {
private:
    static double AroundToTwoDecimalPlaces(double num);

    [[nodiscard]] virtual double getDistanceReduction(double distance) = 0;

public:
    AirEntity(std::string entityName, double entitySpeed);

    double getTotalTravelTime(double distance) override;
};