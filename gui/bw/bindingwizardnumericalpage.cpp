#include "bindingwizardnumericalpage.h"
#include "ui_bindingwizardnumericalpage.h"

BindingWizardNumericalPage::BindingWizardNumericalPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardNumericalPage)
{
    ui->setupUi(this);
}

BindingWizardNumericalPage::~BindingWizardNumericalPage()
{
    delete ui;
}
