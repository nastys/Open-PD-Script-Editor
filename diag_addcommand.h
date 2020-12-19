#ifndef DIAG_ADDCOMMAND_H
#define DIAG_ADDCOMMAND_H

#include "diag_addcommand2.h"
#include <QDialog>

namespace Ui {
class diag_addcommand;
}

class diag_addcommand : public QDialog
{
    Q_OBJECT

public:
    explicit diag_addcommand(QWidget *parent = nullptr, DivaScriptOpcode *newDSO = nullptr);
    ~diag_addcommand();
    QString *command;
    int *time;

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::diag_addcommand *ui;
    DivaScriptOpcode* DSO;
};

#endif // DIAG_ADDCOMMAND_H
