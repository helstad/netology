#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "watch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_timer_clicked();
    void on_pb_clear_clicked();
    void on_pb_lap_clicked();

    void updateTime(int seconds);
    void recordLap(int lapNumber, int lapTime);



private:
    Ui::MainWindow *ui;
    Watch watch;
    bool isRunning;
};
#endif // MAINWINDOW_H
