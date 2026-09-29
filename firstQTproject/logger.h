#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

namespace Ui { class MainWindow; }

class logger
{
public:
    logger(Ui::MainWindow *uiptr);
    void info(QString objtype,QString msg);
private:
    Ui::MainWindow *ui;
};

#endif // LOGGER_H
