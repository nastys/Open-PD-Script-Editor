#ifndef DIAG_ADDCOMMAND_H
#define DIAG_ADDCOMMAND_H

#include <QDialog>

namespace Ui {
class diag_addcommand;
}

class diag_addcommand : public QDialog
{
    Q_OBJECT

public:
    explicit diag_addcommand(QWidget *parent = nullptr);
    ~diag_addcommand();
    QString *command;
    int *time;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::diag_addcommand *ui;
};

#endif // DIAG_ADDCOMMAND_H
