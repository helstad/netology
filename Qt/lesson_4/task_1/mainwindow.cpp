#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rb_game->setChecked(true);

    for (int i = 0; i < 10; ++i)
    {
        ui->cb_gameList->addItem("Игра " + QString::number(i + 1));
    }

    ui->pb_play->setText("Play button");
    ui->pb_play->setCheckable(true);

    ui->pbar_load->setRange(0, 10);
    ui->pbar_load->setValue(0);

    connect(ui->pb_play, &QPushButton::clicked, this, &MainWindow::pushButtonClicked);
    connect(ui->cb_gameList, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxValueChanged);

    connect(ui->rb_game, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
    connect(ui->rb_gameVR, &QRadioButton::toggled, this, &MainWindow::onRadioButtonToggled);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushButtonClicked()
{
    updateProgressBar();
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
    resetState();
}

void MainWindow::onRadioButtonToggled(bool checked)
{
    Q_UNUSED(checked);
    ui->pb_play->setChecked(false);
    ui->pbar_load->setValue(0);
}

void MainWindow::resetState()
{
    ui->pb_play->setChecked(false);
    ui->pbar_load->setValue(0);
}
