#pragma once

#include <string>
#include <vector>
#include "Entities/Track.h"

class GameManager {
private:
    Track track;
    int raceType;
    std::vector<std::string> availableParticipants;
public:
    GameManager(int raceType, double distance);
    double getDistance() const;
    void registerParticipant();
    std::vector<std::string> getParticipants();
};
