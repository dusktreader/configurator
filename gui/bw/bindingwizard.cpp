#include "bindingwizard.h"
#include "ui_bindingwizard.h"

BindingWizard::BindingWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::BindingWizard)
{
    ui->setupUi(this);

    setPage(   INTRO_PAGE, new BindingWizardIntroPage      );
    setPage(    TYPE_PAGE, new BindingWizardTypeSelectPage );
    setPage(  DIRECT_PAGE, new BindingWizardDirectPage     );
    setPage(  FINITE_PAGE, new BindingWizardFinitePage     );
    setPage( NUMERIC_PAGE, new BindingWizardNumericalPage  );

    setStartId( INTRO_PAGE );

    lastId = -1;
}

BindingWizard::~BindingWizard()
{
    delete ui;
}

int BindingWizard::nextId()
{
    int nextPageId = -1;

    switch( currentId() )
    {
    case INTRO_PAGE:
        nextPageId = TYPE_PAGE;
        break;
    case TYPE_PAGE:
        /// @todo type selector
        break;
    case DIRECT_PAGE:
    case FINITE_PAGE:
    case NUMERIC_PAGE:
        nextPageId = -1;
        break;
    }

    lastId = currentId();

    return nextPageId;
}


