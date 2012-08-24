#ifndef FINITESTATEBINDINGDIALOG_H
#define FINITESTATEBINDINGDIALOG_H

#include <QDialog>

namespace Ui {
class FiniteStateBindingDialog;
}

class FiniteStateBindingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FiniteStateBindingDialog(QWidget *parent = 0);
    ~FiniteStateBindingDialog();
    
private:
    Ui::FiniteStateBindingDialog *ui;
};

#endif // FINITESTATEBINDINGDIALOG_H
