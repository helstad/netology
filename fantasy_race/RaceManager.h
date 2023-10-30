#pragma once

#include <vector>
#include <string>
#include "RaceDLL/EntitiesList.h"

class RaceManager {
private:
    std::vector<GroundEntity*> participants;
    std::vector<GroundEntity*> availableParticipants;
    Track track;
public:
    RaceManager();

    void createTrack(double distance);
    void showTrackDistance() const;

    void initAvailableParticipants();
    void showAvailableParticipants();
    void registerParticipant(int choice);
    void showRegisteredParticipants();
    void startRace();
};
