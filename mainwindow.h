#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "globalcontext.h"
#include "parameditdialog.h"
#include "stationeditdialog.h"
#include "parampushbutton.h"
#include "station.h"
#include "satellite.h"

#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QList>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static int x;
//    static const uint DATA_SIZE = 191;
//    QStandardItemModel *scc_model;
//    QStandardItemModel *fds_model;
//    QStandardItemModel *mpc_pl_model;
//    QStandardItemModel *mpc_aocs_model;
//    int num_config;
    void setModel(QSortFilterProxyModel *scc_model, QSortFilterProxyModel *mpc_pl_model, QSortFilterProxyModel *mpc_aocs_model, QSortFilterProxyModel *fds_model);
    void createButtons(QSortFilterProxyModel *scc_model, QSortFilterProxyModel *mpc_pl_model, QSortFilterProxyModel *mpc_aocs_model, QSortFilterProxyModel *fds_model, QList<Station *> *stations, QList<Satellite *> *satellites);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
//    void paramClicked(int number);
//    void itemUpdated(QStandardItem* item);
//    void transferFileClicked();
    void paramClicked();
    void stationClicked();
    void satelliteClicked();

private slots:
//    void createLayout(int n, QWidget *parent, QList<QPushButton*> buttons);

private:
    Ui::MainWindow *ui;
    QList<ParamPushButton *> scc_listButton;
    QList<ParamPushButton *> mpc_aocs_listButton;
    QList<ParamPushButton *> fds_listButton;
    QList<ParamPushButton *> mpc_pl_stations_listButton;
    QList<ParamPushButton *> mpc_pl_satellites_listButton;
    ParamEditDialog *edit_dialog;
    void createSatelliteButtons(QGridLayout *gridLayout, QSortFilterProxyModel *mpc_pl_model, Satellite *satellite);





    //indices on SCC, FDS, MPC_AOCS, and MPC_PL models
//    static const uint PARAM_NAME_INDEX = 0;
//    static const uint PARAM_VALUE_INDEX = 1;
//    static const uint PARAM_VALUE_NEW_INDEX = 2;
//    static const uint TYPE_INDEX = 3;
//    static const uint NOTE_INDEX = 4;
//    static const uint POID_INDEX = 5; //Persistent Object Identifier - use to know the location on the real file
//    static const uint SCC_TAB_INDEX = 0;
//    static const uint MPC_PL_TAB_INDEX = 1;
//    static const uint MPC_AOCS_INDEX = 2;
//    static const uint fds_tab_index = 3;
//    struct param_struct;
//    void setModel(QStandardItemModel* model, int row, param_struct& input_param_struct);
//    param_struct param_struct_constructor(int number);
//    void param_struct_init(param_struct& input_param_struct);
//    void updateAllGroupModel(const int index, const QString value);
//    void saveModelToFile(const QStandardItemModel *model, const QString filename);
//    void saveGroupsToFile();
//    QString getFileNameWithDateTimeUtc(QString initial_filename, QString file_extension);
//    void saveMpc_plToFile(QString filepath);
//    QString getCurrentParamValue(QStandardItemModel* model, int row);
//    void saveSatConfigToFile(QString filepath);
};

#endif // MAINWINDOW_H
