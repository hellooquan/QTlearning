#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("serial");
    ui->comboBox->addItem("MQTT");
    ui->comboBox->addItem("Modbus");
    ui->comboBox->addItem("CAN");

    ui->comboBox_2->addItem("9600");
    ui->comboBox_2->addItem("14400");
    ui->comboBox_2->addItem("115200");
}

MainWindow::~MainWindow()
{
    delete ui;
}
