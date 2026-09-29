#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->yesBt, &QPushButton::clicked, this, &MainWindow::slotNmae, Qt::UniqueConnection);
    connect(ui->yesBt, &QPushButton::clicked, this, &MainWindow::slotNmae, Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotNmae()
{
    qDebug() << "i'm slot";
}