#ifndef LABERINTO_H
#define LABERINTO_H
#include "nodoarbol.h"
#include <queue>
#include <cmath>


class laberinto
{
private:
    nodoArbol* start;
public:
    std::queue <nodoArbol*> sol;
    int height;
    int width;
    int matriz[20][20];
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
