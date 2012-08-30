#ifndef BINDINGWIZARDNUMERICALPAGE_H
#define BINDINGWIZARDNUMERICALPAGE_H

#include <QWizardPage>

namespace Ui {
class BindingWizardNumericalPage;
}

class BindingWizardNumericalPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit BindingWizardNumericalPage(QWidget *parent = 0);
    ~BindingWizardNumericalPage();
    
private:
    Ui::BindingWizardNumericalPage *ui;
};

#endif // BINDINGWIZARDNUMERICALPAGE_H
