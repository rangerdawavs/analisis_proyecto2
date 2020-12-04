#ifndef NODOARBOL_H
#define NODOARBOL_H

class nodoArbol{
public:
    nodoArbol* parent;
    nodoArbol* izq;
    nodoArbol* der;
    nodoArbol* frente;
    int corX;
    int corY;
    int pointer;
    nodoArbol(nodoArbol* _parent,
    nodoArbol* _izq,
    nodoArbol* _der,
    nodoArbol* _frente,
    int _corX,
    int _corY,
    int _pointer);
};

#endif // NODOARBOL_H
