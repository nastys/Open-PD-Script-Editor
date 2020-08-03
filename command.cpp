#include "command.h"

int getTimeFromTimeCommand(QString command)
{
    return command.split('(').at(1).simplified().remove(')').toInt();
}

int vttTimeToDivaTime(QString &time)
{
    QStringList timesplit=time.split(':');
    QString msecs="00000";
    QString mins="00";
    QString hours="00";
    if(timesplit.length()>2)
    {
        msecs=timesplit.at(2).simplified().remove('.');
        mins=timesplit.at(1).simplified();
        hours=timesplit.at(0).simplified();
    }
    else
    {
        msecs=timesplit.at(1).simplified().remove('.');
        mins=timesplit.at(0).simplified();
    }
    return ((msecs.toInt() + (mins.toInt()*60 + hours.toInt()*3600)*1000)*100);
}

QString hmsTimeFromDivaTime(int divaTime)
{
    int seconds = 0, minutes = 0, hours = 0;
    for(int i=0; i<divaTime; i++)
    {
        seconds++;
        if(seconds>=6000000)
        {
            seconds=0;
            minutes++;
            if(minutes>=60)
            {
                minutes=0;
                hours++;
            }
        }
    }
    QString strhours=QString::number(hours, 10);
    if(strhours.length()<2) strhours.prepend('0');
    QString strminutes=QString::number(minutes, 10);
    if(strminutes.length()<2) strminutes.prepend('0');
    QString strseconds=QString::number(seconds, 10);
    while(strseconds.length()<6) strseconds.prepend('0');
    strseconds.insert(2, '.');
    return strhours+':'+strminutes+':'+strseconds;
}

bool insertCommand(QStringList &commandList, int time, QString command)
{
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
        {
            const int tfc=getTimeFromTimeCommand(currentCommand);
            if(tfc==time)
            {
                int p=i+1;
                while(getTimeFromTimeCommand(commandList.at(findTimeOfCommand(commandList, p)))<=tfc&&p<commandList.length()-1)
                    p++;
                commandList.insert(p, command);
                return 1;
            }
            else if(tfc>time)
            {
                commandList.insert(i, command);
                commandList.insert(i, "TIME("+QString::number(time)+")");
                return 1;
            }
        }
        else if(i==commandList.length()-1) // insert TIME + command before PV_END()'s TIME
        {
            int pvEndTime = findTimeOfCommand(commandList, "PV_END()");
            if(pvEndTime == -1) pvEndTime = findTimeOfCommand(commandList, "END()");
            if(pvEndTime == -1) pvEndTime = commandList.length()-1;
            commandList.insert(pvEndTime-1, command);
            commandList.insert(pvEndTime-1, "TIME("+QString::number(time)+")");
            return 1;
        }
    }
    return 0; // not inserted
}

bool removeCommand(QStringList &commandList, int time, QString command)
{
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
        {
            const int tfc=getTimeFromTimeCommand(currentCommand);
            if(tfc==time)
            {
                int p=i;
                do
                {
                    p++;
                    if(commandList.at(p).startsWith("TIME("))
                        return 0;
                }
                while(!commandList.at(p).startsWith(command));
                commandList.removeAt(p);
                return 1;
            }
        }
    }
    return 0; // not removed
}

int findTimeOfCommand(QStringList &commandList, QString command)
{
    int lastTime=-1;
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
            lastTime = i;
        if(currentCommand.startsWith(command))
            return lastTime;
    }

    return -1;
}

int findTimeOfCommand(QTextEdit &qte, int line)
{
    int lastTime=-1;
    QStringList docList = qte.document()->toPlainText().split('\n', QString::SkipEmptyParts);
    for(int i=0; i<qte.document()->lineCount(); i++)
    {
        const QString currentCommand=docList.at(i);
        if(currentCommand.startsWith("TIME("))
            lastTime = i;
        if(line == i)
            return lastTime;
    }

    return -1;
}

int findTimeOfCommand(QStringList &commandList, int line)
{
    int lastTime=-1;
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
        lastTime = i;
        if(line==i)
        return lastTime;
    }

    return -1;
}
