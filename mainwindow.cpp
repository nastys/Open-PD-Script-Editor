#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DSC.cpp"
#include "lyrics.cpp"
#include "diag_lipsync.h"
#include "lipsync_v1_0.cpp"
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_DSC_triggered()
{
    QStringList filepaths=QFileDialog::getOpenFileNames();
    if(filepaths.isEmpty()) return;
    bool ok;
    QString format=QInputDialog::getItem(this, "Format", "DSC format:", {"Project DIVA", "Project DIVA 2nd/Extend", "Project DIVA 2nd/Extend/DT2/DTE edit", "Project DIVA Arcade/Dreamy Theater", "Project DIVA Arcade 2.00/Future Tone/MEGA39's", "Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend", "Project DIVA F 2nd", "Project DIVA X", "Project Mirai", "Miracle Girls Festival"}, 0, false, &ok);
    if(format.isEmpty()||!ok) return;
    QString filepath=filepaths.at(0);
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QDataStream qds(&file);
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend/DT2/DTE edit") DivaScriptOpcode_DIVA2Edit::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone/MEGA39's") DivaScriptOpcode_FT::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend") DivaScriptOpcode_F::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA F 2nd") DivaScriptOpcode_F2::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA X") DivaScriptOpcode_X::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project Mirai") DivaScriptOpcode_Mirai::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Miracle Girls Festival") DivaScriptOpcode_MGF::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    file.close();
}

