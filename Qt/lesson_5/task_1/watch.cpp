#include "watch.h"

Watch::Watch(QObject *parent)
    : QObject(parent),
    elapsedSeconds(0),
    lastLapTime(0),
    lapNumber(0),
    running(false)
{
    connect(&timer, &QTimer::timeout, this, &Watch::updateTime);
    timer.setInterval(100);
}

void Watch::start() {
    if (!running) {
        timer.start();
        running = true;
    }
}

void Watch::stop() {
    if (running) {
        timer.stop();
        running = false;
    }
}

void Watch::reset() {
    timer.stop();
    elapsedSeconds = 0;
    lastLapTime = 0;
    lapNumber = 0;
    running = false;
    emit timeUpdated(elapsedSeconds);
}

void Watch::lap() {
    if (running) {
        lapNumber++;
        int currentLapTime = elapsedSeconds - lastLapTime;
        lastLapTime = elapsedSeconds;
        emit lapRecorded(lapNumber, currentLapTime);
    }
}

void Watch::updateTime() {
    if (running) {
        elapsedSeconds++;
        emit timeUpdated(elapsedSeconds);
    }
}
