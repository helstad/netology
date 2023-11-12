#include "Entity.h"

Entity::Entity(std::string entityName, double entitySpeed)
        : name(std::move(entityName)), speed(entitySpeed) {}

std::string Entity::getName() const { return name; }

double Entity::getSpeed() const { return speed; }

//double Entity::getTotalTravelTime(double distance) {
//    return 0;
//}