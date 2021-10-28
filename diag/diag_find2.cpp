#include "diag_find2.h"
#include "ui_diag_find2.h"

#include <QTextBlock>

#ifdef Q_OS_MACOS
#include "KDMacTouchBar/kdmactouchbar.h"
#endif

diag_find2::diag_find2(QWidget *parent, QWidget *trueparent, QPlainTextEdit *editor) :
    QWidget(parent),
    ui(new Ui::diag_find2)
{
    textEdit=editor;
    parentWidget=trueparent;
    extraSel.format.setFontWeight(2);
    extraSel.format.setBackground(Qt::yellow);
    ui->setupUi(this);

#ifdef Q_OS_MACOS
    KDMacTouchBar *touchBar = new KDMacTouchBar;

    QAction *timestampsAction = new QAction(tr("Timestamps"));
    touchBar->addAction(timestampsAction);
    connect(timestampsAction, &QAction::triggered, this, &diag_find2::on_commandLinkButton_Timestamps_clicked);

    QAction *branchesAction = new QAction(tr("Branches"));
    touchBar->addAction(branchesAction);
    connect(branchesAction, &QAction::triggered, this, &diag_find2::on_commandLinkButton_Branches_clicked);

    QAction *lyricsAction = new QAction(tr("Lyrics"));
    touchBar->addAction(lyricsAction);
    connect(lyricsAction, &QAction::triggered, this, &diag_find2::on_commandLinkButton_Lyrics_clicked);

    touchBar->addSeparator();

    QAction *searchAction = new QAction(tr("Search"));
    touchBar->addAction(searchAction);
    connect(searchAction, &QAction::triggered, this, &diag_find2::on_pushButton_Search_clicked);

    QAction *findNextAction = new QAction(tr("Find next"));
    touchBar->addAction(findNextAction);
    connect(findNextAction, &QAction::triggered, this, &diag_find2::on_pushButton_FindNext_clicked);
#endif
}

diag_find2::~diag_find2()
{
    ui->tableWidget->setRowCount(0);
    delete ui;
    delete this;
}

void diag_find2::on_commandLinkButton_Timestamps_clicked()
{
    search("TIME(", true, true);
}

void diag_find2::on_commandLinkButton_Branches_clicked()
{
    search("PV_BRANCH_MODE(", true, true);
}

void diag_find2::on_commandLinkButton_Lyrics_clicked()
{
    search("LYRIC(", true, true);
}

void diag_find2::on_pushButton_Search_clicked()
{
    search(ui->lineEdit_command->text(), ui->checkBox_Starts->isChecked());
}

void diag_find2::search(QString query, bool startswith, bool internal)
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

void diag_find2::on_pushButton_FindNext_clicked()
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

void diag_find2::on_tableWidget_cellActivated(int row, int column)
{
    QTextCursor cur(textEdit->document()->findBlockByLineNumber(ui->tableWidget->item(row, 0)->text().toInt()-1));
    textEdit->setTextCursor(cur);
    parentWidget->activateWindow();
    textEdit->setFocus();
}
