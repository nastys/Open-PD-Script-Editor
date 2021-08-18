#include "diag_time.h"
#include "ui_diag_time.h"

#ifdef Q_OS_MACOS
#include "KDMacTouchBar/kdmactouchbar.h"
#endif

diag_time::diag_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::diag_time)
{
    ui->setupUi(this);
    ui->spinBox->setValue(6000000);

#ifdef Q_OS_MACOS
    KDMacTouchBar *touchBar = new KDMacTouchBar(this);

    QAction *S30Action = new QAction(tr("30 seconds"));
    touchBar->addAction(S30Action);
    connect(S30Action, &QAction::triggered, this, &diag_time::set30S);

    QAction *M1Action = new QAction(tr("1 minute"));
    touchBar->addAction(M1Action);
    connect(M1Action, &QAction::triggered, this, &diag_time::set1M);

    QAction *M2Action = new QAction(tr("2 minutes"));
    touchBar->addAction(M2Action);
    connect(M2Action, &QAction::triggered, this, &diag_time::set2M);

    QAction *closeAction = new QAction(tr("Close"));
    touchBar->addSeparator();
    touchBar->addAction(closeAction);
    connect(closeAction, &QAction::triggered, this, &diag_time::on_pushButton_Close_clicked);
#endif
}

diag_time::~diag_time()
{
    delete ui;
    delete this;
}

void diag_time::set30S()
{
    ui->spinBox->setValue(3000000);
}

void diag_time::set1M()
{
    ui->spinBox->setValue(6000000);
}

void diag_time::set2M()
{
    ui->spinBox->setValue(12000000);
}

void diag_time::on_spinBox_valueChanged(int arg1)
{
    ui->lineEdit_2->setText(pdtime_string(pdtime_split(arg1)));
}

void diag_time::on_pushButton_Close_clicked()
{
    close();
}
