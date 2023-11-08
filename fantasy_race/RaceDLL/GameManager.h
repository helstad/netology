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
    int raceType{};
public:
    GameManager(int raceType, double distance);
    void changeRaceType(int newRaceType);
    void changeTrackDistance(double newTrackDistance);
    void registerParticipant(int choice);
    void startRace();
    std::vector<std::string> getParticipants();
    std::vector<std::string> getRegisteredParticipants();
    double getDistance() const;
};
