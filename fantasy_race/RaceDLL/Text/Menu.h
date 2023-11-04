#pragma once

#include <vector>
#include <iostream>

class Menu {
public:
    int selectRaceType();
    double enterTrackDistance();
    int displayMenu();
    void showRaceMenu();

private:
    std::vector<std::string> raceTypes = {"Ground racing", "Air racing", "Combined racing"};
    std::vector<std::string> menuOptions = {
            "Register Participant",
            "Show Registered Participants",
            "Show Track Distance",
            "Change Race Type",
            "Change Track Distance",
            "Start Race"
    };
};
