#include "logger.h"
#include "ui_mainwindow.h"
#include <QDateTime>

logger::logger(Ui::MainWindow *uiptr) :ui(uiptr){}

void logger::info(QString objtype,QString msg)
{
    QString datetimestr=QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString info=QString("[%1] [INFO] [%2] [%3]").arg(datetimestr).arg(objtype).arg(msg);
    qDebug()<<info;
    ui->textBrowser->append(info);
}
