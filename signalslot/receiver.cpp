#include "receiver.h"
#include <QDebug>

Receiver::Receiver(QObject *parent)
    : QObject{parent}
{}

void Receiver::slotName()
{
    qDebug() << "i'm slot";
}