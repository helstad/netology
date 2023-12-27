#pragma once
#include "GroundEntity.h"

class FastCamel : public GroundEntity {
public:
    FastCamel();

    double getTotalTravelTime(double distance);
};
