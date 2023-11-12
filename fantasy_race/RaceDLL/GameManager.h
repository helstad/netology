#pragma once

#include <string>
#include <vector>
#include "Entities/Track.h"
#include "Core/ParticipantRegistry.h"
#include "Core/RaceCalculation.h"

class GameManager {
private:
    Track track;
    ParticipantRegistry participantRegistry;
    std::vector<Entity *> availableParticipants;
    std::vector<Entity *> registeredParticipants;
    std::vector<std::pair<std::string, double>> result;
    int raceType{};
public:
    GameManager(int raceType, double distance);
    void changeRaceType(int newRaceType);
    void changeTrackDistance(double newTrackDistance);
    void registerParticipant(int choice);
    void startRace();
    std::vector<std::string> getAvailableParticipants();
    std::vector<std::string> getRegisteredParticipants();
    double getDistance() const;
    void resultRace(RaceCalculation &raceCalculation);

    std::vector<std::pair<std::string, double>> getResult();
};
