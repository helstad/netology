#pragma once

#include <vector>
#include <string>
#include "RaceDLL/GroundEntity.h"

class RaceManager {
private:
    std::vector<GroundEntity*> participants;
    std::vector<GroundEntity*> availableParticipants;
public:
    RaceManager();

    void initAvailableParticipants();
    void showAvailableParticipants();
    void registerParticipant(int choice);
    void showRegisteredParticipants();
    void startRace();
};
