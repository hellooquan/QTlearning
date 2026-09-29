#include <QCoreApplication>
#include "receiver.h"
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender send;
    Receiver recv;

    QObject::connect(&send, &Sender::signalName, &recv, &Receiver::slotName);

    emit send.signalName();

    return QCoreApplication::exec();
}
