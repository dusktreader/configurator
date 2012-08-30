#ifndef BINDINGWIZARDDIRECTPAGE_H
#define BINDINGWIZARDDIRECTPAGE_H

#include <QWizardPage>

namespace Ui {
class BindingWizardDirectPage;
}

class BindingWizardDirectPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit BindingWizardDirectPage(QWidget *parent = 0);
    ~BindingWizardDirectPage();
    
private:
    Ui::BindingWizardDirectPage *ui;
};

#endif // BINDINGWIZARDDIRECTPAGE_H
