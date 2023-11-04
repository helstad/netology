#include "Menu.h"

int Menu::selectRaceType() {
    std::cout << "Select the type of race: " << std::endl;
    for (size_t i = 0; i < raceTypes.size(); ++i) {
        std::cout << i + 1 << ". " << raceTypes[i] << std::endl;
    }

    int choice;
    std::cin >> choice;
    return choice;
}

double Menu::enterTrackDistance() {
    double distance;
    std::cout << "Enter the track distance: ";
    std::cin >> distance;
    return distance;
}

int Menu::displayMenu() {
    std::cout << "Menu:" << std::endl;
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        std::cout << i + 1 << ". " << menuOptions[i] << std::endl;
    }

    int choice;
    std::cin >> choice;
    return choice;
}

void Menu::showRaceMenu() {

}