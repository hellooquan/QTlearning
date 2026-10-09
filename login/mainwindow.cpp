#include "mainwindow.h"
#include <QString>
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
    QString name = ui->lineEdit->text();
    QString passwd = ui->lineEdit_2->text();

    if (name == "admin" && passwd == "123456")
        qDebug() << "登录成功";
    else
        qDebug() << "登录失败";
}
