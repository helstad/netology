#pragma once

#include "../Entity.h"
#include <vector>

class AirEntity : public Entity {
private:
    static double AroundToTwoDecimalPlaces(double num);
public:
    AirEntity(std::string entityName, double entitySpeed);

    [[nodiscard]] virtual double getDistanceReduction(double distance) = 0;

    double getTotalTravelTime(double distance) override;


};