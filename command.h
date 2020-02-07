#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>

int getTimeFromTimeCommand(QString command);
int vttTimeToDivaTime(QString &time);
bool insertCommand(QStringList &commandList, int time, QString command);
bool removeCommand(QStringList &commandList, int time, QString command);

#endif // COMMAND_H
