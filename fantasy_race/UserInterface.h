#pragma once


#include "RaceDLL/GameManager.h"

class UserInterface {
public:
    static void Main();

private:
    static void menuMain(GameManager &gameManager);

    static void setMenuChoice(int choice, GameManager &gameManager);

    static void startRace(GameManager &gameManager);

    static void getResult(GameManager &gameManager);

    static void registerParticipant(GameManager &gameManager);

    static void changeTrackDistance(GameManager &gameManager);

    static void changeRaceType(GameManager &gameManager);

    static void showTrackDistance(GameManager &gameManager);

    static void showRegisterParticipant(GameManager &gameManager);

    static void menuEntity(GameManager &gameManager);

    static double menuTrackDistance(double trackDistance);

    static int menuRaceType();

};
