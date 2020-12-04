#include "nodoarbol.h"
nodoArbol::nodoArbol(nodoArbol* _parent,nodoArbol* _izq,nodoArbol* _der,nodoArbol* _frente,int _corX,int _corY,int _pointer){
    this->parent=_parent;
    this->izq=_izq;
    this->der=_der;
    this->frente=_frente;
    this->corX=_corX;
    this->corY=_corY;
    this->pointer=_pointer;
}
