#include <iostream>
#include <vector>
#include "RaceDLL/GameManager.h"

void menuEntity(GameManager &gameManager) {

    std::vector<std::string> participants;
    participants.clear();
    participants = gameManager.getParticipants();

    for (size_t i = 0; i < participants.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << participants[i] << std::endl;
    }
    std::cout << "[0] Close registration" << std::endl;
}

void showRegisterParticipant(GameManager &gameManager) {
    std::cout << "Registered participants: " << std::endl;

    std::vector<std::string> participants;
    participants = gameManager.getRegisteredParticipants();

    if (participants.empty()) {
        std::cout << "None" << std::endl;
        return;
    }

    for (const auto & participant : participants) {
        std::cout << " - " << participant << std::endl;
    }
}

void registerParticipant(GameManager &gameManager) {
    int choice{};
    std::vector<std::string> participants;
    do {
        std::cout << "Add participants: " << std::endl;
        participants.clear();
        participants = gameManager.getParticipants();
        menuEntity(gameManager);
        std::cin >> choice;

        if (choice <= 0 || choice > participants.size()) {
            std::cout << "Invalid participants" << std::endl;
            return;
        }
        gameManager.registerParticipant(choice);
    } while (choice != 0);
}

void setMenuChoice(int choice, GameManager &gameManager) {
    switch (choice) {
        case 1:
            std::cout << "Start race" << std::endl;
            break;
        case 2:
            registerParticipant(gameManager);
            break;
        case 3:
            showRegisterParticipant(gameManager);
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
            break;
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

int menuRaceType() {
    int choice{};

    while (true) {
        std::cout << "1. Ground race" << std::endl;
        std::cout << "2. Air race" << std::endl;
        std::cout << "3. Combined race" << std::endl;
        std::cin >> choice;

        if (choice >= 1 && choice <= 3) {
            break;
        } else {
            std::cout << "Invalid value. Please enter a value between 1 and 3." << std::endl;
        }
    }

    return choice;
}

double menuTrackDistance(double trackDistance) {
    while (true) {
        std::cout << "Enter track distance between 500 and 100 000 units:" << std::endl;
        std::cin >> trackDistance;

        if (trackDistance > 500 && trackDistance <= 100000) {
            break;
        } else {
            std::cout << "Invalid value. Please enter a value between 500 and 100 000." << std::endl;
        }
    }

    return trackDistance;
}

int main() {
    std::cout << "Welcome to \"The Fantasy Race\"" << std::endl;

    int raceType = menuRaceType();
    double trackDistance = menuTrackDistance(trackDistance);

    GameManager gameManager(raceType, trackDistance);

    menuMain(gameManager);

    return 0;
}