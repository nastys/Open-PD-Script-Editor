#ifndef DIAG_LIPSYNC_VSQX_H
#define DIAG_LIPSYNC_VSQX_H

#include <QDialog>
#include "lipsync/lipsync_settings.h"

namespace Ui {
class diag_lipsync_vsqx;
}

class diag_lipsync_vsqx : public QDialog
{
    Q_OBJECT

public:
    explicit diag_lipsync_vsqx(QWidget *parent = nullptr);
    ~diag_lipsync_vsqx();
    VSQX_Settings settings;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::diag_lipsync_vsqx *ui;
};

#endif // DIAG_LIPSYNC_VSQX_H
