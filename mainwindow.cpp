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
#include <QTextBlock>
#include <QCheckBox>
#include <QScrollArea>

static int pvslot=1;
static bool isLoading=false;

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
    isLoading=true;
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend/DT2/DTE edit") DivaScriptOpcode_DIVA2Edit::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone/MEGA39's") DivaScriptOpcode_FT::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend") DivaScriptOpcode_F::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA F 2nd") DivaScriptOpcode_F2::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA X") DivaScriptOpcode_X::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project Mirai") DivaScriptOpcode_Mirai::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Miracle Girls Festival") DivaScriptOpcode_MGF::readAll(file, qds, ui->textEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    isLoading=false;
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
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone/MEGA39's") DivaScriptOpcode_FT::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend") DivaScriptOpcode_F::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA F 2nd") DivaScriptOpcode_F2::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA X") DivaScriptOpcode_X::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project Mirai") DivaScriptOpcode_Mirai::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Miracle Girls Festival") DivaScriptOpcode_MGF::writeAll(file, qds, ui->textEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
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
    fromVtt(ifile, ui->textEdit, ui->plainTextEdit_db, pvslot);
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
    if(result) LipSync_v1_0::lipsyncFromVtt(ui->textEdit, ifile, diag->settings);
    ifile.close();
    delete diag;
}

