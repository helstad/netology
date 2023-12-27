#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirEntity("Magic Carpet", 10) {}

double MagicCarpet::getDistanceReduction(double distance) {
    const double MIN_DISTANCE = 1000;
    const double MEDIUM_DISTANCE = 5000;
    const double MAX_DISTANCE = 10000;

    const double COEFFICIENT_1 = 0.97;
    const double COEFFICIENT_2 = 0.9;
    const double COEFFICIENT_3 = 0.95;

    if (distance < MIN_DISTANCE) {
        return distance;
    } else if (distance < MEDIUM_DISTANCE) {
        return distance * COEFFICIENT_1;
    } else if (distance < MAX_DISTANCE) {
        return distance * COEFFICIENT_2;
    } else {
        return distance * COEFFICIENT_3;
    }
}