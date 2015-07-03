#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSignalMapper>


int MainWindow::x = 0;

//QPushButton *buttons_FDS[31];
//QPushButton *buttons_MPS_AOCS[31];
//QList<QPushButton*> listbuttons_SCC;
//QList<QPushButton*> listbuttons_FDS;
//QList<QPushButton*> listbuttons_MPS_AOCS;


//struct MainWindow::param_struct
//{
//    QStandardItem *param_name;
//    QStandardItem *param_value;
//    QStandardItem *param_value_new;
//    QStandardItem *type;
//    QStandardItem *note;
//    QStandardItem *poid;
//};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->scc_tableView->verticalHeader()->setVisible(false);
    ui->mpc_pl_tableView->verticalHeader()->setVisible(false);
    ui->mpc_aocs_tableView->verticalHeader()->setVisible(false);
    ui->fds_tableView->verticalHeader()->setVisible(false);



}

void MainWindow::setModel(QSortFilterProxyModel *scc_model, QSortFilterProxyModel *mpc_pl_model, QSortFilterProxyModel *mpc_aocs_model, QSortFilterProxyModel *fds_model)
{
    ui->scc_tableView->setModel(scc_model);
    ui->mpc_pl_tableView->setModel(mpc_pl_model);
    ui->mpc_aocs_tableView->setModel(mpc_aocs_model);
    ui->fds_tableView->setModel(fds_model);

    ui->scc_tableView->hideColumn(GROUPS_INDEX);
    ui->mpc_pl_tableView->hideColumn(GROUPS_INDEX);
    ui->mpc_aocs_tableView->hideColumn(GROUPS_INDEX);
    ui->fds_tableView->hideColumn(GROUPS_INDEX);

    ui->scc_tableView->hideColumn(TYPE_UNIT_INDEX);
    ui->mpc_pl_tableView->hideColumn(TYPE_UNIT_INDEX);
    ui->mpc_aocs_tableView->hideColumn(TYPE_UNIT_INDEX);
    ui->fds_tableView->hideColumn(TYPE_UNIT_INDEX);
}

void MainWindow::createButtons(QSortFilterProxyModel *scc_model, QSortFilterProxyModel *mpc_pl_model, QSortFilterProxyModel *mpc_aocs_model, QSortFilterProxyModel *fds_model, QList<Station *> *stations, QList<Satellite *> *satellites)
{
    ui->scc_gridLayout->setSpacing(4);
    ui->mpc_aocs_gridLayout->setSpacing(4);
    ui->fds_gridLayout->setSpacing(4);
    ui->mpc_pl_stations_gridLayout->setSpacing(4);

    bool b_active = true;
    int i = 0;
    while(b_active)
    {
        b_active = false;
        //SCC
        if(i < scc_model->rowCount())
        {
            QModelIndex index = scc_model->index(i, NAME_INDEX);
            QString param_name = scc_model->data(index).toString();
            scc_listButton.append(new ParamPushButton(param_name, scc_model, index, this));
            ui->scc_gridLayout->addWidget(scc_listButton[i], i/6, i%6);
            connect(scc_listButton[i], SIGNAL(clicked()), this, SLOT(onParamClicked()));
            b_active = true;
        }
        //MPC_AOCS
        if(i < mpc_aocs_model->rowCount())
        {
            QModelIndex index = mpc_aocs_model->index(i, NAME_INDEX);
            QString param_name = mpc_aocs_model->data(index).toString();
            mpc_aocs_listButton.append(new ParamPushButton(param_name, mpc_aocs_model, index, this));
            ui->mpc_aocs_gridLayout->addWidget(mpc_aocs_listButton[i], i/6, i%6);
            connect(mpc_aocs_listButton[i], SIGNAL(clicked()), this, SLOT(onParamClicked()));
            b_active = true;
        }
        //FDS
        if(i < fds_model->rowCount())
        {
            QModelIndex index = fds_model->index(i, NAME_INDEX);
            QString param_name = fds_model->data(index).toString();
            fds_listButton.append(new ParamPushButton(param_name, fds_model, index, this));
            ui->fds_gridLayout->addWidget(fds_listButton[i], i/6, i%6);
            connect(fds_listButton[i], SIGNAL(clicked()), this, SLOT(onParamClicked()));
            b_active = true;
        }
        i++;
    }


    b_active = true;
    i = 0;
    while(b_active)
    {
        b_active = false;
        if(i < stations->size())
        {
            QString param_name = mpc_pl_model->data(stations->at(i)->name_index).toString();
            mpc_pl_stations_listButton.append(new ParamPushButton(param_name, mpc_pl_model, stations->at(i), this));
            ui->mpc_pl_stations_gridLayout->addWidget(mpc_pl_stations_listButton[i], i/4, i%4);
            connect(mpc_pl_stations_listButton[i], SIGNAL(clicked()), this, SLOT(onStationClicked()));
            b_active = true;
        }
        if(i < satellites->size())
        {
            QString satellite_name = mpc_pl_model->data(satellites->at(i)->name_index).toString();
            satellite_name.append(": ");
            ui->mpc_pl_satellites_layout->addWidget(new QLabel(satellite_name));

            QGridLayout *mpc_pl_satellites_gridLayout = new QGridLayout();
            mpc_pl_satellites_gridLayout->setSpacing(4);
            ui->mpc_pl_satellites_layout->addLayout(mpc_pl_satellites_gridLayout);
            createSatelliteButtons(mpc_pl_satellites_gridLayout, mpc_pl_model, satellites->at(i));
        }
        i++;
    }
}

