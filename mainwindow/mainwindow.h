#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QCloseEvent>

#include "helper/EditWidgets.h"
#include "DSC.h"

#ifdef Q_OS_MACOS
#include "KDMacTouchBar/kdmactouchbar.h"
#endif

class DivaScriptOpcode;

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

    void openDSC(QString filepath, bool testopen = false);

    void formatSelector(int defaultsel, int version, bool& ok);

    void on_actionOpen_DSC_triggered();

    bool on_actionSave_DSC_triggered();

    bool on_actionSave_DSC_as_triggered();

    bool doSave(QString &filepath);

    void on_actionExit_triggered();

    void on_actionImport_VTT_triggered();

    void on_actionLip_sync_triggered();

    void on_actionLip_sync_VSQX_triggered();

    void on_actionPDA_2_00_to_PDA_1_01_triggered();

    void on_action_FT_new_mouth_to_FT_old_mouth_triggered();

    void on_action_Look_FT_old_look_triggered();

    void on_action_Expressions_FT_old_expressions_triggered();

    void on_action_Hand_animations_FT_old_animations_triggered();

    void on_actionAll_of_them_triggered();

    void on_actionBAR_TIME_SET_TARGET_FLYING_TIME_triggered();

    void on_actionAbout_triggered();

    void on_textEdit_cursorPositionChanged();

    void on_actionAdd_command_triggered();

    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);

    void on_actionEdits_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_action_Wrap_toggled(bool arg1);

    void on_action_Dark_mode_toggled(bool arg1);

    void on_actionLight_mode_toggled(bool arg1);

    void on_textEdit_modificationChanged(bool arg1);

    void setTitleBarText(bool modified);

    void setPvSlot();

    void on_actionChang_e_format_triggered();

    void on_actionSet_PV_slot_triggered();

    void on_actionFind_and_replace_triggered();

    void on_textEdit_Log_textChanged();

    void on_pushButton_List_clicked();

    void on_actionTime_triggered();

    void on_actionExport_L_RC_triggered();

    void on_actionReload_data_base_entry_triggered();

    void on_action_Bulk_check_triggered();

    void on_actionClea_r_log_triggered();

    void on_actionRemove_command_triggered();

private:
    Ui::MainWindow *ui;
#ifdef Q_OS_MACOS
    KDMacTouchBar *touchBar;
    QAction *wrapAction;
#endif
    void replaceID(QString command);
    void closeEvent(QCloseEvent *event);
    void loadPvDbEntry();
    void toggleWrap();
    void touchBar_main();
    void touchBar_tools();
};

#endif // MAINWINDOW_H
