#include "AirEntity.h"

AirEntity::AirEntity(std::string entityName, double entitySpeed)
        : Entity(std::move(entityName), entitySpeed) {}