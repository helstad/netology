#include "Track.h"

Track::Track() : distance(0) {}

void Track::setDistance(double newDistance) {
    distance = newDistance;
}
double Track::getDistance() const {
    return distance;
}