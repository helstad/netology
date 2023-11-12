#pragma once

#include <string>

class Entity {
private:
    std::string name;
    double speed{};
public:
    Entity(std::string entityName, double entitySpeed);
    virtual ~Entity() = default;
    [[nodiscard]] virtual std::string getName() const;
    [[nodiscard]] virtual double getSpeed() const;
    [[nodiscard]] virtual double getTotalTravelTime(double distance) = 0;
};