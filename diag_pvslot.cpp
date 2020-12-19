#include "diag_pvslot.h"
#include "ui_diag_pvslot.h"
#include "debug.h"

bool usedb=false;

diag_pvslot::diag_pvslot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::diag_pvslot)
{
    ui->setupUi(this);
    ui->tableWidget->setVisible(false);
    ui->tableWidget->setHorizontalHeaderLabels({"File", "Number", "Name"});

    // TODO get both from rom and highest mdata first, + ps4/switch/etc dlc
    loadDbToTable("pv_db.txt");
    loadDbToTable("mdata_pv_db.txt");
    if(usedb) ui->tableWidget->sortByColumn(1, Qt::SortOrder::AscendingOrder);
    else
    {
        ui->lineEdit->setPlaceholderText("No database found.");
        ui->pushButton->setEnabled(false);
    }

    ui->spinBox->setFocus();
}

diag_pvslot::~diag_pvslot()
{
    ui->tableWidget->setRowCount(0);
    delete ui;
}

void diag_pvslot::on_buttonBox_accepted()
{
    *pvslot=(ui->comboBox->currentIndex()*100)+ui->spinBox->value();
}

void diag_pvslot::setPvSlotPtr(int* ptr)
{
    pvslot=ptr;
    const QString pvslot_s = QStringLiteral("%1").arg(*pvslot, 3, 10, QLatin1Char('0'));
    setCurrentPvNum(pvslot_s);
}

void diag_pvslot::on_pushButton_clicked()
{
    if(ui->tableWidget->isVisible())
    {
        QDialog::setMinimumSize(300, 140);
        QDialog::setMaximumSize(300, 140);
        ui->tableWidget->setVisible(false);
    }
    else
    {
        QDialog::setMaximumSize(16777215, 16777215);
        QDialog::setMinimumSize(600, 400);
        ui->tableWidget->setVisible(true);
    }
}

void diag_pvslot::loadDbToTable(QString filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) return;

    while(!file.atEnd())
    {
        QString line = file.readLine().simplified();
        const QString c_songname=".song_name=";
        if(!line.startsWith('#')&&line.contains(c_songname))
        {
            const QString left=file.fileName();
            const QString centre=line.mid(3, 3);
            QStringList snsplit=line.split(c_songname);
            QString right="";
            if(snsplit.length()>0) right=snsplit.at(1);
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(left));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(centre));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(right));
        }
    }

    usedb=true;
}

void diag_pvslot::on_tableWidget_cellActivated(int row, int column)
{
    setCurrentPvNum(ui->tableWidget->item(row, 1)->text());
}

void diag_pvslot::setCurrentPvNum(QString num_s)
{
    ui->comboBox->setCurrentIndex(QString(num_s.at(0)).toInt());
    ui->spinBox->setValue(num_s.mid(1).toInt());
}

void diag_pvslot::updateCurrentName(int num)
{
    const QString pvslot_s = QStringLiteral("%1").arg(num, 3, 10, QLatin1Char('0'));
    QList<QTableWidgetItem*> list = ui->tableWidget->findItems(pvslot_s, Qt::MatchFlag::MatchExactly);
    for(QTableWidgetItem* item : list)
    {
        if(item->column()==1)
        {
            ui->lineEdit->setText(ui->tableWidget->item(item->row(), 2)->text());
            ui->tableWidget->selectRow(item->row());
            return;
        }
    }

    ui->lineEdit->clear();
}

void diag_pvslot::updateCurrentName(int left, int right)
{
    return updateCurrentName((left*100)+right);
}

void diag_pvslot::on_spinBox_valueChanged(int arg1)
{
    updateCurrentName(ui->comboBox->currentIndex(), arg1);
}

void diag_pvslot::on_comboBox_currentIndexChanged(int index)
{
    updateCurrentName(index, ui->spinBox->value());
}
