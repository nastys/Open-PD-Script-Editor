#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "EditWidgets.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    EditWidgets uiEditWidgets();

    void on_actionOpen_DSC_triggered();

    void on_actionSave_DSC_triggered();

    void on_actionExit_triggered();

    void on_actionPSP_to_DT_triggered();

    void on_actionImport_VTT_triggered();

    void on_actionLip_sync_triggered();

    void on_actionPDA_2_00_to_PDA_1_01_triggered();

    void on_action_FT_new_mouth_to_FT_old_mouth_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
