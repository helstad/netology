#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDataStream>
#include <QMessageBox>
#include <QtGlobal>
#include <QtConcurrent>
#include <QPointer>

///Подключаем все что нужно для графиков
#include <QChart>
#include <QChartView>
#include <QLineSeries>

#define FD 1000.0 //частота дискретизации

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_path_clicked();
    void on_pb_start_clicked();
    void dataReadySlot();
    void onChartWindowDestroyed();

signals:
    void dataReady();

private:
    Ui::MainWindow *ui;
    QLineSeries* series;

    QPointer<QMainWindow> chartWindow;
    QPointer<QChartView> chartView;
    QPointer<QChart> chart;

    QString pathToFile;
    uint8_t numberSelectChannel = 0xEA;
    QVector<double> mins, maxs;

    QVector<uint32_t> ReadFile(QString path, uint8_t numberChannel);
    QVector<double> ProcessFile(QVector<uint32_t> dataFile);
    QVector<double> FindMax(QVector<double> resultData);
    QVector<double> FindMin(QVector<double> resultData);
    void DisplayResult(QVector<double> mins, QVector<double> maxs);
    void displayChart();
};
#endif // MAINWINDOW_H
