#include "GameManager.h"
#include "Core/ParticipantRegistry.h"
#include "Core/RaceCalculation.h"
#include <vector>

GameManager::GameManager(int initialRaceType, double distance)
        : raceType(initialRaceType), participantRegistry(static_cast<RaceType>(initialRaceType)), track(distance) {
    registeredParticipants.clear();
    availableParticipants = participantRegistry.getAvailableParticipants();
}

void GameManager::changeRaceType(int newRaceType) {
    participantRegistry.changeRaceType(static_cast<RaceType>(newRaceType));
}

double GameManager::getDistance() const {
    return track.getDistance();
}

std::vector<std::pair<std::string, double>> GameManager::getResult() {
    return result;
}

void GameManager::resultRace(RaceCalculation &raceCalculation) {
    result = raceCalculation.getRaceResults();
}

void GameManager::startRace() {
    std::vector<Entity *> registeredParticipants = participantRegistry.getRegisteredParticipants();
    RaceCalculation raceCalculation(registeredParticipants, getDistance());
    resultRace(raceCalculation);
}

std::vector<std::string> GameManager::getAvailableParticipants() {
    std::vector<Entity *> availableParticipants = participantRegistry.getAvailableParticipants();
    std::vector<std::string> participantName;

    for (Entity *participant : availableParticipants) {
        participantName.push_back(participant->getName());
    }

    return participantName;
}

std::vector<std::string> GameManager::getRegisteredParticipants() {
    std::vector<Entity *> registeredParticipants = participantRegistry.getRegisteredParticipants();
    std::vector<std::string> participantName;

    for (Entity *participant: registeredParticipants) {
        participantName.push_back(participant->getName());
    }

    return participantName;
}

void GameManager::registerParticipant(int choice) {
    participantRegistry.setRegisteredParticipants(choice);
}

void GameManager::changeTrackDistance(double newTrackDistance) {
    track.setDistance(newTrackDistance);
}

//    if (choice == 0) {
//        return;
//    }
//
//    if (choice > 0 && choice <= availableParticipants.size()) {
//        participants.push_back(availableParticipants[choice - 1]);
//        std::string participantName = availableParticipants[choice - 1]->getName();
//        availableParticipants.erase(availableParticipants.begin() + choice - 1);
//        std::cout << "Participant " << participantName << " added to the race." << std::endl;
//    } else {
//        std::cout << "Invalid choice. Please select a valid participant." << std::endl;
//    }
