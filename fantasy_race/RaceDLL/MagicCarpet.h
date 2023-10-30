#pragma once

#include "AirEntity.h"

class MagicCarpet : public AirEntity {
public:
    MagicCarpet();
    [[nodiscard]] double getDistanceReduction(double distance) const override;
};
