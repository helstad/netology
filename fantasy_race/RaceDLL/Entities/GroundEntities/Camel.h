#pragma once

#include "GroundEntity.h"

class Camel : public GroundEntity {
public:
    Camel();
    ~Camel() override = default;
    double getTotalTravelTime(double distance) override;
};
