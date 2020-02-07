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

bool insertCommand(QStringList &commandList, int time, QString command)
{
    for(int i=0; i<commandList.length(); i++)
    {
        QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
        {
            int tfc=getTimeFromTimeCommand(currentCommand);
            if(tfc==time)
            {
                int p=i;
                do p++;
                while(!commandList.at(p).startsWith("TIME("));
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
        /*else if(i==commandList.length()-1)
        {
            commandList.insert(i, command);
            commandList.insert(i, "TIME("+QString::number(time)+")");
            return 1;
        }*/
    }
    return 0; // not inserted
}

bool removeCommand(QStringList &commandList, int time, QString command)
{
    for(int i=0; i<commandList.length(); i++)
    {
        QString currentCommand=commandList.at(i);
        if(currentCommand.startsWith("TIME("))
        {
            int tfc=getTimeFromTimeCommand(currentCommand);
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
