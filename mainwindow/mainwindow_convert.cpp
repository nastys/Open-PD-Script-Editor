#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_actionPDA_2_00_to_PDA_1_01_triggered()
{
    DivaScriptOpcode_PDA DSO(ui->textEdit_Log);

    QStringList commandlist;
    commandlist=ui->textEdit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    ui->textEdit->clear();
    for(int i=0; i<commandlist.length();)
    {
        QStringList command = commandlist.at(i).split('(');
        int opcode=DSO.getOpcodeNumber(command.at(0));
        if(opcode==-1)
        {
            i++;
            continue;
        }
        QStringList parameters = command.at(1).split(')').at(0).split(',');
        if(opcode==0x18/*LYRIC*/) parameters.removeLast();
        else if(opcode==0x1F/*MOVE_CAMERA*/) {parameters.removeLast(); parameters.removeLast();}
        int paramcount=DSO.getOpcodeParamCount(opcode);
        while(parameters.length()>paramcount) parameters.removeFirst();
        QString finalcommand = command.at(0)+'(';
        for(int j=0; j<parameters.length(); j++)
        {
            if(j>0) finalcommand.append(", ");
            finalcommand.append(parameters.at(j));
        }
        finalcommand.append(");");
        ui->textEdit->insertPlainText(finalcommand);
        i++;
    }
}

int getNewID(int oldID, QString idcommand)
{
    if(idcommand=="MOUTH_ANIM")
    {
        switch(oldID)
        {
        case 6:
            return 28;
        case 0:
            return 24;
        case 2:
            return 25;
        case 3:
            return 26;
        case 4:
            return 27;
        case 8:
            return 29;
        case 10:
            return 29;
        case 9:
            return 30;
        case 1:
            return 31;
        case 5:
            return 32;
        case 7:
            return 33;

        case 23:
            return 6;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 4;
        case 28:
            return 6;
        case 29:
            return 8;
        case 30:
            return 9;
        case 31:
            return 1;
        case 32:
            return 5;
        case 33:
            return 7;
        }
    }
    else if(idcommand=="EXPRESSION")
    {
        switch(oldID)
        {
        case 52:
            return 0;
        case 53:
            return 3;
        case 54:
            return 6;
        case 55:
            return 8;
        case 56:
            return 9;
        case 57:
            return 10;
        case 58:
            return 11;
        case 59:
            return 12;
        case 65:
            return 2;
        case 66:
            return 1;
        case 68:
            return 5;
        case 70:
            return 7;
        case 72:
            return 13;
        case 73:
            return 14;

        case 0:
            return 52;
        case 3:
            return 53;
        case 6:
            return 54;
        case 8:
            return 55;
        case 9:
            return 56;
        case 2:
            return 65;
        case 1:
            return 66;
        case 10:
            return 57;
        case 11:
            return 58;
        case 12:
            return 59;
        case 5:
            return 68;
        case 7:
            return 70;
        case 13:
            return 72;
        case 14:
            return 73;

        case 4:
            return oldID;
        }
    }
    else if(idcommand=="HAND_ANIM")
    {
        switch(oldID)
        {
        case 9:
            return 8;
        case 11:
            return 10;

        case 8:
            return 9;
        case 10:
            return 11;

        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            return oldID;
        }
    }
    else if(idcommand=="LOOK_ANIM")
    {
        if(oldID<11)
            return oldID+11;

        return oldID-11;
    }

    QMessageBox::warning(nullptr, "Warning", "Unknown "+idcommand+ " ID "+QString::number(oldID)+'.');
    return oldID;
}

void MainWindow::replaceID(QString idcommand)
{
    DivaScriptOpcode_PDA DSO(ui->textEdit_Log);

    QStringList commandlist;
    commandlist=ui->textEdit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "");
    ui->textEdit->clear();
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList command = commandlist.at(i).split('(');
        if(command.at(0)!=idcommand)
        {
            ui->textEdit->insertPlainText(commandlist.at(i)+';');
            continue;
        }
        int opcode=DSO.getOpcodeNumber(command.at(0));
        if(opcode==-1) continue;
        QStringList parameters = command.at(1).split(')').at(0).split(',');

        int offset=0;

        if(idcommand=="HAND_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked()==false)
            offset=2;
        else if(idcommand=="HAND_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked())
            offset=1;
        else if(idcommand=="MOUTH_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked()==false)
            offset=2;
        else if(idcommand=="MOUTH_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked())
            offset=0;
        else if(idcommand=="EXPRESSION"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked()==false)
            offset=1;
        else if(idcommand=="EXPRESSION"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked())
            offset=0;
        else if(idcommand=="LOOK_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked()==false)
            offset=1;
        else if(idcommand=="LOOK_ANIM"&&ui->actionI_have_already_converted_the_DSC_to_PDA_1_01->isChecked())
            offset=0;

        QString spc="";
        if(offset>0) spc.append(' ');
        parameters[offset]=spc+QString::number(getNewID(parameters.at(offset).toInt(), idcommand));
        QString finalcommand = command.at(0)+'(';
        for(int j=0; j<parameters.length(); j++)
        {
            if(j>0) finalcommand.append(',');
            finalcommand.append(parameters.at(j));
        }
        finalcommand.append(");");
        ui->textEdit->insertPlainText(finalcommand);
    }
}

void MainWindow::on_action_FT_new_mouth_to_FT_old_mouth_triggered()
{
    replaceID("MOUTH_ANIM");
}

void MainWindow::on_action_Look_FT_old_look_triggered()
{
    replaceID("LOOK_ANIM");
}

void MainWindow::on_action_Expressions_FT_old_expressions_triggered()
{
    replaceID("EXPRESSION");
}

void MainWindow::on_action_Hand_animations_FT_old_animations_triggered()
{
    replaceID("HAND_ANIM");
}

void MainWindow::on_actionAll_of_them_triggered()
{
    replaceID("MOUTH_ANIM");
    replaceID("LOOK_ANIM");
    replaceID("EXPRESSION");
    replaceID("HAND_ANIM");
}

void MainWindow::on_actionBAR_TIME_SET_TARGET_FLYING_TIME_triggered()
{
    QStringList commandlist;
    commandlist=ui->textEdit->document()->toPlainText().split(';', Qt::SkipEmptyParts).replaceInStrings("\n", "");
    ui->textEdit->clear();
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList command = commandlist.at(i).split('(');
        QString finalcommand;
        if(command.at(0)=="TARGET_FLYING_TIME")
        {
            double tft = command.at(1).split(')').at(0).toInt();
            int bpm=qRound(240000.00/tft);
            finalcommand="BAR_TIME_SET("+QString::number(bpm)+", 3);";
        }
        else if(command.at(0)=="BAR_TIME_SET")
        {
            QStringList parameters = command.at(1).split(')').at(0).split(',');
            double bpm = parameters.at(0).toInt();
            double ts = parameters.at(1).toInt();
            int tft=qRound(1000.0 / (bpm / ((ts + 1) * 60.0)));
            finalcommand="TARGET_FLYING_TIME("+QString::number(tft)+");";
        }
        else
        {
            ui->textEdit->insertPlainText(commandlist.at(i)+';');
            continue;
        }
        ui->textEdit->insertPlainText(finalcommand);
    }
}
