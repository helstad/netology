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

    void initGroundParticipants();
    void initAirParticipants();
    void initCombinedParticipants();
    void setAvailableParticipants(RaceType raceType);

public:
    explicit ParticipantRegistry(RaceType raceType);
    ~ParticipantRegistry();
    std::vector<std::string> getParticipantNames() const;
};
