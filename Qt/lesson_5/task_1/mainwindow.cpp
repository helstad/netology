#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isRunning(false)
{
    ui->setupUi(this);
    ui->l_time->setText("00:00:00");

    connect(&watch, &Watch::timeUpdated, this, &MainWindow::updateTime);
    connect(&watch, &Watch::lapRecorded, this, &MainWindow::recordLap);

    ui->pb_lap->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_timer_clicked()
{
    if (isRunning) {
        watch.stop();
        ui->pb_timer->setText("Start");
        ui->pb_lap->setEnabled(false);
    } else {
        watch.start();
        ui->pb_timer->setText("Stop");
        ui->pb_lap->setEnabled(true);
    }
    isRunning = !isRunning;
}

void MainWindow::on_pb_clear_clicked()
{
    watch.reset();
    ui->l_time->setText("00:00:00");
    ui->tb_laps->clear();
    ui->pb_timer->setText("Start");
    ui->pb_lap->setEnabled(false);
    isRunning = false;
}

void MainWindow::on_pb_lap_clicked()
{
    watch.lap();
}

void MainWindow::updateTime(int seconds)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int secs = seconds % 60;
    QTime time(hours, minutes, secs);
    QString timeString = time.toString("hh:mm:ss");
    ui->l_time->setText(timeString);
}

void MainWindow::recordLap(int lapNumber, int lapTime)
{
    int hours = lapTime / 3600;
    int minutes = (lapTime % 3600) / 60;
    int secs = lapTime % 60;
    QTime time(hours, minutes, secs);
    QString lapTimeString = time.toString("hh:mm:ss");
    ui->tb_laps->append(QString("Lap %1, time: %2").arg(lapNumber).arg(lapTimeString));
}

