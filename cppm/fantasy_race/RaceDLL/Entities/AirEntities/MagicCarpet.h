#pragma once

#include "AirEntity.h"

class MagicCarpet : public AirEntity {
private:
    [[nodiscard]] double getDistanceReduction(double distance) override;
public:
    MagicCarpet();
};
