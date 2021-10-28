#include "diag_merge.h"
#include "ui_diag_merge.h"
#include "diag_merge2.h"

diag_merge::diag_merge(QWidget *parent, QStringList *mergelist, QPlainTextEdit *editor) :
    QDialog(parent),
    ui(new Ui::diag_merge)
{
    this->mergelist=mergelist;
    this->editor=editor;
    ui->setupUi(this);
}

diag_merge::~diag_merge()
{
    delete ui;
}

void diag_merge::on_commandLinkButton_Open_clicked()
{
    accept();
}

void diag_merge::on_commandLinkButton_Merge_clicked()
{
    diag_merge2 diag(this, mergelist, editor);
    if(diag.exec()) accept();
}
