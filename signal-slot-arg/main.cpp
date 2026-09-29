#include <QCoreApplication>
#include "mywidget.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyWidget *widget = new MyWidget();
    QObject::connect(widget, &MyWidget::mySignal, widget, &MyWidget::mySlot);

    widget->mySignal("hello QT", 666);

    return QCoreApplication::exec();
}
