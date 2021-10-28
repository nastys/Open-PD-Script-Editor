#include "logger.h"

void logger::initlogfile()
{
    logfile = new QFile;
    logfile->setFileName("log.txt");
    logfile->open(QIODevice::ReadWrite);
}

void logger::log(QString text)
{
    logfile->write(text.toUtf8());
    logfile->flush();
}
