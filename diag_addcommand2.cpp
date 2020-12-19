#include "diag_addcommand2.h"
#include "ui_diag_addcommand2.h"
#include "debug.h"
#include <QTextEdit>

diag_addcommand2::diag_addcommand2(QWidget *parent, DivaScriptOpcode* newDSO) :
    QDialog(parent),
    ui(new Ui::diag_addcommand2)
{
    ui->setupUi(this);

    DSO=newDSO;
    DSO->fillCommandListWidget(ui->listWidget);
}

diag_addcommand2::~diag_addcommand2()
{
    delete ui;
}

void diag_addcommand2::on_listWidget_itemActivated(QListWidgetItem *item)
{
    sel=item->text();
    accept();
}

void diag_addcommand2::on_listWidget_currentTextChanged(const QString &currentText)
{
    sel=currentText;
}

void diag_addcommand2::on_buttonBox_accepted()
{
    accept();
}

void diag_addcommand2::on_buttonBox_rejected()
{
    reject();
}
