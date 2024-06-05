#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
{
    ui->setupUi(this);

    ui->rb_game->setChecked(true);

    for (int i = 0; i < 10; ++i)
    {
        ui->cb_gameList->addItem("Игра " + QString::number(i + 1));
    }

    ui->pbar_load->setRange(0, 10);
    ui->pbar_load->setValue(0);

    connect(ui->pb_play, &QPushButton::clicked, this, &MainWindow::on_pushButton_toggled);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    connect(ui->cb_gameList, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxValueChanged);

    connect(ui->rb_game, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
    connect(ui->rb_gameVR, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    if (checked)
    {
        timer->start(100);
    } else {
        timer->stop();
        ui->pbar_load->setValue(0);
    }
}

void MainWindow::updateProgressBar()
{
    int value = ui->pbar_load->value();
    value += 1;
    if (value > 10)
    {
        value = 0;
    }
    ui->pbar_load->setValue(value);
}

void MainWindow::onComboBoxValueChanged(int index)
{
    Q_UNUSED(index);

    if (ui->pb_play->isChecked())
    {
        ui->pb_play->setChecked(false);
        timer->stop();
        ui->pbar_load->setValue(0);
    }
}

void MainWindow::onRadioButtonToggled(bool checked)
{
    Q_UNUSED(checked);
    if (ui->pb_play->isChecked())
    {
        ui->pb_play->setChecked(false);
        timer->stop();
        ui->pbar_load->setValue(0);
    }
}
