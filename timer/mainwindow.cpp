#include "mainwindow.h"
#include <QLabel>
#include <QTimer>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    pixmap = new QPixmap("D:/Learn/QTproject/picture/LilDurk.png");

    timer1->setInterval(1000);
    timer2->setInterval(1000);

    connect(timer1, &QTimer::timeout, this, &MainWindow::showPicture);
    connect(timer2, &QTimer::timeout, this, &MainWindow::showTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer1->start();
}

void MainWindow::showPicture()
{
    ui->label->setPixmap(*pixmap);
}

void MainWindow::on_pushButton_3_clicked()
{
    timer2->start();
}

void MainWindow::showTime()
{
    ui->lcdNumber->display("2026-10-18");
}
