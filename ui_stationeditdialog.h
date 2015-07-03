/********************************************************************************
** Form generated from reading UI file 'stationeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONEDITDIALOG_H
#define UI_STATIONEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StationEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *station_label;
    QLabel *station_name_label;
    QTableWidget *station_tableWidget;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StationEditDialog)
    {
        if (StationEditDialog->objectName().isEmpty())
            StationEditDialog->setObjectName(QStringLiteral("StationEditDialog"));
        StationEditDialog->resize(637, 412);
        verticalLayout = new QVBoxLayout(StationEditDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        station_label = new QLabel(StationEditDialog);
        station_label->setObjectName(QStringLiteral("station_label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        station_label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, station_label);

        station_name_label = new QLabel(StationEditDialog);
        station_name_label->setObjectName(QStringLiteral("station_name_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, station_name_label);


        verticalLayout->addLayout(formLayout);

        station_tableWidget = new QTableWidget(StationEditDialog);
        if (station_tableWidget->columnCount() < 2)
            station_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        station_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        station_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        station_tableWidget->setObjectName(QStringLiteral("station_tableWidget"));
        station_tableWidget->setAlternatingRowColors(true);
        station_tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        station_tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        station_tableWidget->horizontalHeader()->setStretchLastSection(false);
        station_tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        station_tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(station_tableWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(StationEditDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalLayout->setStretch(1, 1);

        retranslateUi(StationEditDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StationEditDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StationEditDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StationEditDialog);
    } // setupUi

    void retranslateUi(QDialog *StationEditDialog)
    {
        StationEditDialog->setWindowTitle(QApplication::translate("StationEditDialog", "Dialog", 0));
        station_label->setText(QApplication::translate("StationEditDialog", "Station: ", 0));
        station_name_label->setText(QApplication::translate("StationEditDialog", "TextLabel", 0));
        QTableWidgetItem *___qtablewidgetitem = station_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StationEditDialog", "Old Value", 0));
        QTableWidgetItem *___qtablewidgetitem1 = station_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("StationEditDialog", "New Value", 0));
    } // retranslateUi

};

namespace Ui {
    class StationEditDialog: public Ui_StationEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONEDITDIALOG_H
