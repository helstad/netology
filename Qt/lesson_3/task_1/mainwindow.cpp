#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogAbout = new DialogAbout(this);
    connectDB = new ConnectDB(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_about_clicked()
{
    dialogAbout->show();
}

void MainWindow::on_pb_create_clicked()
{
    connectDB->show();
}

