#include "GameManager.h"
#include "Core/ParticipantRegistry.h"
#include <iostream>

//void GameManager::init(int raceType, double distance) {
//    ParticipantRegistry participantRegistry(static_cast<RaceType>(raceType));
////    std::vector<Entity *> participants = participantRegistry.getAvailableParticipants();
////    for (Entity* participant : participants) {
////        std::cout << participant->getName() << std::endl;
////    }
//    Track track(distance);
//}

GameManager::GameManager(int raceType, double distance) {
    ParticipantRegistry participantRegistry(static_cast<RaceType>(raceType));
    Track track(distance);
    participantRegistry.getParticipantNames();
}
