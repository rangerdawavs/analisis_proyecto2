#include "mainwindow.h"
#include "renderarea.h"
#include <QApplication>
#include <QWidget>
//changing
/*
https://github.com/rangerdawavs/analisis_proyecto2.git
 */


int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
