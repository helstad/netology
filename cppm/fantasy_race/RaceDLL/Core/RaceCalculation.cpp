#include <iostream>
#include <algorithm>
#include "RaceCalculation.h"
#include "ParticipantRegistry.h"

RaceCalculation::RaceCalculation(const std::vector<Entity *> &participants, double distance) : participants(
        participants), distance(distance) {
    calculateRace();
}

void RaceCalculation::calculateRace() {
    raceResults.clear();
    for (Entity *participant: participants) {
        if (participant != nullptr) {
            double totalTime = participant->getTotalTravelTime(distance);

            raceResults.emplace_back(participant->getName(), totalTime);
        }
    }
    sortRaceResults();
}

void RaceCalculation::sortRaceResults() {
    auto compareTime = [](const std::pair<std::string, double> &a, const std::pair<std::string, double> &b) {
        return a.second < b.second;
    };
    std::sort(raceResults.begin(), raceResults.end(), compareTime);
}

const std::vector<std::pair<std::string, double>>& RaceCalculation::getRaceResults() const {
    return raceResults;
}