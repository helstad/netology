#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogabout.h"
#include "connect_db.h"

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
    void on_pb_about_clicked();
    void on_pb_create_clicked();

private:
    Ui::MainWindow *ui;
    DialogAbout* dialogAbout;
    ConnectDB* connectDB;
};
#endif // MAINWINDOW_H
