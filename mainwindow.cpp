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
    QString format=QInputDialog::getItem(this, "Format", "DSC format:", {"Project DIVA", "Project DIVA 2nd/Extend", "Project DIVA 2nd/Extend/DT2/DTE edit", "Project DIVA Arcade/Dreamy Theater", "Project DIVA Arcade 2.00/Future Tone", "Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend", "Project DIVA F 2nd", "Project DIVA X", "Project Mirai", "Miracle Girls Festival"}, 0, false);
    if(format.isEmpty()||format=="CANCEL") return;
    QString filepath=filepaths.at(0);
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QDataStream qds(&file);
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend/DT2/DTE edit") DivaScriptOpcode_DIVA2Edit::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone") DivaScriptOpcode_FT::readAll(file, qds, ui->plainTextEdit, uiEditWidgets(), ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
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
    if(filepath.isEmpty()||filepath=="CANCEL") return;
    QString format=QInputDialog::getItem(this, "Format", "DSC format:", {"Project DIVA", "Project DIVA 2nd/Extend", "Project DIVA Arcade/Dreamy Theater", "Project DIVA Arcade 2.00/Future Tone", "Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend", "Project DIVA F 2nd", "Project DIVA X", "Project Mirai", "Miracle Girls Festival"}, 0, false);
    if(format.isEmpty()) return;
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.resize(0);
    QDataStream qds(&file);
    qds.setByteOrder(ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone") DivaScriptOpcode_FT::writeAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
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
    if(ifilepath.isEmpty()||ifilepath=="CANCEL") return;

    QString ofilepath=QFileDialog::getSaveFileName();
    if(ofilepath.isEmpty()||ofilepath=="CANCEL") return;

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
    if(ifilepath.isEmpty()||ifilepath=="CANCEL") return;
    QFile ifile(ifilepath);
    ifile.open(QIODevice::ReadOnly);
    fromVtt(ifile, ui->plainTextEdit, ui->plainTextEdit_db, ui->spinBox_pv->value());
    ifile.close();
}

void MainWindow::on_actionLip_sync_triggered()
{
    QString ifilepath=QFileDialog::getOpenFileName();
    if(ifilepath.isEmpty()||ifilepath=="CANCEL") return;
    QFile ifile(ifilepath);
    ifile.open(QIODevice::ReadOnly);

    diag_lipsync *diag = new diag_lipsync(this);
    bool result = diag->exec();
    if(result) LipSync_v1_0::lipsyncFromVtt(ui->plainTextEdit, ifile, diag->settings);
    ifile.close();
    delete diag;
}
