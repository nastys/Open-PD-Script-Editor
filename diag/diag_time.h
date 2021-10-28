#ifndef DIAG_TIME_H
#define DIAG_TIME_H

#include <QWidget>

#include "helper/pdtime.h"

namespace Ui {
class diag_time;
}

class diag_time : public QWidget
{
    Q_OBJECT

public:
    explicit diag_time(QWidget *parent = nullptr);
    ~diag_time();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_Close_clicked();

private:
    Ui::diag_time *ui;
    void set30S();
    void set1M();
    void set2M();
};

#endif // DIAG_TIME_H
