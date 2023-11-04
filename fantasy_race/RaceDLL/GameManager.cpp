#include "GameManager.h"
#include "Core/ParticipantRegistry.h"
#include <iostream>

GameManager::GameManager(int raceType, double distance) {
    ParticipantRegistry participantRegistry(static_cast<RaceType>(raceType));
    Track track(distance);
    availableParticipants = participantRegistry.getParticipantNames();
}

std::vector<std::string> GameManager::getParticipants() {
    return availableParticipants;
}
