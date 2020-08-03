#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>

static QFile *logfile;

class logger
{
public:
    static void initlogfile();
    static void log(QString text);
};

#endif // LOGGER_H
