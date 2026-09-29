#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>

class MyWidget : public QObject
{
    Q_OBJECT
public:
    explicit MyWidget(QObject *parent = nullptr);

signals:
    void mySignal(QString msg, int value);

public slots:
    void mySlot(QString msg, int value);
};

#endif // MYWIDGET_H
