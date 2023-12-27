#pragma once


#include <vector>
#include "ParticipantRegistry.h"

class RaceCalculation {
private:
    std::vector<Entity *> participants;
    double distance{};
    std::vector<std::pair<std::string, double>> raceResults;

    void sortRaceResults();

    void calculateRace();

public:
    explicit RaceCalculation(const std::vector<Entity *> &participants, double distance);

    const std::vector<std::pair<std::string, double>> &getRaceResults() const;
};
