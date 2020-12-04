#ifndef NODOARBOL_H
#define NODOARBOL_H

class nodoArbol{
private:
    nodoArbol* parent;
    nodoArbol* izq;
    nodoArbol* der;
    nodoArbol* frente;
    int corX;
    int corY;
public:
    nodoArbol();
};

#endif // NODOARBOL_H
