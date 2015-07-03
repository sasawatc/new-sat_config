/********************************************************************************
** Form generated from reading UI file 'parameditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMEDITDIALOG_H
#define UI_PARAMEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ParamEditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *param_name_label;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *old_value_lineEdit;
    QFormLayout *formLayout_3;
    QLabel *label_2;
    QLineEdit *new_value_lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *set_param_pushButton;
    QPushButton *close_pushButton;

    void setupUi(QDialog *ParamEditDialog)
    {
        if (ParamEditDialog->objectName().isEmpty())
            ParamEditDialog->setObjectName(QStringLiteral("ParamEditDialog"));
        ParamEditDialog->resize(834, 368);
        verticalLayout = new QVBoxLayout(ParamEditDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(ParamEditDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(150, 0));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        param_name_label = new QLabel(ParamEditDialog);
        param_name_label->setObjectName(QStringLiteral("param_name_label"));
        QFont font1;
        font1.setPointSize(11);
        param_name_label->setFont(font1);

        horizontalLayout_2->addWidget(param_name_label);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setHorizontalSpacing(6);
        formLayout_2->setVerticalSpacing(6);
        label = new QLabel(ParamEditDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(150, 0));
        label->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        old_value_lineEdit = new QLineEdit(ParamEditDialog);
        old_value_lineEdit->setObjectName(QStringLiteral("old_value_lineEdit"));
        old_value_lineEdit->setMinimumSize(QSize(0, 30));
        old_value_lineEdit->setFocusPolicy(Qt::NoFocus);
        old_value_lineEdit->setFrame(false);
        old_value_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, old_value_lineEdit);


        verticalLayout->addLayout(formLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_3->setHorizontalSpacing(6);
        formLayout_3->setVerticalSpacing(6);
        label_2 = new QLabel(ParamEditDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        new_value_lineEdit = new QLineEdit(ParamEditDialog);
        new_value_lineEdit->setObjectName(QStringLiteral("new_value_lineEdit"));
        new_value_lineEdit->setMinimumSize(QSize(0, 30));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, new_value_lineEdit);


        verticalLayout->addLayout(formLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        set_param_pushButton = new QPushButton(ParamEditDialog);
        set_param_pushButton->setObjectName(QStringLiteral("set_param_pushButton"));

        horizontalLayout->addWidget(set_param_pushButton);

        close_pushButton = new QPushButton(ParamEditDialog);
        close_pushButton->setObjectName(QStringLiteral("close_pushButton"));

        horizontalLayout->addWidget(close_pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 100);
        verticalLayout->setStretch(4, 1);
        QWidget::setTabOrder(set_param_pushButton, close_pushButton);

        retranslateUi(ParamEditDialog);

        QMetaObject::connectSlotsByName(ParamEditDialog);
    } // setupUi

    void retranslateUi(QDialog *ParamEditDialog)
    {
        ParamEditDialog->setWindowTitle(QApplication::translate("ParamEditDialog", "Update Sattelite Parameter", 0));
        label_4->setText(QApplication::translate("ParamEditDialog", "Parameter Name:", 0));
        param_name_label->setText(QApplication::translate("ParamEditDialog", "TextLabel", 0));
        label->setText(QApplication::translate("ParamEditDialog", "Old Value:", 0));
        label_2->setText(QApplication::translate("ParamEditDialog", "New Value:", 0));
        set_param_pushButton->setText(QApplication::translate("ParamEditDialog", "Set Parameter", 0));
        close_pushButton->setText(QApplication::translate("ParamEditDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ParamEditDialog: public Ui_ParamEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMEDITDIALOG_H
