#pragma once

class Track {
private:
    double distance{};
public:
    Track();

    void setDistance(double newDistance);
    double getDistance() const;
};