void MainWindow::on_actionSave_DSC_triggered()
{
    QString filepath=QFileDialog::getSaveFileName();
    if(filepath.isEmpty()||filepath.isNull()) return;
    bool ok;
    QString format=QInputDialog::getItem(this, "Format", "DSC format:", {"Project DIVA", "Project DIVA 2nd/Extend", "Project DIVA Arcade/Dreamy Theater", "Project DIVA Arcade 2.00/Future Tone/MEGA39's", "Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend", "Project DIVA F 2nd", "Project DIVA X", "Project Mirai", "Miracle Girls Festival"}, 0, false, &ok);
    if(format.isEmpty()||!ok) return;
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.resize(0);
    QDataStream qds(&file);
    qds.setByteOrder(ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone/MEGA39's") DivaScriptOpcode_FT::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend") DivaScriptOpcode_F::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA F 2nd") DivaScriptOpcode_F2::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA X") DivaScriptOpcode_X::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project Mirai") DivaScriptOpcode_Mirai::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Miracle Girls Festival") DivaScriptOpcode_MGF::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

EditWidgets MainWindow::uiEditWidgets()
{
    EditWidgets editWidgets;
    editWidgets.tabedit=ui->tab_edit;
    editWidgets.bartable=ui->tableWidget_edit;
    editWidgets.editname=ui->lineEdit_edit_editname;
    editWidgets.songname=ui->lineEdit_edit_songname;
    editWidgets.songstart=ui->spinBox_edit_starttime;
    editWidgets.modulelist=ui->listWidget_edit_modules;
    editWidgets.stagelist=ui->listWidget_edit_stages;
    editWidgets.motionlist=ui->listWidget_edit_motions;
    editWidgets.effectlist=ui->listWidget_edit_effects;
    editWidgets.handitemlist=ui->listWidget_edit_handitems;
    editWidgets.songend=ui->spinBox_edit_end;
    editWidgets.buttonsfx=ui->spinBox_edit_buttonsfx;

    return editWidgets;
}

void MainWindow::on_actionPSP_to_DT_triggered()
{
    QString ifilepath=QFileDialog::getOpenFileName();
    if(ifilepath.isEmpty()||ifilepath.isNull()) return;

    QString ofilepath=QFileDialog::getSaveFileName();
    if(ofilepath.isEmpty()||ofilepath.isNull()) return;

    QFile ifile(ifilepath);
    ifile.open(QIODevice::ReadOnly);
    QDataStream iqds(&ifile);
    iqds.setByteOrder(QDataStream::ByteOrder::LittleEndian);

    QFile ofile(ofilepath);
    ofile.open(QIODevice::WriteOnly);
    ofile.resize(0);
    QDataStream oqds(&ofile);
    oqds.setByteOrder(QDataStream::ByteOrder::LittleEndian);

    oqds << 1677721600 << 16846880 << 192439748 << -192217088;
    while(!ifile.atEnd())
    {
        int v;
        iqds >> v;
        oqds << v;
    }
    ifile.close();
    ofile.close();
}

void MainWindow::on_actionImport_VTT_triggered()
{
    QString ifilepath=QFileDialog::getOpenFileName();
    if(ifilepath.isEmpty()||ifilepath.isNull()) return;
    QFile ifile(ifilepath);
    ifile.open(QIODevice::ReadOnly);
    fromVtt(ifile, ui->plainTextEdit, ui->plainTextEdit_db, ui->spinBox_pv->value());
    ifile.close();
}

void MainWindow::on_actionLip_sync_triggered()
{
    QString ifilepath=QFileDialog::getOpenFileName();
    if(ifilepath.isEmpty()||ifilepath.isNull()) return;
    QFile ifile(ifilepath);
    ifile.open(QIODevice::ReadOnly);

    diag_lipsync *diag = new diag_lipsync(this);
    bool result = diag->exec();
    if(result) LipSync_v1_0::lipsyncFromVtt(ui->plainTextEdit, ifile, diag->settings);
    ifile.close();
    delete diag;
}

void MainWindow::on_actionPDA_2_00_to_PDA_1_01_triggered()
{
    QStringList commandlist;
    commandlist=ui->plainTextEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    ui->plainTextEdit->clear();
    for(int i=0; i<commandlist.length();)
    {
        QStringList command = commandlist.at(i).split('(');
        int opcode=DivaScriptOpcode_PDA::getOpcodeNumber(command.at(0));
        if(opcode==-1)
        {
            i++;
            continue;
        }
        QStringList parameters = command.at(1).split(')').at(0).split(',');
        if(opcode==0x18/*LYRIC*/) parameters.removeLast();
        int paramcount=DivaScriptOpcode_PDA::getOpcodeParamCount(opcode);
        while(parameters.length()>paramcount) parameters.removeFirst();
        QString finalcommand = command.at(0)+'(';
        for(int j=0; j<parameters.length(); j++)
        {
            if(j>0) finalcommand.append(", ");
            finalcommand.append(parameters.at(j));
        }
        finalcommand.append(");");
        ui->plainTextEdit->appendPlainText(finalcommand);
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
        case 54:
            return 6;
        case 55:
            return 8;
        case 56:
            return 9;
        case 57:
            return 10;
        case 66:
            return 1;
        case 68:
            return 5;

        case 6:
            return 54;
        case 8:
            return 55;
        case 9:
            return 56;
        case 1:
            return 66;
        case 10:
            return 57;
        case 5:
            return 68;
        }
    }
    else if(idcommand=="HAND_ANIM")
    {
        switch(oldID)
        {
        case 0:
            return 0;

        case 1:
            return 1;

        case 11:
            return 10;

        case 10:
            return 11;
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
    QStringList commandlist;
    commandlist=ui->plainTextEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "");
    ui->plainTextEdit->clear();
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList command = commandlist.at(i).split('(');
        if(command.at(0)!=idcommand)
        {
            ui->plainTextEdit->appendPlainText(commandlist.at(i)+';');
            continue;
        }
        int opcode=DivaScriptOpcode_PDA::getOpcodeNumber(command.at(0));
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
        ui->plainTextEdit->appendPlainText(finalcommand);
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
    on_actionBAR_TIME_SET_TARGET_FLYING_TIME_triggered();
}

void MainWindow::on_actionBAR_TIME_SET_TARGET_FLYING_TIME_triggered()
{
    QStringList commandlist;
    commandlist=ui->plainTextEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "");
    ui->plainTextEdit->clear();
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
            ui->plainTextEdit->appendPlainText(commandlist.at(i)+';');
            continue;
        }
        ui->plainTextEdit->appendPlainText(finalcommand);
    }
}
