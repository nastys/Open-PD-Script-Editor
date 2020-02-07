#include "diag_lipsync.h"
#include "ui_diag_lipsync.h"

diag_lipsync::diag_lipsync(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diag_lipsync)
{
    ui->setupUi(this);
}

diag_lipsync::~diag_lipsync()
{
    delete ui;
}

void diag_lipsync::on_buttonBox_accepted()
{
    settings.engine=ui->comboBox_engine->currentIndex();
    settings.format=ui->comboBox_format->currentIndex();
    settings.language=ui->comboBox_language->currentIndex();
    settings.espeak_voice=ui->lineEdit_espeak_voice->text();
    settings.performer=ui->spinBox_performer->value();
    settings.delete_existing=ui->checkBox_delete_existing->isChecked();
    settings.offset_before=ui->spinBox_offset_before->value();
    settings.offset_after=ui->spinBox_offset_after->value();
    settings.close_mouth_b=ui->checkBox_close_mouth_b->isChecked();
    settings.close_mouth_p=ui->checkBox_close_mouth_p->isChecked();
    settings.close_mouth_n=ui->checkBox_close_mouth_n->isChecked();
    settings.close_mouth_m=ui->checkBox_close_mouth_m->isChecked();
    settings.close_mouth_end=ui->checkBox_close_mouth_end->isChecked();
}

void diag_lipsync::on_comboBox_language_currentIndexChanged(int index)
{
    if(index==lipsync_language::OTHER)
        ui->lineEdit_espeak_voice->setEnabled(true);
    else
        ui->lineEdit_espeak_voice->setEnabled(false);
}
