//
// Created by User on 2/11/2024.
//
#ifndef VEKTOR2_VEKTOR_CPP
#define VEKTOR2_VEKTOR_CPP
#include "Vektor.h"
#include "iostream"
using namespace std;

template <class T>
Vektor<T>::Vektor() {
    for(int i=0;i<10;i++){
        this->zauzet[i]= false;
    }
}

template<class T>
void Vektor<T>::dodaj(T elem) {
    for(int i=0;i<10;i++){
        if(this->zauzet[i]== false){
            this->data[i]=elem;
            this->zauzet[i]== true;
            return;
        }
    }
    throw overflow_error("Niz je pun");
}

template<class T>
void Vektor<T>::Ukloni(int i) {
    this->zauzet[i]=false;
    this->data[i]=0;
}


template<class T>
void Vektor<T>::rotirajZaK(int k) {
    T tmp[k];
    bool tmp2[k];
    for(int i=0;i<k;i++){
        tmp[i]=this->data[10-k+i];
        tmp2[i]=this->zauzet[10-k+i];
    }

    for(int i=0;i<10-k;i++){
        this->data[i]=this->data[i+k];
        this->zauzet[i]=this->zauzet[i+k];
    }

    for(int i=0;i<k;i++){
        this->zauzet[i]=tmp2[i];
        this->data[i]=tmp[i];
    }
}


template <class T>
Vektor<T> Vektor<T>::defragmentKopija() {
    for(int i=0;i<10;i++){
        if(!this->zauzet[i]){
            for(int k=9;k>=0;k--){
                if(this->zauzet[k]){
                    bool tmpZauzet=this->zauzet[i];
                    T tmp= this->data[i];
                    this->data[i]=this->data[k];
                    this->zauzet[i]=this->zauzet[k];
                    this->zauzet[k]=tmpZauzet;
                    this->data[k]=tmp;
                }
            }
        }
    }
    return *this;
}

#endif