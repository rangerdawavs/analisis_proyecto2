#include "laberinto.h"
#include <QDebug>
laberinto::laberinto()
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            this->matriz[i][j]=0;
        }
    }
    this->matriz[0][0]=1;
    this->start = new nodoArbol(nullptr,nullptr,nullptr,nullptr,0,0,0);
}
