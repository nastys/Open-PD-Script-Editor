#ifndef DIAG_PVSLOT_H
#define DIAG_PVSLOT_H

#include <QDialog>
#include <QFile>
#include "helper/DoubleDigitQSpinBox.h"

namespace Ui {
class diag_pvslot;
}

class diag_pvslot : public QDialog
{
    Q_OBJECT

public:
    explicit diag_pvslot(QWidget *parent = nullptr);
    ~diag_pvslot();
    void setPvSlotPtr(int* ptr);

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_spinBox_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::diag_pvslot *ui;
    int *pvslot;
    void loadDbToTable(QString filename);
    void setCurrentPvNum(QString num_s);
    void updateCurrentName(int left, int right);
    void updateCurrentName(int num);
};

#endif // DIAG_PVSLOT_H
