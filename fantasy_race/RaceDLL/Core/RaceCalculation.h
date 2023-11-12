#pragma once


#include <vector>
#include "ParticipantRegistry.h"

class RaceCalculation {
private:
    std::vector<Entity *> participants;
    double distance{};
    std::vector<std::pair<std::string, double>> raceResults;
//    const ParticipantRegistry &participantRegistry;
public:
    explicit RaceCalculation(const std::vector<Entity *>& participants, double distance);
    void calculateRace();
    const std::vector<std::pair<std::string, double>>& getRaceResults() const;
    void sortRaceResults();
};
