/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Changed;
    QAction *actionSave_and_Send_file;
    QAction *actionPrint;
    QAction *actionSCC;
    QAction *actionMPC_PL;
    QAction *action_MPC_AOCS;
    QAction *actionFDS;
    QAction *actionTransfer_files;
    QAction *actionSave_to_conf_sat_txt;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *scc_tab;
    QVBoxLayout *verticalLayout;
    QGridLayout *scc_gridLayout;
    QLabel *scc_table_head_label;
    QTableView *scc_tableView;
    QWidget *mpc_pl_tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *mpc_pl_buttons_horizontalLayout;
    QVBoxLayout *mpc_pl_stations_layout;
    QLabel *mpc_pl_stations_label;
    QGridLayout *mpc_pl_stations_gridLayout;
    QVBoxLayout *mpc_pl_satellites_layout;
    QLabel *mpc_pl_table_head_label;
    QTableView *mpc_pl_tableView;
    QWidget *mpc_aocs_tab;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *mpc_aocs_gridLayout;
    QLabel *mpc_aocs_table_head_label;
    QTableView *mpc_aocs_tableView;
    QWidget *fds_tab;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *fds_gridLayout;
    QLabel *fds_table_head_label;
    QTableView *fds_tableView;
    QMenuBar *menuBar;
    QMenu *menuSave_changed;
    QMenu *menuType;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1101, 727);
        actionSave_Changed = new QAction(MainWindow);
        actionSave_Changed->setObjectName(QStringLiteral("actionSave_Changed"));
        actionSave_and_Send_file = new QAction(MainWindow);
        actionSave_and_Send_file->setObjectName(QStringLiteral("actionSave_and_Send_file"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionSCC = new QAction(MainWindow);
        actionSCC->setObjectName(QStringLiteral("actionSCC"));
        actionMPC_PL = new QAction(MainWindow);
        actionMPC_PL->setObjectName(QStringLiteral("actionMPC_PL"));
        action_MPC_AOCS = new QAction(MainWindow);
        action_MPC_AOCS->setObjectName(QStringLiteral("action_MPC_AOCS"));
        actionFDS = new QAction(MainWindow);
        actionFDS->setObjectName(QStringLiteral("actionFDS"));
        actionTransfer_files = new QAction(MainWindow);
        actionTransfer_files->setObjectName(QStringLiteral("actionTransfer_files"));
        actionSave_to_conf_sat_txt = new QAction(MainWindow);
        actionSave_to_conf_sat_txt->setObjectName(QStringLiteral("actionSave_to_conf_sat_txt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        scc_tab = new QWidget();
        scc_tab->setObjectName(QStringLiteral("scc_tab"));
        verticalLayout = new QVBoxLayout(scc_tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scc_gridLayout = new QGridLayout();
        scc_gridLayout->setSpacing(6);
        scc_gridLayout->setObjectName(QStringLiteral("scc_gridLayout"));

        verticalLayout->addLayout(scc_gridLayout);

        scc_table_head_label = new QLabel(scc_tab);
        scc_table_head_label->setObjectName(QStringLiteral("scc_table_head_label"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        scc_table_head_label->setFont(font);

        verticalLayout->addWidget(scc_table_head_label);

        scc_tableView = new QTableView(scc_tab);
        scc_tableView->setObjectName(QStringLiteral("scc_tableView"));

        verticalLayout->addWidget(scc_tableView);

        tabWidget->addTab(scc_tab, QString());
        mpc_pl_tab = new QWidget();
        mpc_pl_tab->setObjectName(QStringLiteral("mpc_pl_tab"));
        verticalLayout_2 = new QVBoxLayout(mpc_pl_tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mpc_pl_buttons_horizontalLayout = new QHBoxLayout();
        mpc_pl_buttons_horizontalLayout->setSpacing(6);
        mpc_pl_buttons_horizontalLayout->setObjectName(QStringLiteral("mpc_pl_buttons_horizontalLayout"));
        mpc_pl_stations_layout = new QVBoxLayout();
        mpc_pl_stations_layout->setSpacing(6);
        mpc_pl_stations_layout->setObjectName(QStringLiteral("mpc_pl_stations_layout"));
        mpc_pl_stations_label = new QLabel(mpc_pl_tab);
        mpc_pl_stations_label->setObjectName(QStringLiteral("mpc_pl_stations_label"));

        mpc_pl_stations_layout->addWidget(mpc_pl_stations_label);

        mpc_pl_stations_gridLayout = new QGridLayout();
        mpc_pl_stations_gridLayout->setSpacing(6);
        mpc_pl_stations_gridLayout->setObjectName(QStringLiteral("mpc_pl_stations_gridLayout"));

        mpc_pl_stations_layout->addLayout(mpc_pl_stations_gridLayout);


        mpc_pl_buttons_horizontalLayout->addLayout(mpc_pl_stations_layout);

        mpc_pl_satellites_layout = new QVBoxLayout();
        mpc_pl_satellites_layout->setSpacing(6);
        mpc_pl_satellites_layout->setObjectName(QStringLiteral("mpc_pl_satellites_layout"));

        mpc_pl_buttons_horizontalLayout->addLayout(mpc_pl_satellites_layout);


        verticalLayout_2->addLayout(mpc_pl_buttons_horizontalLayout);

        mpc_pl_table_head_label = new QLabel(mpc_pl_tab);
        mpc_pl_table_head_label->setObjectName(QStringLiteral("mpc_pl_table_head_label"));
        mpc_pl_table_head_label->setFont(font);

        verticalLayout_2->addWidget(mpc_pl_table_head_label);

        mpc_pl_tableView = new QTableView(mpc_pl_tab);
        mpc_pl_tableView->setObjectName(QStringLiteral("mpc_pl_tableView"));

        verticalLayout_2->addWidget(mpc_pl_tableView);

        tabWidget->addTab(mpc_pl_tab, QString());
        mpc_aocs_tab = new QWidget();
        mpc_aocs_tab->setObjectName(QStringLiteral("mpc_aocs_tab"));
        verticalLayout_4 = new QVBoxLayout(mpc_aocs_tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        mpc_aocs_gridLayout = new QGridLayout();
        mpc_aocs_gridLayout->setSpacing(6);
        mpc_aocs_gridLayout->setObjectName(QStringLiteral("mpc_aocs_gridLayout"));

        verticalLayout_4->addLayout(mpc_aocs_gridLayout);

        mpc_aocs_table_head_label = new QLabel(mpc_aocs_tab);
        mpc_aocs_table_head_label->setObjectName(QStringLiteral("mpc_aocs_table_head_label"));
        mpc_aocs_table_head_label->setFont(font);

        verticalLayout_4->addWidget(mpc_aocs_table_head_label);

        mpc_aocs_tableView = new QTableView(mpc_aocs_tab);
        mpc_aocs_tableView->setObjectName(QStringLiteral("mpc_aocs_tableView"));

        verticalLayout_4->addWidget(mpc_aocs_tableView);

        tabWidget->addTab(mpc_aocs_tab, QString());
        fds_tab = new QWidget();
        fds_tab->setObjectName(QStringLiteral("fds_tab"));
        verticalLayout_3 = new QVBoxLayout(fds_tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        fds_gridLayout = new QGridLayout();
        fds_gridLayout->setSpacing(6);
        fds_gridLayout->setObjectName(QStringLiteral("fds_gridLayout"));

        verticalLayout_3->addLayout(fds_gridLayout);

        fds_table_head_label = new QLabel(fds_tab);
        fds_table_head_label->setObjectName(QStringLiteral("fds_table_head_label"));
        fds_table_head_label->setFont(font);

        verticalLayout_3->addWidget(fds_table_head_label);

        fds_tableView = new QTableView(fds_tab);
        fds_tableView->setObjectName(QStringLiteral("fds_tableView"));

        verticalLayout_3->addWidget(fds_tableView);

        tabWidget->addTab(fds_tab, QString());

        verticalLayout_5->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1101, 21));
        menuSave_changed = new QMenu(menuBar);
        menuSave_changed->setObjectName(QStringLiteral("menuSave_changed"));
        menuType = new QMenu(menuBar);
        menuType->setObjectName(QStringLiteral("menuType"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSave_changed->menuAction());
        menuBar->addAction(menuType->menuAction());
        menuSave_changed->addAction(actionSave_to_conf_sat_txt);
        menuSave_changed->addSeparator();
        menuSave_changed->addAction(actionTransfer_files);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Satellite Configuration", 0));
        actionSave_Changed->setText(QApplication::translate("MainWindow", "Save file", 0));
        actionSave_and_Send_file->setText(QApplication::translate("MainWindow", "Send file", 0));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", 0));
        actionSCC->setText(QApplication::translate("MainWindow", "SCC", 0));
        actionMPC_PL->setText(QApplication::translate("MainWindow", "MPC_PL", 0));
        action_MPC_AOCS->setText(QApplication::translate("MainWindow", "\n"
"MPC_AOCS", 0));
        actionFDS->setText(QApplication::translate("MainWindow", "FDS", 0));
        actionTransfer_files->setText(QApplication::translate("MainWindow", "Transfer files", 0));
        actionSave_to_conf_sat_txt->setText(QApplication::translate("MainWindow", "Save to conf_sat.txt", 0));
        scc_table_head_label->setText(QApplication::translate("MainWindow", "I_CMOB", 0));
        tabWidget->setTabText(tabWidget->indexOf(scc_tab), QApplication::translate("MainWindow", "SCC", 0));
        mpc_pl_stations_label->setText(QApplication::translate("MainWindow", "Stations:", 0));
        mpc_pl_table_head_label->setText(QApplication::translate("MainWindow", "I_CNFM", 0));
        tabWidget->setTabText(tabWidget->indexOf(mpc_pl_tab), QApplication::translate("MainWindow", "MPC_PL", 0));
        mpc_aocs_table_head_label->setText(QApplication::translate("MainWindow", "I_CMOB", 0));
        tabWidget->setTabText(tabWidget->indexOf(mpc_aocs_tab), QApplication::translate("MainWindow", "MPC_AOCS", 0));
        fds_table_head_label->setText(QApplication::translate("MainWindow", "I_CNFF", 0));
        tabWidget->setTabText(tabWidget->indexOf(fds_tab), QApplication::translate("MainWindow", "FDS", 0));
        menuSave_changed->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuType->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
