#ifndef BINDINGWIZARDINTROPAGE_H
#define BINDINGWIZARDINTROPAGE_H

#include <QWizardPage>

namespace Ui {
class BindingWizardIntroPage;
}

class BindingWizardIntroPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit BindingWizardIntroPage(QWidget *parent = 0);
    ~BindingWizardIntroPage();
    
private:
    Ui::BindingWizardIntroPage *ui;
};

#endif // BINDINGWIZARDINTROPAGE_H
