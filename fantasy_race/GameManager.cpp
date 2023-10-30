#include "GameManager.h"
#include <iostream>

int GameManager::chooseRaceType() {
    int raceType{};

    while (true) {
        std::cout << "Choose the type of race:\n";
        std::cout << "1. Ground vehicles only\n";
        std::cout << "2. Air vehicles only\n";
        std::cout << "3. Both ground and air vehicles\n";
        std::cout << "0. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                raceType = choice;
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                continue;
        }

        break;
    }

    return raceType;
}

double GameManager::enterTrackDistance() {
    double distance = 0.0;
    std::cout << "Enter the distance of the track: ";
    std::cin >> distance;
    return distance;
}