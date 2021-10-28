#ifndef DIAG_LIPSYNC_H
#define DIAG_LIPSYNC_H

#include "lipsync/lipsync_settings.h"
#include <QDialog>

namespace Ui {
class diag_lipsync;
}

class diag_lipsync : public QDialog
{
    Q_OBJECT

public:
    explicit diag_lipsync(QWidget *parent = nullptr);
    ~diag_lipsync();
    lipsync_settings settings;

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_language_currentIndexChanged(int index);

private:
    Ui::diag_lipsync *ui;
};

#endif // DIAG_LIPSYNC_H
