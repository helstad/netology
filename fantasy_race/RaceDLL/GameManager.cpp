#include "GameManager.h"
#include "Core/ParticipantRegistry.h"
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

void GameManager::startRace() {

}

std::vector<std::string> GameManager::getParticipants() {
    availableParticipants = participantRegistry.getAvailableParticipants();
    std::vector<std::string> participants;
    for (const auto &availableParticipant: availableParticipants) {
        participants.push_back(availableParticipant);
    }
    return participants;
}

std::vector<std::string> GameManager::getRegisteredParticipants() {
    registeredParticipants = participantRegistry.getRegisteredParticipants();
    std::vector<std::string> participants;
    for (const auto &registeredParticipant: registeredParticipants) {
        participants.push_back(registeredParticipant);
    }
    return participants;
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
