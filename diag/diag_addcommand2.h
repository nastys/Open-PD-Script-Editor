#ifndef DIAG_ADDCOMMAND2_H
#define DIAG_ADDCOMMAND2_H

#include <QDialog>
#include "DSC.h"

class DivaScriptOpcode;

namespace Ui {
class diag_addcommand2;
}

class diag_addcommand2 : public QDialog
{
    Q_OBJECT

public:
    explicit diag_addcommand2(QWidget *parent = nullptr, DivaScriptOpcode* newDSO = nullptr);
    ~diag_addcommand2();
    QString sel="";

private slots:
    void on_listWidget_itemActivated(QListWidgetItem *item);

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::diag_addcommand2 *ui;
    DivaScriptOpcode* DSO;
};

#endif // DIAG_ADDCOMMAND2_H
