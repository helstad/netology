#pragma once
#include "GroundEntity.h"

class Centaur : public GroundEntity {
public:
    Centaur();

    double getTotalTravelTime(double distance);
};
