#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>
#include <QTextEdit>

int getTimeFromTimeCommand(QString command);
int vttTimeToDivaTime(QString &time);
QString hmsTimeFromDivaTime(int divaTime);
bool insertCommand(QStringList &commandList, int time, QString command);
bool removeCommand(QStringList &commandList, int time, QString command);
int findTimeOfCommand(QStringList &commandList, QString command);
int findTimeOfCommand(QTextEdit &qte, int line);
int findTimeOfCommand(QStringList &commandList, int line);

#endif // COMMAND_H
