#include "diag_find.h"
#include "ui_diag_find.h"

#include <QTextBlock>

diag_find::diag_find(QWidget *parent, QPlainTextEdit *editor) :
    QDialog(parent),
    ui(new Ui::diag_find)
{
    textEdit=editor;
    parentWidget=parent;
    extraSel.format.setFontWeight(2);
    extraSel.format.setBackground(Qt::yellow);
    ui->setupUi(this);
}

diag_find::~diag_find()
{
    ui->tableWidget->setRowCount(0);
    delete ui;
    delete this;
}

void diag_find::on_commandLinkButton_Timestamps_clicked()
{
    search("TIME(", true, true);
}

void diag_find::on_commandLinkButton_Branches_clicked()
{
    search("PV_BRANCH_MODE(", true, true);
}

void diag_find::on_commandLinkButton_Lyrics_clicked()
{
    search("LYRIC(", true, true);
}

void diag_find::on_pushButton_2_clicked()
{
    search(ui->lineEdit_command->text(), ui->checkBox_Starts->isChecked());
}

void diag_find::search(QString query, bool startswith, bool internal)
{
    ui->tableWidget->setRowCount(0);

    QStringList list = textEdit->document()->toPlainText().split('\n');
    for(int i=0; i<list.length(); i++)
    {
        Qt::CaseSensitivity sensitive = internal?Qt::CaseSensitive:ui->checkBox_Case->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;
        if( (startswith && list.at(i).startsWith(query, sensitive)) || (!startswith && list.at(i).contains(query, sensitive) ))
        {
            const int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(i+1)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(list.at(i)));
        }
    }
}

void diag_find::on_pushButton_3_clicked()
{
    QTextDocument::FindFlags flags;
    if(ui->checkBox_Case->isChecked()) flags|=QTextDocument::FindFlag::FindCaseSensitively;
    if(ui->checkBox_Whole->isChecked()) flags|=QTextDocument::FindFlag::FindWholeWords;
    if(ui->checkBox_Backwards->isChecked()) flags|=QTextDocument::FindFlag::FindBackward;

    if(textEdit->find(ui->lineEdit_command->text(), flags))
    {
        parentWidget->activateWindow();
        textEdit->setFocus();
    }
}

void diag_find::on_tableWidget_cellActivated(int row, int column)
{
    QTextCursor cur(textEdit->document()->findBlockByLineNumber(ui->tableWidget->item(row, 0)->text().toInt()-1));
    textEdit->setTextCursor(cur);
    parentWidget->activateWindow();
    textEdit->setFocus();
}
