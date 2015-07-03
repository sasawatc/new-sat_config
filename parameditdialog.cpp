#include "parameditdialog.h"
#include "ui_parameditdialog.h"


#include <QDebug>

ParamEditDialog::ParamEditDialog(QSortFilterProxyModel *model, const QModelIndex index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParamEditDialog)
{
    ui->setupUi(this);

    this->model_index = index;
    this->proxy_model = model;

    QModelIndex param_name_index = proxy_model->index(model_index.row(), NAME_INDEX);
    QString param_name = proxy_model->data(param_name_index).toString();

    QModelIndex old_value_index = proxy_model->index(model_index.row(), VALUE_INDEX);
    QString old_value = proxy_model->data(old_value_index).toString();

    ui->param_name_label->setText(param_name);
    ui->old_value_lineEdit->setText(old_value);

    connect(ui->set_param_pushButton, SIGNAL(clicked()), this, SLOT(setParameterClicked()));
    connect(ui->close_pushButton, SIGNAL(clicked()), this, SLOT(closeClicked()));
}

void ParamEditDialog::setParameterClicked()
{
    QString new_value = ui->new_value_lineEdit->text();

    QModelIndex new_value_index = proxy_model->index(model_index.row(), VALUE_NEW_INDEX);
    proxy_model->setData(new_value_index, new_value);

    closeClicked();
}

void ParamEditDialog::closeClicked()
{
    this->close();
}

ParamEditDialog::~ParamEditDialog()
{
    delete ui;
}

