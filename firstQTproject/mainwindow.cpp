#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loggerptr=new logger(ui);
    loggerptr->info("MainWindow","主窗口W创建成功");
    loggerptr->info("MainWindow","主窗口创建成功");
    qWarning()<<"WARNING";
}

MainWindow::~MainWindow()
{
    delete ui;
}
