#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

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

public:
    void connectToServer(const QString &ipStr, quint16 port);
private slots:
    void clientConnect();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *m_socket;
};
#endif // MAINWINDOW_H
