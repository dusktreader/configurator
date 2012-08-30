#include "bindingwizarddirectpage.h"
#include "ui_bindingwizarddirectpage.h"

BindingWizardDirectPage::BindingWizardDirectPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardDirectPage)
{
    ui->setupUi(this);

    registerField( "direct.value*", ui->valueBox );
}

BindingWizardDirectPage::~BindingWizardDirectPage()
{
    delete ui;
}
