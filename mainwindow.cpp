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
    while(!lab->solve(lab->getStart())){
        ui->renderArea->lab->res_laberinto();
        lab->build();
    }
    ui->renderArea->update();
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

void MainWindow::on_pushButton_clicked()
{
    QFile xml("Laberinto.xml");
        xml.open(QIODevice::WriteOnly);
        QXmlStreamWriter WriterXml(&xml);
        WriterXml.setAutoFormatting(true);
        WriterXml.writeStartDocument("Matriz");
        for(int x = 0; x <= 19; x++){
            for(int y = 0; y <= 19; y++){
               WriterXml.writeStartElement(QString::number(lab->matriz[x][y]));
               WriterXml.writeEndElement();
            }
        }
        WriterXml.writeEndDocument();
        WriterXml.writeStartDocument("Coordenas de solución");
        lab->solve(lab->getStart());
        nodoArbol* cur;
        while (!lab->sol.empty()){
            cur=lab->sol.front();
            lab->sol.pop();
            WriterXml.writeStartElement("("+QString::number(cur->corX)+","+QString::number(cur->corY)+")");
            WriterXml.writeEndElement();
        }
        WriterXml.writeEndDocument();
        xml.close();
}
