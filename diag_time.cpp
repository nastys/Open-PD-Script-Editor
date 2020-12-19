#include "diag_time.h"
#include "ui_diag_time.h"

diag_time::diag_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diag_time)
{
    ui->setupUi(this);
    ui->spinBox->setValue(6000000);
}

diag_time::~diag_time()
{
    delete ui;
    delete this;
}

void diag_time::on_spinBox_valueChanged(int arg1)
{
    ui->lineEdit_2->setText(pdtime_string(pdtime_split(arg1)));
}

void diag_time::on_pushButton_Close_clicked()
{
    close();
}
