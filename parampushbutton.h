#ifndef PARAMPUSHBUTTON_H
#define PARAMPUSHBUTTON_H

#include "station.h"
#include "satellite.h"

#include <QPushButton>
#include <QSortFilterProxyModel>

class ParamPushButton : public QPushButton
{
public:
    ParamPushButton(const QString &text, QSortFilterProxyModel *model, QModelIndex index, QWidget *parent=0);
    ParamPushButton(const QString &text, QSortFilterProxyModel *model, Station *station, QWidget *parent=0);
    ~ParamPushButton();
    QModelIndex model_index;
    QSortFilterProxyModel *proxy_model;
    QModelIndex getIndex();
    Station *station;
    QSortFilterProxyModel * getModel();
};

#endif // PARAMPUSHBUTTON_H
