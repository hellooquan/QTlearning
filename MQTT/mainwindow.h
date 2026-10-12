#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmqtt.h"

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
    void myConnectToHost();
    void myDisConnectToHost();
    void myReceive(const QMQTT::Message &message);
    void on_linkbt_clicked();
    void on_subbt_clicked();
    void on_publishbt_clicked();

private:
    Ui::MainWindow *ui;
    QMQTT::Client *client;
    bool isConnect;
    QList<QString> subscribedTopics;
    QString clientId;
};
#endif // MAINWINDOW_H
