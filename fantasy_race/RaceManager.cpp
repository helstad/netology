//#include <iostream>
//#include "RaceManager.h"
//#include "RaceDLL/Entities/EntitiesList.h"
//
//RaceManager::RaceManager() {
//    initAvailableParticipants();
//}
//
//void RaceManager::createTrack(double distance) {
//    track.setDistance(distance);
//}
//
//void RaceManager::showTrackDistance() const {
//    std::cout << "Track length: " << track.getDistance() << " units" << std::endl;
//}
//
//void RaceManager::initAvailableParticipants() {
//    availableParticipants.push_back(new Camel());
//    availableParticipants.push_back(new FastCamel());
//    availableParticipants.push_back(new Centaur());
//    availableParticipants.push_back(new BootsTerrain());
//}
//
//void RaceManager::showAvailableParticipants() {
//    for (size_t i = 0; i < availableParticipants.size(); ++i) {
//        std::cout << "[" << i + 1 << "] " << availableParticipants[i]->getName() << std::endl;
//    }
//    std::cout << "[0] Back to menu" << std::endl;
//}
//
//void RaceManager::registerParticipant(int choice) {
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
//}
//
//void RaceManager::showRegisteredParticipants() {
//    std::cout << "Registered participants:" << std::endl;
//
//    if (participants.empty()) {
//        std::cout << "No one is registered yet." << std::endl;
//    } else {
//        for (GroundEntity *participant: participants) {
//            std::cout << participant->getName() << std::endl;
//        }
//    }
//    std::cout << std::endl;
//}
//
//void RaceManager::startRace() {
//
//}