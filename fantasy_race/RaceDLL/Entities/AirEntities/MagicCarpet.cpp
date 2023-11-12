#include "MagicCarpet.h"

MagicCarpet::MagicCarpet() : AirEntity("Magic Carpet", 10) {}

double MagicCarpet::getDistanceReduction(double distance) {
    if (distance < 1000) {
        return 1.0;
    } else if (distance < 5000) {
        return 0.97;
    } else if (distance < 10000) {
        return 0.9;
    } else {
        return 0.95;
    }
}