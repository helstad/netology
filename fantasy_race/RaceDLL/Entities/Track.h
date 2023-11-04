#pragma once

class Track {
private:
    double distance{};
public:
    Track(double distance);
    double getDistance() const;
};
