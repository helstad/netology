#pragma once

#include <string>
#include <vector>
#include "Entities/Track.h"
#include "Core/ParticipantRegistry.h"

class GameManager {
private:
    Track track;
    ParticipantRegistry participantRegistry;
    std::vector<std::string> availableParticipants;
    std::vector<std::string> registeredParticipants;
public:
    GameManager(int raceType, double distance);
    void registerParticipant(int choice);
    std::vector<std::string> getParticipants();
    std::vector<std::string> getRegisteredParticipants();
    double getDistance() const;
};
