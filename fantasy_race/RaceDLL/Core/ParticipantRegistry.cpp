#include "ParticipantRegistry.h"

ParticipantRegistry::ParticipantRegistry(RaceType raceType) {
    setAvailableParticipants(raceType);
}

void ParticipantRegistry::setAvailableParticipants(RaceType raceType) {
    availableParticipants.clear();

    switch (raceType) {
        case RaceType::GroundRace:
            initGroundParticipants();
            break;
        case RaceType::AirRace:
            initAirParticipants();
            break;
        case RaceType::CombinedRace:
            initCombinedParticipants();
            break;
    }
}

void ParticipantRegistry::changeRaceType(RaceType newRaceType) {
    for (Entity* participant : availableParticipants) {
        delete participant;
    }
    availableParticipants.clear();

    for (Entity* participant : registeredParticipants) {
        delete participant;
    }
    registeredParticipants.clear();

    setAvailableParticipants(newRaceType);
}

void ParticipantRegistry::initGroundParticipants() {
    availableParticipants.push_back(new Camel());
    availableParticipants.push_back(new FastCamel());
    availableParticipants.push_back(new Centaur());
    availableParticipants.push_back(new BootsTerrain());
}

void ParticipantRegistry::initAirParticipants() {
    availableParticipants.push_back(new Eagle());
    availableParticipants.push_back(new MagicCarpet());
    availableParticipants.push_back(new Broomstick());
}

void ParticipantRegistry::initCombinedParticipants() {
    initGroundParticipants();
    initAirParticipants();
}

void ParticipantRegistry::setRegisteredParticipants(int choice) {
    registeredParticipants.push_back(availableParticipants[choice - 1]);
    availableParticipants.erase(availableParticipants.begin() + choice - 1);
}

std::vector<std::string> ParticipantRegistry::getRegisteredParticipants() const {
    std::vector<std::string> participantNames;
    for (auto registeredParticipant : registeredParticipants) {
        participantNames.push_back(registeredParticipant->getName());
    }
    return participantNames;
}

std::vector<std::string> ParticipantRegistry::getAvailableParticipants() const {
    std::vector<std::string> participantNames;
    for (auto availableParticipant : availableParticipants) {
        participantNames.push_back(availableParticipant->getName());
    }
    return participantNames;
}