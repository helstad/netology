#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialogAbout = new DialogAbout(this);

    ui->pb_ok->setEnabled(false);
    ui->cb_connect->setEnabled(false);

    connect(ui->le_dbName, &QLineEdit::textChanged, this, &MainWindow::updateButtonState);
    connect(ui->le_hostName, &QLineEdit::textChanged, this, &MainWindow::updateButtonState);

    connect(ui->pb_ok, &QPushButton::clicked, this, &MainWindow::showTestInStatusBar);

    connect(ui->le_login, &QLineEdit::textChanged, this, &MainWindow::updateCheckBoxState);
    connect(ui->le_password, &QLineEdit::textChanged, this, &MainWindow::updateCheckBoxState);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_about_clicked()
{
    dialogAbout->show();
}

void MainWindow::updateButtonState() {
    bool enableButton = !ui->le_dbName->text().isEmpty() && !ui->le_hostName->text().isEmpty();
    ui->pb_ok->setEnabled(enableButton);
}

void MainWindow::updateCheckBoxState() {
    bool enableCheckBox = !ui->le_login->text().isEmpty() && !ui->le_password->text().isEmpty();
    ui->cb_connect->setEnabled(enableCheckBox);
}

void MainWindow::showTestInStatusBar() {
    QString name = ui->le_dbName->text();
    QString host = ui->le_hostName->text();
    if (ui->cb_connect->isChecked())
    {
        ui->statusbar->showMessage("Connecting to: " + name + " / " + host, 3000);
    } else {
        ui->statusbar->showMessage("Create connection to: " + name + " / " + host + " is success!", 3000);
    }

}

