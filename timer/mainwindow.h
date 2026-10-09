#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void on_pushButton_clicked();
    void showPicture();
    void showTime();
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer1;
    QTimer *timer2;
    QPixmap *pixmap;
};
#endif // MAINWINDOW_H