void MainWindow::createSatelliteButtons(QGridLayout *gridLayout, QSortFilterProxyModel *mpc_pl_model, Satellite *satellite)
{
    bool b_active = true;
    int i = 0;

    while(b_active)
    {
        b_active = false;

        if(i < satellite->mission_constraints_name.count())
        {
            QString param_name = mpc_pl_model->data(satellite->mission_constraints_name[i]).toString();
            mpc_pl_satellites_listButton.append(new ParamPushButton(param_name, mpc_pl_model, satellite->mission_constraints_name[i], this));
            gridLayout->addWidget(mpc_pl_satellites_listButton[i], i/4, i%4);
            connect(mpc_pl_satellites_listButton[i], SIGNAL(clicked()), this, SLOT(onSatelliteClicked()));
            b_active = true;
        }
        if(i < satellite->system_constraints_name.count())
        {
            QString param_name = mpc_pl_model->data(satellite->system_constraints_name[i]).toString();
            mpc_pl_satellites_listButton.append(new ParamPushButton(param_name, mpc_pl_model, satellite->system_constraints_name[i], this));
            gridLayout->addWidget(mpc_pl_satellites_listButton[i], i/4, i%4);
            connect(mpc_pl_satellites_listButton[i], SIGNAL(clicked()), this, SLOT(onSatelliteClicked()));
            b_active = true;
        }
        i++;
    }
}




void MainWindow::onParamClicked()
{
    qDebug() << "Text: " << ((ParamPushButton *) sender())->text();
    QModelIndex sender_index = ((ParamPushButton *) sender())->getIndex();

    QSortFilterProxyModel *proxy_model = ((ParamPushButton *) sender())->getModel();
    QModelIndex index = proxy_model->index(sender_index.row(), VALUE_INDEX);
    qDebug() << "Old Value: " << proxy_model->data(index).toString();

    ParamEditDialog edit_dialog(proxy_model, index);
    edit_dialog.setModal(true);
    edit_dialog.exec();
}

void MainWindow::onStationClicked()
{
    qDebug() << "Text: " << ((ParamPushButton *) sender())->text();

    QSortFilterProxyModel *proxy_model = ((ParamPushButton *) sender())->getModel();
    Station *station = ((ParamPushButton *) sender())->station;
    StationEditDialog edit_dialog(proxy_model, station);
    edit_dialog.setModal(true);
    edit_dialog.exec();

}

void MainWindow::onSatelliteClicked()
{
    qDebug() << "Text: " << ((ParamPushButton *) sender())->text();
    QModelIndex sender_index = ((ParamPushButton *) sender())->getIndex();

    QSortFilterProxyModel *proxy_model = ((ParamPushButton *) sender())->getModel();
    QModelIndex index = proxy_model->index(sender_index.row(), VALUE_INDEX);
    qDebug() << "Old Value: " << proxy_model->data(index).toString();

    ParamEditDialog edit_dialog(proxy_model, index);
    edit_dialog.setModal(true);
    edit_dialog.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}
