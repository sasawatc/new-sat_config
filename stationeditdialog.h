#ifndef STATIONEDITDIALOG_H
#define STATIONEDITDIALOG_H

#include "globalcontext.h"
#include "station.h"

#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class StationEditDialog;
}

class StationEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StationEditDialog(QSortFilterProxyModel *model, Station *station, QWidget *parent = 0);
    ~StationEditDialog();
    static const unsigned int STATION_OLD_VALUE_COLUMN_INDEX = 0;
    static const unsigned int STATION_NEW_VALUE_COLUMN_INDEX = 1;
//    static const unsigned int STATION_NAME_ROW_INDEX = 0;
    static const unsigned int CIPHERING_KEY_STARTING_ROW_INDEX = 0;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::StationEditDialog *ui;
    Station *station;
    QSortFilterProxyModel *proxy_model;


};

#endif // STATIONEDITDIALOG_H
