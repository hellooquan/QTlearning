#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QString>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString domain = "www";
    domain.append(".");
    domain = domain + "yueqian" + ".com";
    qDebug() << domain; //www.yueqian.com
    qDebug() << domain.size();
    qDebug() << domain.length();

    qDebug() << domain.section(".", 0, 1);

    QStringList list = domain.split(".");
    qDebug() << list;

    QString timestr = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString function = "main";
    QString msg = "good";
    QString info = QString("[%1] [INFO] [%2] [%3]").arg(timestr).arg(function).arg(msg);
    qDebug() << info;

    QString firststr = "123";
    QString secondstr = "456";
    double result = firststr.toDouble() + secondstr.toDouble();
    qDebug() << result;
    QString resultstr = QString::number(result);
    qDebug() << resultstr;

    QString tmp = "hello QT";
    QByteArray array = tmp.toUtf8();
    const char *p = tmp.toUtf8().data();
    qDebug() << tmp;
    qDebug() << array;
    qDebug() << p;

    return QApplication::exec();
}
