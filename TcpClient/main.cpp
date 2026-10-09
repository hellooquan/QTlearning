#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.connectToServer("192.168.45.1", 10000);

    return QApplication::exec();
}
