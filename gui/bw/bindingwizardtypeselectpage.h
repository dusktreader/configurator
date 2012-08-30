#ifndef BINDINGWIZARDTYPESELECTPAGE_H
#define BINDINGWIZARDTYPESELECTPAGE_H

#include <QWizardPage>

namespace Ui {
class BindingWizardTypeSelectPage;
}

class BindingWizardTypeSelectPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit BindingWizardTypeSelectPage(QWidget *parent = 0);
    ~BindingWizardTypeSelectPage();
    
private:
    Ui::BindingWizardTypeSelectPage *ui;
};

#endif // BINDINGWIZARDTYPESELECTPAGE_H
