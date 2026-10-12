#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , client(nullptr)
    , isConnect(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_linkbt_clicked()
{
    // 释放旧的 client
    if (isConnect) {
        client->disconnectFromHost();
        return;
    }
    QString addr = ui->urllineedit->text();
    QString port = ui->portlineedit->text();
    clientId = ui->idlineedit->text();

    /*
    Client(const QHostAddress& host = QHostAddress::LocalHost,
           const quint16 port = 1883,
           QObject* parent = nullptr); 
	*/
    client = new QMQTT::Client();

    connect(client, &QMQTT::Client::connected, this, &MainWindow::myConnectToHost);
    connect(client, &QMQTT::Client::disconnected, this, &MainWindow::myDisConnectToHost);
    connect(client, &QMQTT::Client::received, this, &MainWindow::myReceive);

    client->setHostName(addr);
    client->setPort(port.toInt());
    client->setClientId(clientId);

    client->connectToHost();
}

void MainWindow::myConnectToHost()
{
    isConnect = true;
    ui->linkbt->setStyleSheet("background-color: green");
}

void MainWindow::myDisConnectToHost()
{
    isConnect = false;
    ui->linkbt->setStyleSheet("background-color: white;color: black");
    if (client) {
        client->deleteLater();
        client = nullptr;
    }
}

void MainWindow::myReceive(const QMQTT::Message &message)
{
    QString topic = message.topic();
    QByteArray payload = message.payload();
    QString msg = QString("%1 %2").arg(topic).arg(QString::fromUtf8(payload));
    ui->textBrowser->append(msg);
}

void MainWindow::on_subbt_clicked()
{
    if (isConnect) {
        QString subscribe = ui->subtopiclineedit->text();
        if (subscribedTopics.contains(subscribe)) {
            QMessageBox::warning(this, "警告", "已经订阅过了");
            return;
        }
        subscribedTopics.push_back(subscribe);
        client->subscribe(subscribe);
    } else {
        qDebug() << "未连接到服务器";
    }
}

void MainWindow::on_publishbt_clicked()
{
    QString topicStr = ui->topiclineedit->text();
    QString contentStr = ui->msglineedit->text();
    /*
    explicit Message(const quint16 id, const QString &topic, const QByteArray &payload,
                     const quint8 qos = 0, const bool retain = false, const bool dup = false); 
	*/
    QMQTT::Message message(clientId.toInt(), topicStr, contentStr.toUtf8());
    client->publish(message);
}
