#include "bindingwizarddirectpage.h"
#include "ui_bindingwizarddirectpage.h"

BindingWizardDirectPage::BindingWizardDirectPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardDirectPage)
{
    ui->setupUi(this);
}

BindingWizardDirectPage::~BindingWizardDirectPage()
{
    delete ui;
}
