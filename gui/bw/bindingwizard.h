#ifndef BINDINGWIZARD_H
#define BINDINGWIZARD_H

#include <QWizard>
#include <QWizardPage>

#include <bindingwizardintropage.h>
#include <bindingwizardtypeselectpage.h>
#include <bindingwizarddirectpage.h>
#include <bindingwizardfinitepage.h>
#include <bindingwizardnumericalpage.h>

namespace Ui {
class BindingWizard;
}

class BindingWizard : public QWizard
{
    Q_OBJECT


public:
    explicit BindingWizard(QWidget *parent = 0);
    ~BindingWizard();

    int nextId() const;
    int lastId;

    enum PageId
    {
        INTRO_PAGE,
        TYPE_PAGE,
        DIRECT_PAGE,
        FINITE_PAGE,
        NUMERIC_PAGE
    };

private:
    Ui::BindingWizard *ui;
};

#endif // BINDINGWIZARD_H
