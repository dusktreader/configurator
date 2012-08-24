#ifndef BINDINGWIZARDFINITEPAGE_H
#define BINDINGWIZARDFINITEPAGE_H

#include <QWizardPage>

namespace Ui {
class BindingWizardFinitePage;
}

class BindingWizardFinitePage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit BindingWizardFinitePage(QWidget *parent = 0);
    ~BindingWizardFinitePage();
    
private:
    Ui::BindingWizardFinitePage *ui;
};

#endif // BINDINGWIZARDFINITEPAGE_H
