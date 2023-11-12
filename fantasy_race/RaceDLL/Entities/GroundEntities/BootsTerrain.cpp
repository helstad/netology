#include "BootsTerrain.h"

BootsTerrain::BootsTerrain() : GroundEntity("Boots All-Terrain", 6, 60, {10, 5}) {}

double BootsTerrain::getTotalTravelTime(double distance) {
    return GroundEntity::getTotalTravelTime(distance);
}