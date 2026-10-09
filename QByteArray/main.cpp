#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray chararr;
    chararr.resize(5);
    chararr[0] = 'a';
    chararr[1] = 'b';
    chararr[2] = 'c';
    chararr[3] = 'd';
    chararr[4] = 'e';
    qDebug() << chararr;

    QByteArray chararr2 = chararr;
    qDebug() << chararr2;

    QByteArray chararr3("abcde");
    qDebug() << chararr3;

    QByteArray chararr4(10, 'a');
    qDebug() << chararr4;

    qDebug() << chararr << chararr2 << chararr3 << chararr4;

    QByteArray encoded = chararr.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);
    qDebug() << encoded << decoded;

    const char *q = chararr.data();
    qDebug() << q;

    QByteArray mychararr;
    mychararr.resize(5);
    const char *char1 = "hello";
    mychararr.setRawData(char1, 5);
    QByteArray mychararr2 = mychararr.toHex();
    qDebug() << mychararr << mychararr2;

    return QCoreApplication::exec();
}
