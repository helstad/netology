#pragma once

class Track {
private:
    double distance{};
public:
    explicit Track(double distance);
    double getDistance() const;
    void setDistance(double newTrackDistance);
};
