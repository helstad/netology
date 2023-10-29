#pragma once

#include <string>

class Entity {
private:
    std::string name;
    double speed{};
public:
    Entity(std::string entityName, double entitySpeed);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] double getSpeed() const;
};