#include "diag_addcommand.h"
#include "ui_diag_addcommand.h"

diag_addcommand::diag_addcommand(QWidget *parent, DivaScriptOpcode* newDSO) :
    QDialog(parent),
    ui(new Ui::diag_addcommand)
{
    ui->setupUi(this);
    DSO=newDSO;

#ifdef Q_OS_MACOS
    KDMacTouchBar *touchBar = new KDMacTouchBar;

    QAction *ENDAction = new QAction(tr("END()"));
    touchBar->addAction(ENDAction);
    connect(ENDAction, &QAction::triggered, this, &diag_addcommand::tb_END);
#endif
}

diag_addcommand::~diag_addcommand()
{
    delete ui;

    //if(DSO->gameStr().isEmpty()||DSO->gameStr().isNull()) ui->pushButton->setEnabled(false);
}

void diag_addcommand::tb_END()
{
    ui->lineEdit_command->setText("END()");
    on_buttonBox_accepted();
    accept();
}

void diag_addcommand::on_buttonBox_accepted()
{
    *command=ui->lineEdit_command->text().remove(';');
    *time=ui->spinBox_time->value();
}

void diag_addcommand::on_pushButton_clicked()
{
    diag_addcommand2 diag(this, DSO);
    if(diag.exec()) ui->lineEdit_command->setText(diag.sel);
}
