#ifndef DIAG_FIND2_H
#define DIAG_FIND2_H

#include <QWidget>
#include <QPlainTextEdit>

namespace Ui {
class diag_find2;
}

class diag_find2 : public QWidget
{
    Q_OBJECT

public:
    explicit diag_find2(QWidget *parent = nullptr, QWidget *trueparent = nullptr, QPlainTextEdit *editor = nullptr);
    ~diag_find2();

private slots:
    void on_commandLinkButton_Timestamps_clicked();

    void on_commandLinkButton_Branches_clicked();

    void on_commandLinkButton_Lyrics_clicked();

    void on_pushButton_Search_clicked();

    void on_pushButton_FindNext_clicked();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::diag_find2 *ui;
    QPlainTextEdit *textEdit;
    QTextEdit::ExtraSelection extraSel;
    void search(QString query, bool startswith, bool internal=false);
    QWidget *parentWidget;
};

#endif // DIAG_FIND2_H
