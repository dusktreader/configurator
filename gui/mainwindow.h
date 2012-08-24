#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "bindingwizard.h"

#include "binding/binding.h"
#include "binding/directbinding.h"
#include "binding/dynamicbinding/finitestatebinding.h"
#include "binding/dynamicbinding/numericrangebinding.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bindingTableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
