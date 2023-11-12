#include "UserInterface.h"
#include <iostream>
#include <vector>
#include "RaceDLL/GameManager.h"

int UserInterface::menuRaceType() {
    int choice{};

    while (true) {
        std::cout << "Choose a race type:\n";
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

double UserInterface::menuTrackDistance(double trackDistance) {
    std::string input;
    while (true) {
        std::cout << "Enter track distance between 100 and 100,000 units:" << std::endl;
        std::cin >> input;
        try {
            trackDistance = std::stod(input);
            if (trackDistance >= 100 && trackDistance <= 100000) {
                break;
            } else {
                std::cout << "Invalid value. Please enter a value between 100 and 100,000." << std::endl;
            }
        } catch (std::invalid_argument&) {
            std::cout << "Invalid value. Please enter a valid number." << std::endl;
        }
    }
    return trackDistance;
}

void UserInterface::menuEntity(GameManager &gameManager) {
    const std::vector<std::string>& participants = gameManager.getAvailableParticipants();

    for (size_t i = 0; i < participants.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << participants[i] << std::endl;
    }
    std::cout << "[0] Close registration" << std::endl;
}

void UserInterface::showRegisterParticipant(GameManager &gameManager) {
    std::cout << "Registered participants: " << std::endl;

    const std::vector<std::string>& participants = gameManager.getRegisteredParticipants();

    if (participants.empty()) {
        std::cout << "None" << std::endl;
        return;
    }

    for (const auto &participant: participants) {
        std::cout << " - " << participant << std::endl;
    }
}

void UserInterface::showTrackDistance(GameManager &gameManager) {
    std::cout << "Your track length:\n" << " - " << gameManager.getDistance() << " units" << std::endl;
}

void UserInterface::changeRaceType(GameManager &gameManager) {
    int raceType = menuRaceType();
    gameManager.changeRaceType(raceType);
}

void UserInterface::changeTrackDistance(GameManager &gameManager) {
    double newDistance = menuTrackDistance(newDistance);
    gameManager.changeTrackDistance(newDistance);
}

void UserInterface::registerParticipant(GameManager &gameManager) {
    int choice{};
    std::vector<std::string> participants;

    do {
        std::cout << "Add participants: " << std::endl;
        participants = gameManager.getAvailableParticipants();
        menuEntity(gameManager);
        std::cin >> choice;

        if (choice > 0 && choice <= participants.size()) {
            gameManager.registerParticipant(choice);
        } else if (choice != 0) {
            std::cout << "Invalid participants" << std::endl;
        }
    } while (choice != 0);
}

void UserInterface::getResult(GameManager &gameManager) {
    const std::vector<std::pair<std::string, double>> &raceResults = gameManager.getResult();
    for (const auto &result: raceResults) {
        std::cout << "Participant: " << result.first << ", Total time: " << result.second << " hours\n";
    }
    std::cout << std::endl;

    changeRaceType(gameManager);
    changeTrackDistance(gameManager);
}

void UserInterface::startRace(GameManager &gameManager) {
    std::vector<std::string> participants = gameManager.getRegisteredParticipants();
    if (participants.size() < 2) {
        std::cout << "There must be at least 2 participants." << std::endl;
        return;
    }
    gameManager.startRace();
    getResult(gameManager);
}

void UserInterface::setMenuChoice(int choice, GameManager &gameManager) {
    switch (choice) {
        case 1:
            startRace(gameManager);
            break;
        case 2:
            registerParticipant(gameManager);
            break;
        case 3:
            showRegisterParticipant(gameManager);
            break;
        case 4:
            showTrackDistance(gameManager);
            break;
        case 5:
            changeTrackDistance(gameManager);
            break;
        case 6:
            changeRaceType(gameManager);
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

void UserInterface::menuMain(GameManager &gameManager) {
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

void UserInterface::Main() {
    std::cout << "Welcome to \"The Fantasy Race\"" << std::endl;

    int raceType = menuRaceType();
    double trackDistance = menuTrackDistance(trackDistance);

    GameManager gameManager(raceType, trackDistance);

    menuMain(gameManager);
}