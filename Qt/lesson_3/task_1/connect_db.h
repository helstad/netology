#ifndef CONNECT_DB_H
#define CONNECT_DB_H

#include <QDialog>

namespace Ui {
class ConnectDB;
}

class ConnectDB : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDB(QWidget *parent = nullptr);
    ~ConnectDB();

private slots:
    void updateButtonState();
    void updateCheckBoxState();

    void on_pb_close_clicked();

private:
    Ui::ConnectDB *ui;
};

#endif // CONNECT_DB_H
