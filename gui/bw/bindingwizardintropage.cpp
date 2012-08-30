#include "bindingwizardintropage.h"
#include "ui_bindingwizardintropage.h"

BindingWizardIntroPage::BindingWizardIntroPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardIntroPage)
{
    ui->setupUi(this);
}

BindingWizardIntroPage::~BindingWizardIntroPage()
{
    delete ui;
}
