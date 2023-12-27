#pragma once

#include "GroundEntity.h"

class Camel : public GroundEntity {
public:
    Camel();
    double getTotalTravelTime(double distance) override;
};
