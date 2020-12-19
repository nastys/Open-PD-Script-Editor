#ifndef DIAG_FIND_H
#define DIAG_FIND_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class diag_find;
}

class diag_find : public QDialog
{
    Q_OBJECT

public:
    explicit diag_find(QWidget *parent = nullptr, QPlainTextEdit *editor = nullptr);
    ~diag_find();

private slots:
    void on_commandLinkButton_Timestamps_clicked();

    void on_commandLinkButton_Branches_clicked();

    void on_commandLinkButton_Lyrics_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::diag_find *ui;
    QPlainTextEdit *textEdit;
    QTextEdit::ExtraSelection extraSel;
    void search(QString query, bool startswith, bool internal=false);
    QWidget *parentWidget;
};

#endif // DIAG_FIND_H
