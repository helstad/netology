#include <iostream>
#include <vector>
#include "RaceDLL/GameManager.h"
#include "RaceDLL/Core/ParticipantRegistry.h"

void createMenu(const std::vector<std::string>& option) {
    for (size_t i = 0; i < option.size(); ++i) {
        std::cout << i + 1 << ". " << option[i] << std::endl;
    }
}

void dataMainMenu() {
    std::vector<std::string> mainMenu = {
            "Start Race",
            "Register Participant",
            "Show Registered Participants",
            "Show Track Distance",
            "Change Race Type",
            "Change Track Distance"
    };
    createMenu(mainMenu);
}

void menuMainMenu() {
    std::cout << "Menu: " << std::endl;
    dataMainMenu();
}

void menuEntity(GameManager &gameManager) {
//    std::vector<std::string> showParticipants = gameManager.getParticipants();
    createMenu(gameManager.getParticipants());
}

void menuDistance() {
    std::cout << "Enter a track distance: " << std::endl;
}

void dataRaceType() {
    std::vector<std::string> raceTypes = {"Ground racing", "Air racing", "Combined racing"};
    createMenu(raceTypes);
}

void menuRaceType() {
    std::cout << "Choose a race type:" << std::endl;
    dataRaceType();
}

int main() {
    menuRaceType();
    int raceType{};
    std::cin >> raceType;

    menuDistance();
    double distance{};
    std::cin >> distance;

    GameManager gameManager(raceType, distance);

//    menuEntity(gameManager);

    int choice{};
    do {
        menuMainMenu();
        std::cout << "0. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                break;
            case 2:
                menuEntity(gameManager);
                break;
            case 0:
                std::cout << "Back to menu" << std::endl;
            default:
                std::cout << "Invalid value" << std::endl;
        }

    } while (choice != 0);
}
