#include "mainwindow.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    w.show();
    w.setWindowTitle("QTwindow");

    QWidget sw(&w, Qt::Window | Qt::FramelessWindowHint);
    sw.show();
    sw.resize(300, 300);

    return QApplication::exec();
}
