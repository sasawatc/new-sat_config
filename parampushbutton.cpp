#include "parampushbutton.h"

ParamPushButton::ParamPushButton(const QString &text, QSortFilterProxyModel *model, QModelIndex index, QWidget *parent):QPushButton(text, parent), model_index(index), proxy_model(model)
{

}

ParamPushButton::ParamPushButton(const QString &text, QSortFilterProxyModel *model, Station *station, QWidget *parent):QPushButton(text, parent), station(station), proxy_model(model)
{

}

ParamPushButton::~ParamPushButton()
{

}

QModelIndex ParamPushButton::getIndex()
{
    return model_index;
}

QSortFilterProxyModel * ParamPushButton::getModel()
{
    return proxy_model;
}
