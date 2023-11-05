#include "GameManager.h"
#include "Core/ParticipantRegistry.h"
#include <iostream>

GameManager::GameManager(int raceType, double distance) : raceType(raceType), track(distance){
    ParticipantRegistry participantRegistry(static_cast<RaceType>(raceType));

    availableParticipants = participantRegistry.getParticipantNames();
}

double GameManager::getDistance() const {
    return track.getDistance();
}

//GameManager::registerParticipant(int choice) {
//    if (choice == 0) {
//        return;
//    }
//
//    if (choice > 0 && choice <= availableParticipants.size()) {
//        participants.push_back(availableParticipants[choice - 1]);
//
//    }
//}
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

std::vector<std::string> GameManager::getParticipants() {
    return availableParticipants;
}
