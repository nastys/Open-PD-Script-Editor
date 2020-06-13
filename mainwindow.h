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

    void on_action_Look_FT_old_look_triggered();

    void on_action_Expressions_FT_old_expressions_triggered();

    void on_action_Hand_animations_FT_old_animations_triggered();

    void on_actionAll_of_them_triggered();

    void on_actionBAR_TIME_SET_TARGET_FLYING_TIME_triggered();

    void on_actionAbout_triggered();

    void on_textEdit_cursorPositionChanged();

private:
    Ui::MainWindow *ui;
    void replaceID(QString command);
};

#endif // MAINWINDOW_H
