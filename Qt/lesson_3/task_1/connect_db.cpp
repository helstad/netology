#include "connect_db.h"
#include "./ui_connect_db.h"

ConnectDB::ConnectDB(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectDB)
{
    ui->setupUi(this);

    ui->pb_ok->setEnabled(false);
    ui->cb_connect->setEnabled(false);

    connect(ui->le_dbName, &QLineEdit::textChanged, this, &ConnectDB::updateButtonState);
    connect(ui->le_hostName, &QLineEdit::textChanged, this, &ConnectDB::updateButtonState);

    connect(ui->le_login, &QLineEdit::textChanged, this, &ConnectDB::updateCheckBoxState);
    connect(ui->le_password, &QLineEdit::textChanged, this, &ConnectDB::updateCheckBoxState);
}

ConnectDB::~ConnectDB()
{
    delete ui;
}

void ConnectDB::updateButtonState() {
    bool enableButton = !ui->le_dbName->text().isEmpty() && !ui->le_hostName->text().isEmpty();
    ui->pb_ok->setEnabled(enableButton);
}

void ConnectDB::updateCheckBoxState() {
    bool enableCheckBox = !ui->le_login->text().isEmpty() && !ui->le_password->text().isEmpty();
    ui->cb_connect->setEnabled(enableCheckBox);
}

void ConnectDB::on_pb_close_clicked()
{
    this->close();
}

