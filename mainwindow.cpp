#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cbx_lowbeam_view->setChecked(true);
    ui->cbx_highbeam_view->setChecked(true);
    ui->cbx_lowbeam_view->setEnabled(false);
    ui->cbx_highbeam_view->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cbx_highbeam_stateChanged(int arg1)
{
    bool state= arg1  ? true : false;
    ui->widget->setHighBeamState(state);
}

void MainWindow::on_cbx_lowbeam_stateChanged(int arg1)
{
    bool state= arg1  ? true : false;
    ui->widget->setLowBeamState(state);

}

void MainWindow::on_cbx_highbeam_view_stateChanged(int arg1)
{

}

void MainWindow::on_cbx_lowbeam_view_stateChanged(int arg1)
{

}

