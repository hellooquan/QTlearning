#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_3_clicked();

private:
    QSerialPort::DataBits toDataBits(const QString &str);
    QSerialPort::Parity toParity(const QString &str);
    QSerialPort::StopBits toStopBits(const QString &str);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
