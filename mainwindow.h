#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTableWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct EditWidgets
{
    QWidget *tabedit;
    QTableWidget *bartable;
    QListWidget *modulelist;
    QListWidget *stagelist;
    QListWidget *motionlist;
    QListWidget *handitemlist;
    QListWidget *effectlist;
    QLineEdit *editname;
    QLineEdit *songname;
    QSpinBox *songstart;
    QSpinBox *songend;
    QSpinBox *buttonsfx;
};

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
