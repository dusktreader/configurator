#include "finitestatebindingdialog.h"
#include "ui_finitestatebindingdialog.h"

FiniteStateBindingDialog::FiniteStateBindingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiniteStateBindingDialog)
{
    ui->setupUi(this);
}

FiniteStateBindingDialog::~FiniteStateBindingDialog()
{
    delete ui;
}
