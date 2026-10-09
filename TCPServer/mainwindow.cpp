#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Server = new QTcpServer(this);

    m_Server->listen(QHostAddress::Any, 8888);

    connect(m_Server, SIGNAL(newConnection()), this, newClientLink());
}

void MainWindow::newClientLink() {}

MainWindow::~MainWindow()
{
    delete ui;
}
