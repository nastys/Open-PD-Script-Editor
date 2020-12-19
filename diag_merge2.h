#ifndef DIAG_MERGE2_H
#define DIAG_MERGE2_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QTableWidgetItem>
#include <QMessageBox>

namespace Ui {
class diag_merge2;
}

class diag_merge2 : public QDialog
{
    Q_OBJECT

public:
    explicit diag_merge2(QWidget *parent = nullptr, QStringList *mergelist = nullptr, QPlainTextEdit *editor = nullptr);
    ~diag_merge2();

private slots:
    void on_buttonBox_accepted();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_All_clicked();

    void on_pushButton_None_clicked();

    void on_pushButton_Invert_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::diag_merge2 *ui;
    QStringList *mergelist;
    void setAllChecked(Qt::CheckState checkState);
};

#endif // DIAG_MERGE2_H
