#include "bindingwizardtypeselectpage.h"
#include "ui_bindingwizardtypeselectpage.h"

BindingWizardTypeSelectPage::BindingWizardTypeSelectPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardTypeSelectPage)
{
    ui->setupUi(this);
}

BindingWizardTypeSelectPage::~BindingWizardTypeSelectPage()
{
    delete ui;
}
