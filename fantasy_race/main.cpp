#include <iostream>
#include <vector>
#include "RaceDLL/GameManager.h"

void menuEntity() {
//    for (size_t i = 0; i < option.size(); ++i) {
//        std::cout << i + 1 << ". " << option[i] << std::endl;
//    }
}

void registerParticipant(GameManager &gameManager) {
//    do {
//        std::cin >> choice;
//
//        switch (choice) {
//            case 1:
//                break;
//            case 2:
//                menuEntity(gameManager);
//                break;
//            case 0:
//                std::cout << "Back to menu" << std::endl;
//            default:
//                std::cout << "Invalid value" << std::endl;
//        }
//
//    } while (choice != 0);
}

void setMenuChoice(int choice, GameManager &gameManager) {
    switch (choice) {
        case 1:
            std::cout << "Start race" << std::endl;
            break;
        case 2:
            std::cout << "Register a participant" << std::endl;
            break;
        case 3:
            std::cout << "Show registered participants" << std::endl;
            break;
        case 4:
            std::cout << "- Your track length: " << gameManager.getDistance() << std::endl;
            break;
        case 5:
            std::cout << "Change track length" << std::endl;
            break;
        case 6:
            std::cout << "Change race type" << std::endl;
            break;
        case 0:
            std::cout << "Bye!" << std::endl;
            break;
        default:
            std::cout << "Invalid value" << std::endl;
    }
    std::cout << std::endl;
}

void menuMain(GameManager &gameManager) {
    int choice{};

    do {
        std::cout << "1. Start race" << std::endl;
        std::cout << "2. Register a participant" << std::endl;
        std::cout << "3. Show registered participants" << std::endl;
        std::cout << "4. Show track length" << std::endl;
        std::cout << "5. Change track length" << std::endl;
        std::cout << "6. Change race type" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> choice;

        setMenuChoice(choice, gameManager);
    } while (choice != 0);
}

int menuRaceType(int raceType) {
    int choice{};

    std::cout << "1. Ground race" << std::endl;
    std::cout << "2. Air race" << std::endl;
    std::cout << "3. Combined race" << std::endl;
    std::cin >> choice;

    return raceType;
}

double menuTrackDistance(double trackDistance) {
    std::cout << "Enter track distance" << std::endl;
    std::cin >> trackDistance;

    return trackDistance;
}

int main() {
    std::cout << "Welcome to \"The Fantasy Race\"" << std::endl;

    int raceType = menuRaceType(raceType);
    double trackDistance = menuTrackDistance(trackDistance);

    GameManager gameManager(raceType, trackDistance);

    menuMain(gameManager);

    return 0;
}