#pragma once

#include <vector>
#include <string>
#include "../Entities/EntitiesList.h"

enum class RaceType {
    GroundRace = 1,
    AirRace,
    CombinedRace
};

class ParticipantRegistry {
private:
    std::vector<Entity *> participants;
    std::vector<Entity *> availableParticipants;
    std::vector<Entity *> registeredParticipants;

    void initGroundParticipants();
    void initAirParticipants();
    void initCombinedParticipants();
    void setAvailableParticipants(RaceType raceType);

public:
    explicit ParticipantRegistry(RaceType raceType);
    void changeRaceType(RaceType newRaceType);
    void setRegisteredParticipants(int choice);
    std::vector<Entity *> getRegisteredParticipants() const;
    std::vector<Entity *> getAvailableParticipants() const;
};
