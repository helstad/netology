#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include <QTimer>

class Watch : public QObject
{
    Q_OBJECT

public:
    explicit Watch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();
    void lap();

signals:
    void timeUpdated(int secons);
    void lapRecorded(int lapNumber, int lapTime);

private:
    void updateTime();

private:
    QTimer timer;
    int elapsedSeconds;
    int lastLapTime;
    int lapNumber;
    bool running;
};

#endif // WATCH_H
