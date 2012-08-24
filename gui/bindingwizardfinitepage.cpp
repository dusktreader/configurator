#include "bindingwizardfinitepage.h"
#include "ui_bindingwizardfinitepage.h"

BindingWizardFinitePage::BindingWizardFinitePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::BindingWizardFinitePage)
{
    ui->setupUi(this);
}

BindingWizardFinitePage::~BindingWizardFinitePage()
{
    delete ui;
}
