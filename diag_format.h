#ifndef DIAG_FORMAT_H
#define DIAG_FORMAT_H

#include <QDialog>

namespace Ui {
class Diag_Format;
}

class Diag_Format : public QDialog
{
    Q_OBJECT

public:
    explicit Diag_Format(QWidget *parent = nullptr);
    ~Diag_Format();
    bool* useBigEndian;
    int tmpFormat;
    int* format;
    int* formatVer;
    bool* ok;
    void setDefaults(int detectedFormat, int detectedVer);

private slots:
    void on_buttonBox_accepted();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_radioButton_5_toggled(bool checked);

    void on_radioButton_6_toggled(bool checked);

    void on_radioButton_7_toggled(bool checked);

    void on_radioButton_8_toggled(bool checked);

    void on_radioButton_9_toggled(bool checked);

private:
    Ui::Diag_Format *ui;
};

#endif // DIAG_FORMAT_H
