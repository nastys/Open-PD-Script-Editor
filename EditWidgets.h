#ifndef EDITWIDGETS_H
#define EDITWIDGETS_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QSpinBox>

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

#endif // EDITWIDGETS_H
