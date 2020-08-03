#include "diag_addcommand.h"
#include "ui_diag_addcommand.h"

diag_addcommand::diag_addcommand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diag_addcommand)
{
    ui->setupUi(this);
}

diag_addcommand::~diag_addcommand()
{
    delete ui;
}

void diag_addcommand::on_buttonBox_accepted()
{
    *command=ui->lineEdit_command->text();
    *time=ui->spinBox_time->value();
}
