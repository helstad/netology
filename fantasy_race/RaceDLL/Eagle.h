#pragma once

#include "AirEntity.h"

class Eagle : public AirEntity {
    Eagle();
    double getDistanceReduction(double distance) const override;
};
