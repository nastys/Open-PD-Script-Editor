#include "diag_merge2.h"
#include "ui_diag_merge2.h"

#define cmdUnmergeable (cmd=="TIME"||cmd=="PV_BRANCH_MODE"||cmd=="PV_END"||cmd=="END"||cmd=="MUSIC_PLAY")

diag_merge2::diag_merge2(QWidget *parent, QStringList *mergelist, QPlainTextEdit *editor) :
    QDialog(parent),
    ui(new Ui::diag_merge2)
{
    this->mergelist=mergelist;

    ui->setupUi(this);
    ui->tableWidget->blockSignals(true);

    if(!editor->document()->isEmpty())
    {
        QStringList commands = editor->document()->toPlainText().split('\n');
        for(QString command : commands)
        {
            QStringList psplit = command.simplified().split('(');
            if(psplit.length()>0)
            {
                const QString cmd = psplit.at(0);
                if(!cmd.isEmpty()&&!ui->tableWidget->findItems(cmd, Qt::MatchExactly).length())
                {
                    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(cmd));
                    if(cmdUnmergeable) ui->tableWidget->item(ui->tableWidget->rowCount()-1, 0)->setCheckState(Qt::PartiallyChecked);
                    else ui->tableWidget->item(ui->tableWidget->rowCount()-1, 0)->setCheckState(Qt::Checked);
                }
            }
        }
    }

    ui->tableWidget->blockSignals(false);
}

diag_merge2::~diag_merge2()
{
    ui->tableWidget->setRowCount(0);
    delete ui;
}

void diag_merge2::on_buttonBox_accepted()
{
    const bool selective = ui->checkBox->isChecked();
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        if((selective&&ui->tableWidget->item(i, 0)->checkState()==Qt::Checked)||
                (!selective&&ui->tableWidget->item(i, 0)->checkState()!=Qt::PartiallyChecked))
            mergelist->append(ui->tableWidget->item(i, 0)->text());
    }
}

void diag_merge2::on_checkBox_stateChanged(int arg1)
{
    ui->tableWidget->setEnabled(arg1);
    ui->pushButton_All->setEnabled(arg1);
    ui->pushButton_None->setEnabled(arg1);
    ui->pushButton_Invert->setEnabled(arg1);
}

void diag_merge2::setAllChecked(Qt::CheckState checkState)
{
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        QString cmd = item->text();
        if(!cmdUnmergeable) ui->tableWidget->item(i, 0)->setCheckState(checkState);
    }
}

void diag_merge2::on_pushButton_All_clicked()
{
    setAllChecked(Qt::Checked);
}

void diag_merge2::on_pushButton_None_clicked()
{
    setAllChecked(Qt::Unchecked);
}

void diag_merge2::on_pushButton_Invert_clicked()
{
    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        QString cmd = item->text();
        if(!cmdUnmergeable) ui->tableWidget->item(i, 0)->setCheckState(!ui->tableWidget->item(i, 0)->checkState()?Qt::Checked:Qt::Unchecked);
    }
}

void diag_merge2::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    const QString cmd = item->text();
    if(cmdUnmergeable)
    {
        ui->tableWidget->blockSignals(true);
        item->setCheckState(Qt::PartiallyChecked);
        ui->tableWidget->blockSignals(false);
        QMessageBox::information(this, cmd, "This command cannot be merged directly.");
    }
}
