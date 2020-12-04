#ifndef LABERINTO_H
#define LABERINTO_H
#include "nodoarbol.h"

class laberinto
{
private:
    nodoArbol* start;
public:
    int height;
    int width;
    int matriz[40][40];
    laberinto();
    nodoArbol* getStart();
    void build();
    void build(nodoArbol* nodo);
    bool buildLeft(nodoArbol* nodo);
    bool buildRight(nodoArbol* nodo);
    bool buildforw(nodoArbol* nodo);
    bool buildable(int x,int y,int pointer);
};

#endif // LABERINTO_H
