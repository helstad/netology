#pragma once

#include "../Entity.h"
#include <vector>

class GroundEntity : public Entity {
private:
    double travelTimeToRest{};
    std::vector<double> restDurations;
    int currentRestIndex{};
    void incrementRestIndex();
public:
    GroundEntity(std::string entityName, double entitySpeed, double travelTime,
                 const std::vector<double> &restDurations);

    [[nodiscard]] virtual double getTravelTimeToRest() const;

    [[nodiscard]] virtual double getRestDuration() const;

    [[nodiscard]] double getTotalTravelTime(double distance) override;
};
