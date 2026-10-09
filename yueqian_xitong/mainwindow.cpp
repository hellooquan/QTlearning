#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->setText("串口协议");
}

void MainWindow::on_MQTT_clicked()
{
    ui->label_2->setText("MQTT");
}

void MainWindow::on_Modbus_clicked()
{
    ui->label_2->setText("Modbus");
}

void MainWindow::on_CAN_clicked()
{
    ui->label_2->setText("CAN");
}
