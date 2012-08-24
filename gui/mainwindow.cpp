#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bindingTableWidget_doubleClicked(const QModelIndex &index)
{
    int row = index.row();

    BindingWizard wiz;
    wiz.show();

    BindingPtr binding;

    switch( wiz.lastId )
    {
    case BindingWizard::DIR_PAGE:
        DirectBindingPtr directBinding( new DirectBinding() );
        directBinding->setValue( wiz.fi);

    }
}
