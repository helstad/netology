#pragma once

#include "AirEntity.h"

class Broomstick : public AirEntity {
private:
    [[nodiscard]] double getDistanceReduction(double distance) override;
public:
    Broomstick();
};