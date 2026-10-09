#include "mainwindow.h"
#include <QHostAddress>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket(this);

    m_socket->bind(QHostAddress("127.0.0.1"), 8888);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_puahButton_clicked()));
}

void MainWindow::connectToServer(const QString &ipStr, quint16 port)
{
    m_socket->connectToHost(QHostAddress(ipStr), port);
}

void MainWindow::clientConnect()
{
    QString msg = ui->textEdit->toPlainText();
    m_socket->write(msg.toUtf8());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    connect(m_socket, SIGNAL(connected()), this, SLOT(clientConnect()));
}
