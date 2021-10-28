#ifndef DEBUG_H
#define DEBUG_H

#include <QtGlobal>

#ifdef QT_DEBUG
#include <QDebug>
#define debugger(out); qDebug()<<out;
#else
#define debugger(out);
#endif

#endif // DEBUG_H
