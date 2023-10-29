#include <iostream>
#include "RaceManager.h"

int main() {
    RaceManager raceManager;

    std::cout << "Welcome to the Fantasy Race.\n";

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show registered participants" << std::endl;
        std::cout << "2. Register a participant" << std::endl;
        std::cout << "3. Start race" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice{};
        std::cin >> choice;

        switch (choice) {
            case 1:
                raceManager.showRegisteredParticipants();
                break;
            case 2:
                raceManager.showAvailableParticipants();
                int participantChoice;
                std::cout << "Choose participant: ";
                std::cin >> participantChoice;
                if (participantChoice == 0) {
                    std::cout << "Back to the menu." << std::endl;
                } else {
                    raceManager.registerParticipant(participantChoice);
                }
                break;
            case 3:
                raceManager.startRace();
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }
    return 0;
}
