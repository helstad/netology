#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager networkManager;
    QSqlDatabase sqlDB;

    qInfo() << "Network manager created succesfuly.";
    qInfo() << "Sql Database created succesfuly.";

    return a.exec();
}
