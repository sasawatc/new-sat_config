#ifndef PARAMEDITDIALOG_H
#define PARAMEDITDIALOG_H

//#include "mainwindow.h"
#include "globalcontext.h"
#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class ParamEditDialog;
}
//class MainWindow;
class ParamEditDialog : public QDialog
{
    Q_OBJECT

public:
//    MainWindow *mw;
//    explicit ParamEditDialog(){}
    explicit ParamEditDialog(QSortFilterProxyModel *model, const QModelIndex index, QWidget *parent = 0);
    ~ParamEditDialog();

private:
    Ui::ParamEditDialog *ui;
    QModelIndex model_index;
    QSortFilterProxyModel *proxy_model;

public slots:
    void setParameterClicked();
    void closeClicked();
};

#endif // PARAMEDITDIALOG_H
