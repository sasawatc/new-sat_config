#ifndef SATCONFIGSYS_H
#define SATCONFIGSYS_H

#include "mainwindow.h"
#include "globalcontext.h"
#include "station.h"
#include "satellite.h"

#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QObject>


class SatConfigSys :QObject
{
    Q_OBJECT
public:
    SatConfigSys(int argc, char *argv[]);
    ~SatConfigSys();

//    static const QString SAT_CONFIG_PATH = "conf_sat.txt";

    QStandardItemModel *data_model;

    QSortFilterProxyModel *scc_proxyModel;
    QSortFilterProxyModel *mpc_pl_proxyModel;
    QSortFilterProxyModel *mpc_aocs_proxyModel;
    QSortFilterProxyModel *fds_proxyModel;
    QList<Station *> *stations;
    QList<Satellite *> *satellites;
    QString getCurrentParamValue(QSortFilterProxyModel* model, int row);
    QList<Station *> * getStationsFromMpcPl();
    QList<Satellite *> * getSatellitesFromMpcPl();

public slots:
    void ontransferFilesClicked();

private:
    void importSatConfig(QString filepath);
    void initDataModel();
    void saveGroupsToFile();




};

#endif // SATCONFIGSYS_H
