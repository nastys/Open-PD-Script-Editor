#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>
#include <QPlainTextEdit>

int getTimeFromTimeCommand(QString command);
int vttTimeToDivaTime(QString &time);
QString hmsTimeFromDivaTime(int divaTime);
bool insertCommand(QStringList &commandList, int time, QString command, int branch = -1, QString suffix = "");
bool insertBranch(QStringList &commandList, int line, int branch, QString suffix = "");
bool removeCommand(QStringList &commandList, int time, QString command);
int findTimeOfCommand(QStringList &commandList, QString command);
int findTimeOfCommand(QPlainTextEdit &qte, int line);
int findTimeOfCommand(QStringList &commandList, int line);
char findBranchOfCommand(QPlainTextEdit &qte, int line);
int findBranchOfCommand(QStringList &commandList, int line);

#endif // COMMAND_H
