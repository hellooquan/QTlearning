#include "mainwindow.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString jsonstr = "{\"商品名\":\"哇哈哈\",\"价格\":4.5,\"数量\":20,"
                      "\"生产厂家\"[\"广州市永和经济开发区\"],\"口味\":[\"白桃味\",\"苹果味\"]}";

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonstr.toUtf8());

    QJsonObject

        QJsonValue jsonVal(jsonDoc);
    QString shangp = j
}

MainWindow::~MainWindow()
{
    delete ui;
}
