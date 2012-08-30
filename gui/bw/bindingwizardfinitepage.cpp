#include "bindingwizardfinitepage.h"
#include "ui_bindingwizardfinitepage.h"

BindingWizardFinitePage::BindingWizardFinitePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardFinitePage)
{
    ui->setupUi(this);

    registerField( "finite.stateTable", ui->stateTable );
}

BindingWizardFinitePage::~BindingWizardFinitePage()
{
    delete ui;
}

BindingWizardFinitePage::validatePage()
{
    if( ui->stateTable->rowCount() == 0 )
        return false;
}
