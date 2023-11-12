#pragma once

#include "AirEntity.h"

class Eagle : public AirEntity {
private:
    [[nodiscard]] double getDistanceReduction(double distance) override;
public:
    Eagle();
};
