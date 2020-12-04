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

void MainWindow::on_Exportar_clicked(){
    
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
    
    WriterXml.writeEndDocument();
    xml.close();
}