void MainWindow::on_actionPDA_2_00_to_PDA_1_01_triggered()
{
    QStringList commandlist;
    commandlist=ui->textEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "").replaceInStrings(" ", "");
    ui->textEdit->clear();
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
        else if(opcode==0x1F/*MOVE_CAMERA*/) {parameters.removeLast(); parameters.removeLast();}
        int paramcount=DivaScriptOpcode_PDA::getOpcodeParamCount(opcode);
        while(parameters.length()>paramcount) parameters.removeFirst();
        QString finalcommand = command.at(0)+'(';
        for(int j=0; j<parameters.length(); j++)
        {
            if(j>0) finalcommand.append(", ");
            finalcommand.append(parameters.at(j));
        }
        finalcommand.append(");");
        ui->textEdit->append(finalcommand);
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
    QStringList commandlist;
    commandlist=ui->textEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "");
    ui->textEdit->clear();
    for(int i=0; i<commandlist.length(); i++)
    {
        QStringList command = commandlist.at(i).split('(');
        if(command.at(0)!=idcommand)
        {
            ui->textEdit->append(commandlist.at(i)+';');
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
        ui->textEdit->append(finalcommand);
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
    commandlist=ui->textEdit->document()->toPlainText().split(';', QString::SkipEmptyParts).replaceInStrings("\n", "");
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
            ui->textEdit->append(commandlist.at(i)+';');
            continue;
        }
        ui->textEdit->append(finalcommand);
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Open PD Script Editor", "MIT License\nCopyright (c) 2020 nastys\n\nPermission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:\n\nThe above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
    QMessageBox i8about;
    i8about.setTextFormat(Qt::RichText);
    //i8about.setIcon();
    i8about.setText("Icons by Icons8<br><a href='https://icons8.it/'>https://icons8.it</a>");
    i8about.setStandardButtons(QMessageBox::Ok);
    //i8about.setParent(this);
    i8about.exec();
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    if(isLoading) return;

    QLayout *curlayout = ui->frame_paramEdit->layout();
    if ( curlayout != NULL )
    {
        QLayoutItem* item;
        while ( ( item = curlayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        delete curlayout->layout();
    }

    QTextEdit *edit = qobject_cast<QTextEdit *>(sender());
    Q_ASSERT(edit);
    QTextCursor cursor = edit->textCursor();
    cursor.movePosition(QTextCursor::StartOfLine);

    int line = 0;
    while(cursor.positionInBlock()>0) {
        cursor.movePosition(QTextCursor::Up);
        line++;
    }
    QTextBlock block = cursor.block().previous();

    while(block.isValid()) {
        line += block.lineCount();
        block = block.previous();
    }

    QScrollArea *scrollarea = new QScrollArea();
    QWidget *frame = new QWidget(scrollarea);
    QVBoxLayout *layout = new QVBoxLayout(frame);
    scrollarea->setWidgetResizable(true);
    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    scrollarea->setFrameStyle(QFrame::Plain);
    scrollarea->setWidget(frame);
    ui->statusBar->showMessage("Line "+QString::number(line+1));
    QString currline=ui->textEdit->document()->findBlockByLineNumber(line).text();
    if(currline.endsWith(");")) // TODO make it game-specific instead of assuming PDA 2.00
    {
        if(currline.startsWith("TIME("))
        {
            QLabel *label = new QLabel("Time");
            label->setStyleSheet("font-weight: bold");
            layout->addWidget(label);
            QFrame *separator = new QFrame;
            separator->setFrameShape(QFrame::HLine);
            separator->setFrameShadow(QFrame::Sunken);
            layout->addWidget(new QLabel("Waits until this timestamp."));
            layout->addWidget(separator);
            QString timestr=currline.mid(5, currline.length()-7);
            unsigned long long divatime=timestr.toULongLong(), seconds=0, minutes=0, hours=0;
            for(unsigned long long i=0; i<divatime; i++)
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
            QString timestr_fn=strhours+':'+strminutes+':'+strseconds;
            ui->lineEdit_time->setText(timestr_fn); // TODO check the time of any command and update lineEdit_time accordingly

            layout->addWidget(new QLabel("Hours:"));
            QSpinBox *sb_hours = new QSpinBox;
            sb_hours->setValue(hours);
            layout->addWidget(sb_hours);
            QSpinBox *sb_minutes = new QSpinBox;
            sb_minutes->setRange(0, 59);
            sb_minutes->setValue(minutes);
            layout->addWidget(new QLabel("Minutes:"));
            layout->addWidget(sb_minutes);
            QSpinBox *sb_seconds = new QSpinBox;
            sb_seconds->setRange(0, 5999999);
            sb_seconds->setValue(seconds);
            layout->addWidget(new QLabel("Nanoseconds:"));
            layout->addWidget(sb_seconds);
            QCheckBox *cb_move = new QCheckBox;
            cb_move->setText("Move commands");
            layout->addWidget(cb_move);
            layout->addStretch(1);
            QPushButton *pb_apply = new QPushButton;
            pb_apply->setText("Apply");
            layout->addWidget(pb_apply);
        }
        else if(currline.startsWith("TARGET("))
        {
            QStringList par_cs=currline.chopped(2).split('(');
            if(par_cs.length()>=2)
            {
                QStringList parameters_str=par_cs.at(1).split(',');

                QLabel *label = new QLabel("Target");
                label->setStyleSheet("font-weight: bold");
                layout->addWidget(label);
                QFrame *separator = new QFrame;
                separator->setFrameShape(QFrame::HLine);
                separator->setFrameShadow(QFrame::Sunken);
                layout->addWidget(new QLabel("Displays a target."));
                layout->addWidget(separator);

                layout->addWidget(new QLabel("Type:"));
                QComboBox *typecb = new QComboBox;
                if(parameters_str.length()>=1)
                {
                    typecb->addItem(QIcon("qrc:/icons/icons8/color/icons8-cerchio-48.png"), "Circle"); // TODO fix icon
                }
                layout->addWidget(typecb);

                layout->addWidget(new QLabel("Horizontal position:"));
                QSpinBox *posx = new QSpinBox;
                posx->setRange(0, 128000);
                if(parameters_str.length()>=2) posx->setValue(parameters_str.at(1).toInt());
                layout->addWidget(posx);

                layout->addWidget(new QLabel("Vertical position:"));
                QSpinBox *posy = new QSpinBox;
                posy->setRange(0, 72000);
                if(parameters_str.length()>=3) posy->setValue(parameters_str.at(2).toInt());
                layout->addWidget(posy);

                layout->addWidget(new QLabel("Angle:"));
                QSpinBox *angle = new QSpinBox;
                angle->setRange(INT_MIN, INT_MAX);
                if(parameters_str.length()>=4) angle->setValue(parameters_str.at(3).toInt());
                layout->addWidget(angle);

                layout->addWidget(new QLabel("Distance:"));
                QSpinBox *distance = new QSpinBox;
                distance->setRange(INT_MIN, INT_MAX);
                if(parameters_str.length()>=5) distance->setValue(parameters_str.at(4).toInt());
                layout->addWidget(distance);

                layout->addWidget(new QLabel("Amplitude:"));
                QSpinBox *amplitude = new QSpinBox;
                amplitude->setRange(INT_MIN, INT_MAX);
                if(parameters_str.length()>=6) amplitude->setValue(parameters_str.at(5).toInt());
                layout->addWidget(amplitude);

                layout->addWidget(new QLabel("Wave count:"));
                QSpinBox *wavecount = new QSpinBox;
                wavecount->setRange(INT_MIN, INT_MAX);
                if(parameters_str.length()>=7) wavecount->setValue(parameters_str.at(6).toInt());
                layout->addWidget(wavecount);

                QPushButton *pb_apply = new QPushButton;
                pb_apply->setText("Apply");
                layout->addWidget(pb_apply);
            }
        }
        else
        {
            QStringList par_cs=currline.chopped(2).split('(');
            if(par_cs.length()>=2)
            {
                QLabel *label = new QLabel(par_cs.at(0));
                label->setStyleSheet("font-weight: bold");
                layout->addWidget(label);
                QFrame *separator = new QFrame;
                separator->setFrameShape(QFrame::HLine);
                separator->setFrameShadow(QFrame::Sunken);
                layout->addWidget(separator);
                QStringList parameters_str=par_cs.at(1).split(',');
                if(parameters_str.length()>0&&!(parameters_str.at(0).isNull()||parameters_str.at(0).isEmpty()))
                {
                    for(int i=0; i<parameters_str.length(); i++)
                    {
                        layout->addWidget(new QLabel("Parameter "+QString::number(i+1)+':'));
                        QSpinBox *spinbox=new QSpinBox;
                        spinbox->setRange(INT_MIN, INT_MAX);
                        spinbox->setValue(parameters_str.at(i).toInt());
                        layout->addWidget(spinbox);
                    }
                    layout->addStretch(1);
                    QPushButton *pb_apply = new QPushButton;
                    pb_apply->setText("Apply");
                    layout->addWidget(pb_apply);
                }
                else layout->addStretch(1);
            }
        }
    }
    QLayout *container = new QGridLayout;
    container->setMargin(0);
    container->setContentsMargins(0, 0, 0, 0);
    container->addWidget(scrollarea);
    ui->frame_paramEdit->setLayout(container);
}
