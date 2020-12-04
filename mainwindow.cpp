#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderarea.h"
#include <QDebug>
#include <qxmlstream.h>
#include <qfile.h>

laberinto* lab= new laberinto();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->renderArea->setLab(lab);
    lab->build();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    ui->renderArea->setSol(arg1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->renderArea->lab->res_laberinto();
    lab->build();
    while(!lab->solve(lab->getStart())){
        ui->renderArea->lab->res_laberinto();
        lab->build();
    }
    ui->renderArea->update();
}
