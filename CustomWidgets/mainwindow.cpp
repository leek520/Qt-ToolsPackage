#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "multicombobox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MultiComboBox *mCmb = new MultiComboBox(this);
    mCmb->addItems(QStringList()<<"1"<<"2"<<"3"<<"4"<<"5"<<"6");
}

MainWindow::~MainWindow()
{
    delete ui;
}
