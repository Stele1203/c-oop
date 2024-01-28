//
// Created by User on 1/28/2024.
//
#include <iostream>
#include "DatumStack.h"

using namespace std;

DatumStack::DatumStack() {
    niz= new Datum[100];
    brElem=0;
    kapacitet=100;
}


void DatumStack::push(Datum d) {
    if(brElem==kapacitet){
        Datum* novi= new Datum[kapacitet+10];
        for(int i=0;i<brElem;i++){
            novi[i]=niz[i];
        }
        novi[brElem]=d;
        delete[] niz;
        niz=novi;
        delete[] novi;
        brElem++;
        kapacitet+=10;
        return;
    }
    niz[brElem]=d;
    brElem++;
    return;
}


Datum DatumStack::pop() {
    if(brElem<=0){
        cout<<"Stek je prazan";
        exit(1);
    }
    Datum tmp= niz[brElem-1];
    Datum* tmp_niz= new Datum[kapacitet];

    for(int i=0;i<brElem-1;i++){
        tmp_niz[i]=niz[i];
    }
    delete[] niz;
    niz=tmp_niz;
    delete[] tmp_niz;
    return tmp;
}

DatumStack& DatumStack::sortiraj() {
    for(int i=0;i<brElem;i++){
        for(int j=i+1;j<brElem;j++){
            if(niz[i].compareTo(niz[j])==-1){
                Datum tmp= niz[i];
                niz[i]=niz[j];
                niz[j]=tmp;
            }
        }
    }
    return *this;
}

void DatumStack::ispisiStack() {
    for(int i=0;i<brElem;i++){
        cout<<niz[i].d<<" "<<niz[i].m<<" "<<niz[i].g<<endl;
    }
}