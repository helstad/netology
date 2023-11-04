#pragma once

#include <string>
#include <vector>

class GameManager {
private:
    std::vector<std::string> availableParticipants;
public:
    GameManager(int raceType, double distance);
    std::vector<std::string> getParticipants();
};
