#include "diag_lipsync_vsqx.h"
#include "ui_diag_lipsync_vsqx.h"

diag_lipsync_vsqx::diag_lipsync_vsqx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diag_lipsync_vsqx)
{
    ui->setupUi(this);
}

diag_lipsync_vsqx::~diag_lipsync_vsqx()
{
    delete ui;
}

void diag_lipsync_vsqx::on_buttonBox_accepted()
{
    settings.track=ui->spinBox_track->value();
    settings.offset=ui->spinBox_offset->value();
    settings.transition_duration=ui->spinBox_transition_duration->value();
    settings.transition_timeout=ui->spinBox_transition_timeout->value();
    settings.performer=ui->spinBox_performer->value();
    settings.exclude_premeasure=ui->checkBox_exclude_premeasure->isChecked();
    settings.delete_existing=ui->checkBox_delete_existing->isChecked();
}
