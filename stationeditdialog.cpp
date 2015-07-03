#include "stationeditdialog.h"
#include "ui_stationeditdialog.h"

#include <QDebug>

StationEditDialog::StationEditDialog(QSortFilterProxyModel *model, Station *station, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StationEditDialog)
{
    ui->setupUi(this);

    this->station = station;
    this->proxy_model = model;

    int ciphering_keys_num = station->ciphering_keys_index.count();
    ui->station_tableWidget->setRowCount(ciphering_keys_num);

    //Set prototype item for consistency
    QTableWidgetItem *prototype_item = new QTableWidgetItem();
    prototype_item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    prototype_item->setFlags(prototype_item->flags() ^ Qt::ItemIsEditable);

    QString station_name = model->data(station->name_index).toString();
    ui->station_name_label->setText(station_name);

    QFont header_font;
    header_font.setBold(true);
    header_font.setWeight(75);
    ui->station_tableWidget->verticalHeader()->setFont(header_font);
    QStringList vertical_headers;
    for(int i = 0; i < ciphering_keys_num; i++)
    {
        QString ciphering_label_str = "Ciphering Key ";
        ciphering_label_str.append(QString::number(i+1)); //Starts from 1 instead of 0
        ciphering_label_str.append(": ");
        vertical_headers.append(ciphering_label_str);

        QModelIndex ciphering_key_index = station->ciphering_keys_index[i];
        QString ciphering_key_str = model->data(ciphering_key_index).toString();
//        QTableWidgetItem *ciphering_key_item = new QTableWidgetItem(ciphering_key_str);
//        ciphering_key_item->setTextAlignment(Qt::AlignRight);
//        ciphering_key_item->setFlags(ciphering_key_item->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *ciphering_key_item = prototype_item->clone();
        ciphering_key_item->setText(ciphering_key_str);
        ui->station_tableWidget->setItem(i+CIPHERING_KEY_STARTING_ROW_INDEX, STATION_OLD_VALUE_COLUMN_INDEX, ciphering_key_item);
    }
    ui->station_tableWidget->setVerticalHeaderLabels(vertical_headers);

}

StationEditDialog::~StationEditDialog()
{
    delete ui;
}

void StationEditDialog::on_buttonBox_accepted()
{
    qDebug() << "Accepted";

    QModelIndex new_name_index = proxy_model->index(station->name_index.row(), VALUE_NEW_INDEX);
//    QString new_name_str = ui->station_tableWidget->item(STATION_NAME_ROW_INDEX, STATION_NEW_VALUE_COLUMN_INDEX);
//    proxy_model->setData(new_name_index);

    int ciphering_keys_num = station->ciphering_keys_index.count();

//    for(int i = 0; i < ciphering_keys_num; i++)
//    {
//        QModelIndex new_ciphering_key =
//    }
}

void StationEditDialog::on_buttonBox_rejected()
{
    qDebug() << "Rejected";
}
