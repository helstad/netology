#include "Track.h"

Track::Track(double distance) : distance(distance) {}

double Track::getDistance() const {
    return distance;
}

void Track::setDistance(double newTrackDistance) {
    distance = newTrackDistance;
}