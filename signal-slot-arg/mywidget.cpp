#include "mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QObject *parent)
    : QObject{parent}
{}

void MyWidget::mySlot(QString msg, int value)
{
    qDebug() << "收到信息：" << msg << "和值：" << value;
}