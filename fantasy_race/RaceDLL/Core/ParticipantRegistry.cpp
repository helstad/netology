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

ParticipantRegistry::~ParticipantRegistry() {
    for (Entity* participant : availableParticipants) {
        delete participant;
    }
    availableParticipants.clear();
}

std::vector<std::string> ParticipantRegistry::getParticipantNames() const {
    std::vector<std::string> participantNames;
//    for (const Entity* participant : availableParticipants) {
//        participantNames.push_back(participant->getName());
//    }
//    return participantNames;

    for (auto availableParticipant : availableParticipants) {
        participantNames.push_back(availableParticipant->getName());
    }
    return participantNames;
}
