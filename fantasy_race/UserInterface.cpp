#include "UserInterface.h"
#include <iostream>
#include <vector>
#include "RaceDLL/GameManager.h"
#include <limits>

int UserInterface::menuRaceType() {
    int choice{};

    while (true) {
        std::cout << "Choose a race type:\n";
        std::cout << "1. Ground race\n";
        std::cout << "2. Air race\n";
        std::cout << "3. Combined race\n";

        if (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cout << "Invalid value. Please enter a value between 1 and 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        } else {
            break;
        }
    }
    return choice;
}

double UserInterface::menuTrackDistance(double trackDistance) {
    std::string input;
    while (true) {
        std::cout << "Enter track distance between 100 and 100,000 units:\n";
        std::cin >> input;
        try {
            trackDistance = std::stod(input);
            if (trackDistance >= 100 && trackDistance <= 100000) {
                break;
            } else {
                std::cout << "Invalid value. Please enter a value between 100 and 100,000.\n";
            }
        } catch (std::invalid_argument&) {
            std::cout << "Invalid value. Please enter a valid value.\n";
        }
    }
    return trackDistance;
}

void UserInterface::menuEntity(GameManager &gameManager) {
    const std::vector<std::string>& participants = gameManager.getAvailableParticipants();

    for (size_t i = 0; i < participants.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << participants[i] << "\n";
    }
    std::cout << "[0] Close registration\n";
}

void UserInterface::showRegisterParticipant(GameManager &gameManager) {
    std::cout << "Registered participants:\n";

    const std::vector<std::string>& participants = gameManager.getRegisteredParticipants();

    if (participants.empty()) {
        std::cout << "None\n";
        return;
    }

    for (const auto &participant: participants) {
        std::cout << " - " << participant << "\n";
    }
}

void UserInterface::showTrackDistance(GameManager &gameManager) {
    std::cout << "Your track length:\n" << " - " << gameManager.getDistance() << " units\n";
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
        std::cout << "Add participants:\n";
        participants = gameManager.getAvailableParticipants();

        if (participants.empty()) {
            std::cout << "No available participants\n";
            break;
        }

        menuEntity(gameManager);

        if (!(std::cin >> choice) || choice < 0 || choice > participants.size()) {
            std::cout << "Invalid participants\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        } else if (choice > 0) {
            gameManager.registerParticipant(choice);
        }
    } while (choice != 0);
}

void UserInterface::getResult(GameManager &gameManager) {
    const std::vector<std::pair<std::string, double>> &raceResults = gameManager.getResult();

    if (raceResults.empty()) {
        std::cout << "No results.\n";
        return;
    }

    for (const auto &result: raceResults) {
        std::cout << "Participant: " << result.first << ", Total time: " << result.second << " hours\n";
    }
    std::cout << std::endl;

    askPlayAgain();
}

void UserInterface::startRace(GameManager &gameManager) {
    std::vector<std::string> participants = gameManager.getRegisteredParticipants();
    if (participants.size() < 2) {
        std::cout << "There must be at least 2 participants.\n";
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
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Invalid value\n";
            break;
    }
    std::cout << std::endl;
}

void UserInterface::menuMain(GameManager &gameManager) {
    int choice{};

    do {
        std::cout << "1. Start race\n";
        std::cout << "2. Register a participant\n";
        std::cout << "3. Show registered participants\n";
        std::cout << "4. Show track length\n";
        std::cout << "5. Change track length\n";
        std::cout << "6. Change race type\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;

        setMenuChoice(choice, gameManager);
    } while (choice != 0);
}

void UserInterface::askPlayAgain() {
    std::string input;
    std::cout << "Play again? (y/n): ";
    std::cin >> input;

    if (input == "y" || input == "Y") {
        Play();
    } else if (input == "n" || input == "N") {
        std::cout << "Bye!\n";
        exit(0);
    } else {
        std::cout << "Invalid input\n";
    }
}

void UserInterface::Play() {
    std::cout << "Welcome to \"The Fantasy Race\"\n";

    int raceType = menuRaceType();
    double trackDistance = menuTrackDistance(trackDistance);

    GameManager gameManager(raceType, trackDistance);

    menuMain(gameManager);
}