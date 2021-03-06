#ifndef SATCONFIGSYS_H
#define SATCONFIGSYS_H

#include "mainwindow.h"
#include "globalcontext.h"
#include "station.h"
#include "satellite.h"

#include <QObject>
#include <QApplication>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QMessageBox>
#include <QDateTime>
#include <QXmlStreamWriter>
#include <QXmlStreamAttributes>


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
    QString getFileNameWithDateTimeUtc(QString initial_filename, QString file_extension);

    void transferMpcPl(QString filepath);
    void transferMpcAocs(QString filepath);
    void transferFds(QString filepath);

    void saveToConfSat();
    void transferFiles();

public slots:
    void onTransferFilesClicked();
    void onSaveToConfSatClicked();

private:
    void importSatConfig(QString filepath);
    void initDataModel();



};

#endif // SATCONFIGSYS_H
