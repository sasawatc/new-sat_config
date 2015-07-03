#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

QString PasswordDialog::getText()
{
    return this->ui->lineEdit->text()
}

void PasswordDialog::on_buttonBox_accepted()
{
    return
}
