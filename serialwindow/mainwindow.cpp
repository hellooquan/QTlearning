#include "mainwindow.h"
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto ret = QSerialPortInfo::availablePorts();

    //遍历容器，打印所有的串口
    for (auto &x : ret) {
        ui->comboBox->addItem(x.portName());
    }

    //波特率下拉框显示波特率
    ui->comboBox_2->addItem("9600");
    ui->comboBox_2->addItem("115200");

    //数据位显示
    ui->comboBox_4->addItem("5");
    ui->comboBox_4->addItem("6");
    ui->comboBox_4->addItem("7");
    ui->comboBox_4->addItem("8");

    //校验
    ui->comboBox_3->addItem("odd");
    ui->comboBox_3->addItem("even");
    ui->comboBox_3->addItem("none");

    //停止位
    ui->comboBox_5->addItem("1");
    ui->comboBox_5->addItem("1.5");
    ui->comboBox_5->addItem("2");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSerialPort::DataBits MainWindow::toDataBits(const QString &str)
{
    if (str == "5")
        return QSerialPort::Data5;
    if (str == "6")
        return QSerialPort::Data6;
    if (str == "7")
        return QSerialPort::Data7;
    if (str == "8")
        return QSerialPort::Data8;
    return QSerialPort::Data8;
}

QSerialPort::Parity MainWindow::toParity(const QString &str)
{
    if (str == "odd")
        return QSerialPort::OddParity;
    if (str == "even")
        return QSerialPort::EvenParity;
    if (str == "none")
        return QSerialPort::NoParity;
    return QSerialPort::NoParity;
}

QSerialPort::StopBits MainWindow::toStopBits(const QString &str)
{
    if (str == "1")
        return QSerialPort::OneStop;
    if (str == "1.5")
        return QSerialPort::OneAndHalfStop;
    if (str == "2")
        return QSerialPort::TwoStop;
    return QSerialPort::OneStop;
}

void MainWindow::on_pushButton_3_clicked()
{
    QString portStr = ui->comboBox->currentText();
    QString baudRateStr = ui->comboBox_2->currentText();
    QString dateBitsStr = ui->comboBox_4->currentText();
    QString parityStr = ui->comboBox_3->currentText();
    QString stopBitsStr = ui->comboBox_5->currentText();

    QSerialPort *serialPort = new QSerialPort(this);
    serialPort->setPortName(portStr);
    serialPort->setBaudRate(baudRateStr.toInt());
    serialPort->setDataBits(toDataBits(dateBitsStr));
    serialPort->setParity(toParity(parityStr));
    serialPort->setStopBits(toStopBits(stopBitsStr));
}
