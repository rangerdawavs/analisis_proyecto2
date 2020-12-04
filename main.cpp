#include "mainwindow.h"
#include "renderarea.h"
#include <QApplication>
#include <QWidget>
/*
https://github.com/rangerdawavs/analisis_proyecto2.git
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
