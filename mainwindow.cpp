#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderarea.h"
#include <QDebug>

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
