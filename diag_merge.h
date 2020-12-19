#ifndef DIAG_MERGE_H
#define DIAG_MERGE_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class diag_merge;
}

class diag_merge : public QDialog
{
    Q_OBJECT

public:
    explicit diag_merge(QWidget *parent = nullptr, QStringList *mergelist = nullptr, QPlainTextEdit *editor = nullptr);
    ~diag_merge();

private slots:
    void on_commandLinkButton_Open_clicked();

    void on_commandLinkButton_Merge_clicked();

private:
    Ui::diag_merge *ui;
    QStringList *mergelist;
    QPlainTextEdit *editor;
    bool *chanceSuccessDefault;
};

#endif // DIAG_MERGE_H
