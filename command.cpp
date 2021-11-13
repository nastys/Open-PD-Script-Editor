#include "command.h"
#include "helper/pdtime.h"

int getTimeFromTimeCommand(QString command)
{
    return command.split('(').at(1).simplified().split(')').at(0).toInt();
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
    return pdtime_string(pdtime_split(divaTime));
}

bool insertBranch(QStringList &commandList, int line, int branch, QString suffix)
{
    if(branch<0) return 1;

    if(findBranchOfCommand(commandList, line)!=branch)
    {
        commandList.insert(line, "PV_BRANCH_MODE("+QString::number(branch)+")"+suffix);
        return 1;
    }

    return 0;
}

bool insertCommand(QStringList &commandList, int time, QString command, int branch, QString suffix)
{
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i).simplified();
        if(currentCommand.startsWith("TIME(") && i<commandList.length()-1)
        {
            int thisTimeCommand=getTimeFromTimeCommand(currentCommand);
            const int thisTimeCommandLine=i;
            if(thisTimeCommand==time)
            {
                commandList.insert(thisTimeCommandLine+1, command);
                return insertBranch(commandList, thisTimeCommandLine, branch, suffix);
            }
            else if(thisTimeCommand>time)
            {
                commandList.insert(thisTimeCommandLine-1, command);
                commandList.insert(thisTimeCommandLine-1, "TIME("+QString::number(time)+')'+suffix);
                return insertBranch(commandList, thisTimeCommandLine, branch, suffix);
            }
        }
        else if(i==commandList.length()-1) // insert TIME + command before PV_END()'s TIME
        {
            int pvEndTime = findTimeOfCommand(commandList, "PV_END()"+suffix);
            if(pvEndTime == -1) pvEndTime = findTimeOfCommand(commandList, "END()"+suffix);
            if(pvEndTime == -1) pvEndTime = commandList.length()-1;
            commandList.insert(pvEndTime-1, command);
            commandList.insert(pvEndTime-1, "TIME("+QString::number(time)+')'+suffix);
            return insertBranch(commandList, pvEndTime-1, branch, suffix);
        }
    }
    return 0; // not inserted
}

bool removeCommand(QStringList &commandList, int time, QString command)
{
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i).simplified();
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
        if(commandList.length()<=i) continue;
        const QString currentCommand=commandList.at(i).simplified();
        if(currentCommand.startsWith("TIME("))
            lastTime = i;
        if(currentCommand.startsWith(command))
            return lastTime;
    }

    return -1;
}

int findTimeOfCommand(QPlainTextEdit &qte, int line)
{
    QStringList docList = qte.document()->toPlainText().split('\n'/*, QString::SkipEmptyParts*/);
    return findTimeOfCommand(docList, line);
}

int findTimeOfCommand(QStringList &commandList, int line)
{
    int lastTime=-1;
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i).simplified();
        if(currentCommand.startsWith("TIME("))
            lastTime = i;
        if(line==i)
            return lastTime;
    }

    return -1;
}

char findBranchOfCommand(QPlainTextEdit &qte, int line)
{
    int lastBranch=0;
    QStringList docList = qte.document()->toPlainText().split('\n'/*, QString::SkipEmptyParts*/);
    for(int i=0; i<qte.document()->lineCount(); i++)
    {
        if(docList.length()<=i) continue;
        const QString currentCommand=docList.at(i).simplified();
        if(currentCommand.startsWith("PV_BRANCH_MODE("))
            lastBranch = currentCommand.split('(').at(1).split(')').at(0).toInt();
        if(line == i)
            switch(lastBranch)
            {
                case 1:
                    return 'F';
                case 2:
                    return 'S';
                default:
                    return 'D';
            }
    }

    return 'D';
}

int findBranchOfCommand(QStringList &commandList, int line)
{
    int lastBranch=-1;
    for(int i=0; i<commandList.length(); i++)
    {
        const QString currentCommand=commandList.at(i).simplified();
        if(currentCommand.startsWith("PV_BRANCH_MODE("))
            lastBranch = i;
        if(i==line)
        {
            if(lastBranch < 0) return 0;
            QStringList split = commandList.at(lastBranch).simplified().split(')');
            if(split.length()>0)
            {
                return split.at(0).mid(15).toInt();
            }
            return -1;
        }
    }

    return -1;
}
