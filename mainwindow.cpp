#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DSC.h"
#include <QFileDialog>
#include <QFile>
#include <QDataStream>
#include <QDebug>
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
    QString format=QInputDialog::getItem(this, "Format", "DSC format:", {"Project DIVA", "Project DIVA 2nd/Extend", "Project DIVA Arcade/Dreamy Theater", "Project DIVA Arcade 2.00/Future Tone", "Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend", "Project DIVA F 2nd", "Project DIVA X", "Project Mirai", "Miracle Girls Festival"}, 0, false);
    if(format.isEmpty()) return;
    QString filepath=filepaths.at(0);
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QDataStream qds(&file);
    if(format=="Project DIVA") DivaScriptOpcode_DIVA::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA 2nd/Extend") DivaScriptOpcode_DIVA2::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade/Dreamy Theater") DivaScriptOpcode_PDA::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA Arcade 2.00/Future Tone") DivaScriptOpcode_FT::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA f/F/Dreamy Theater 2nd/Dreamy Theater Extend") DivaScriptOpcode_F::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA F 2nd") DivaScriptOpcode_F2::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project DIVA X") DivaScriptOpcode_X::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Project Mirai") DivaScriptOpcode_Mirai::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    else if(format=="Miracle Girls Festival") DivaScriptOpcode_MGF::readAll(file, qds, ui->plainTextEdit, ui->actionEnable_Big_Endian->isChecked()?QDataStream::BigEndian:QDataStream::LittleEndian);
    file.close();
}

void MainWindow::on_actionSave_DSC_triggered()
{
    QString filepath=QFileDialog::getSaveFileName();
    if(filepath.isEmpty()) return;
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
