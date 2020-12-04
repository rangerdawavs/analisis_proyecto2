#include "laberinto.h"
#include <QDebug>
#include <queue>
#include <time.h>

std::queue <nodoArbol*> buildorder;

laberinto::laberinto()
{
    this->height=20;
    this->width=20;
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
    int rnd3=rand()%20;
    int rnd1=0;
    if(rnd3==8){
        rnd1=1;
    }
    if(rnd3==9){
        rnd1=2;
    }
    int rnd2;
    int i=0;
    int j=1;
    while(rnd1>=0 && i<50){
        rnd2=rand()%3;
        if(rnd2==0 && j%2!=0 && buildforw(nodo)){
            buildorder.push(nodo->frente);
            j*=2;
            rnd1--;
        }
        if(rnd2==1 && j%3!=0 && buildLeft(nodo)){
            buildorder.push(nodo->izq);
            j*=3;
            rnd1--;
        }
        if(rnd2==2 && j%5!=0 && buildRight(nodo)){
            buildorder.push(nodo->der);
            j*=5;
            rnd1--;
        }
        i++;
    }
    while(!buildorder.empty()){
        nodoArbol* cur=buildorder.front();
        buildorder.pop();
        build(cur);
    }
    /*
    if(buildforw(nodo)){
        build(nodo->frente);
    }
    if(buildLeft(nodo)){
        build(nodo->izq);
    }
    if(buildRight(nodo)){
        build(nodo->der);
    }*/
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
        nodoArbol* newNode=new nodoArbol(nodo,nullptr,nullptr,nullptr,corX,corY,newDir);
        nodo->frente=newNode;
        matriz[corX][corY]=1;
        return true;
    }
    return false;
}

void laberinto::res_laberinto(nodoArbol* nodo){
    if(nodo->izq!=nullptr){
        res_laberinto(nodo->izq);
    }
    if(nodo->frente!=nullptr){
        res_laberinto(nodo->frente);
    }
    if(nodo->der!=nullptr){
        res_laberinto(nodo->der);
    }
    matriz[nodo->corX][nodo->corY]=0;
    delete nodo;
}

void laberinto::res_laberinto(){
    res_laberinto(getStart());
    start=new nodoArbol(nullptr,nullptr,nullptr,nullptr,0,0,0);
    matriz[0][0]=1;
}

bool laberinto::solve(nodoArbol* nodo){
    if(nodo->corX==19 && nodo->corY==19){
        sol.push(nodo);
        return true;
    }
    else{
        if(nodo->izq!=nullptr){
            if(solve(nodo->izq)){
                sol.push(nodo);
                return true;
            }
        }
        if(nodo->frente!=nullptr){
            if(solve(nodo->frente)){
                sol.push(nodo);
                return true;
            }
        }
        if(nodo->der!=nullptr){
            if(solve(nodo->der)){
                sol.push(nodo);
                return true;
            }
        }
        return false;
    }
}
