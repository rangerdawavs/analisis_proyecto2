#include "mainwindow.h"

#include <QApplication>
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
