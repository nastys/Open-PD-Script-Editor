#include "diag_format.h"
#include "ui_diag_format.h"
#include <QtEndian>

const QString st_force="Force b&ig endian";
const QString st_ps3="PlayStat&ion 3";

Diag_Format::Diag_Format(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diag_Format)
{
    ui->setupUi(this);
}

Diag_Format::~Diag_Format()
{
    delete ui;
}

void Diag_Format::on_buttonBox_accepted()
{
    //todo verify fmt format
    *ok=true;
    *format=tmpFormat;
    *formatVer=qFromLittleEndian(ui->comboBox->currentText().toInt());
    *useBigEndian=ui->checkBox->isChecked();
}

void Diag_Format::on_radioButton_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=0;
        ui->comboBox->setCurrentText("");
        ui->comboBox->setEnabled(false);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_2_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=1;
        ui->comboBox->setCurrentText("");
        ui->comboBox->setEnabled(false);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_3_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=2;
        ui->comboBox->setCurrentText("");
        ui->comboBox->setEnabled(false);
        ui->checkBox->setText(st_ps3);
    }
}

void Diag_Format::on_radioButton_4_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=3;
        ui->comboBox->setCurrentText("285614104");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_5_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=4;
        ui->comboBox->setCurrentText("335874337");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_6_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=5;
        ui->comboBox->setCurrentText("302121504");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_7_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=6;
        ui->comboBox->setCurrentText("1129535056");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_ps3);
    }
}

void Diag_Format::on_radioButton_8_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=7;
        ui->comboBox->setCurrentText("1129535056");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::on_radioButton_9_toggled(bool checked)
{
    if(checked)
    {
        tmpFormat=8;
        ui->comboBox->setCurrentText("269615382");
        ui->comboBox->setEnabled(true);
        ui->checkBox->setText(st_force);
    }
}

void Diag_Format::setDefaults(int detectedFormat, int detectedVer)
{
    switch(detectedFormat)
    {
    case 0:
        ui->radioButton->setChecked(true);
        break;
    case 1:
        ui->radioButton_2->setChecked(true);
        break;
    case 2:
        ui->radioButton_3->setChecked(true);
        break;
    case 3:
        ui->radioButton_4->setChecked(true);
        break;
    case 4:
        ui->radioButton_5->setChecked(true);
        break;
    case 5:
        ui->radioButton_6->setChecked(true);
        break;
    case 6:
        ui->radioButton_7->setChecked(true);
        break;
    case 7:
        ui->radioButton_8->setChecked(true);
        break;
    case 8:
        ui->radioButton_9->setChecked(true);
        break;
    }

    ui->comboBox->setCurrentText(QString::number(detectedVer));
}
