//
// Created by User on 1/28/2024.
//

#include "iostream"
#include "Datum.h"

using namespace std;

int Datum::getG() {
    return g;
}

int Datum::getM() {
    return m;
}

int Datum::getD() {
    return d;
}


void Datum::setG(int g) {
    this->g=g;
}

void Datum::setM(int m) {
    this->m=m;
}

void Datum::setD(int d) {
    this->d=d;
}

Datum::Datum() {
    d=1;
    m=1;
    g=2000;
}

Datum::Datum(int d, int m, int g) {
    this->g=g;
    this->m=m;
    this->d=d;
}

int Datum::compareTo(Datum tmp_datum) {
    if(this->g<tmp_datum.g){
        return 1;
    }else if(this->g>tmp_datum.g) {
        return -1;
    }else if(this->m<tmp_datum.m){
        return 1;
    }else if(this->m>tmp_datum.m){
        return -1;
    }else if(this->d<tmp_datum.d){
        return 1;
    }else if(this->d>tmp_datum.d){
        return -1;
    }else{
        return 0;
    }
}

void Datum::ispisiDatum() {
    cout<<this->d<<" "<< this->m<<" "<< this->g<<endl;
}