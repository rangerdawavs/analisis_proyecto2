#include "laberinto.h"
#include <QDebug>
laberinto::laberinto()
{
    this->height=40;
    this->width=40;
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            this->matriz[i][j]=0;
        }
    }
    this->matriz[0][0]=1;
    this->start = new nodoArbol(nullptr,nullptr,nullptr,nullptr,0,0,0);
}

nodoArbol* laberinto::getStart(){
    return start;
}

bool laberinto::buildable(int x, int y,int pointer){
    if(x<0 || x>=width || y<0 || y>=height){
        return false;
    }
    if(x+1<width && matriz[x+1][y]==1 && pointer!=2){
        return false;
    }
    if(y+1<height && matriz[x][y+1]==1 && pointer!=1){
        return false;
    }
    if(x-1>=0 && matriz[x-1][y]==1 && pointer!=0){
        return false;
    }
    if(y-1>=0 && matriz[x][y-1]==1 && pointer!=3){
        return false;
    }
    return true;
}
void laberinto::build(){
    build(getStart());
}

void laberinto::build(nodoArbol* nodo){
    if(buildLeft(nodo)){
        build(nodo->izq);
    }else if(buildforw(nodo)){
        build(nodo->frente);
    }else if(buildRight(nodo)){
        build(nodo->der);
    }
}

bool laberinto::buildLeft(nodoArbol* nodo){
    int corX=nodo->corX;
    int corY=nodo->corY;
    int dir=nodo->pointer;
    int newDir=(dir+1)%4;
    if(dir==0){
        corY--;
    }
    if(dir==1){
        corX--;
    }
    if(dir==2){
        corY++;
    }
    if(dir==3){
        corX++;
    }
    if(buildable(corX,corY,newDir)){
        qDebug()<<"adding Node left at ("<<corX<<","<<corY<<")";
        nodoArbol* newNode=new nodoArbol(nodo,nullptr,nullptr,nullptr,corX,corY,newDir);
        nodo->izq=newNode;
        matriz[corX][corY]=1;
        return true;
    }
    return false;
}

bool laberinto::buildRight(nodoArbol* nodo){
    int corX=nodo->corX;
    int corY=nodo->corY;
    int dir=nodo->pointer;
    int newDir=(dir+3)%4;
    if(dir==0){
        corY++;
    }
    if(dir==1){
        corX++;
    }
    if(dir==2){
        corY--;
    }
    if(dir==3){
        corX--;
    }
    if(buildable(corX,corY,newDir)){
        qDebug()<<"adding Node right at ("<<corX<<","<<corY<<")";
        nodoArbol* newNode=new nodoArbol(nodo,nullptr,nullptr,nullptr,corX,corY,newDir);
        nodo->der=newNode;
        matriz[corX][corY]=1;
        return true;
    }
    return false;
}

bool laberinto::buildforw(nodoArbol * nodo){
    int corX=nodo->corX;
    int corY=nodo->corY;
    int dir=nodo->pointer;
    int newDir=dir;
    if(dir==0){
        corX++;
    }
    if(dir==1){
        corY--;
    }
    if(dir==2){
        corX--;
    }
    if(dir==3){
        corY++;
    }
    if(buildable(corX,corY,newDir)){
        qDebug()<<"adding Node forward at ("<<corX<<","<<corY<<")";
        nodoArbol* newNode=new nodoArbol(nodo,nullptr,nullptr,nullptr,corX,corY,newDir);
        nodo->frente=newNode;
        matriz[corX][corY]=1;
        return true;
    }
    return false;
}
