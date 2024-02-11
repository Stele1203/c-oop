//
// Created by User on 2/11/2024.
//
#ifndef RIJETKAMATRICA_RIJETKAMATRICA_CPP
#define RIJETKAMATRICA_RIJETKAMATRICA_CPP
#include "RijetkaMatrica.h"
#include "iostream"
using namespace std;
template <class T>
void RijetkaMatrica<T>::set(T elem, int i, int j) {
    if((i>=0 && i<n) && (j>=0 && j<m)){
        int index=-1;
        for(int k=0;k<brElem;k++){
            if(this->cols[k]==j && this->rows[k]==i){
                index=k;
                break;
            }
        }
        if(brElem==1000){
            throw overflow_error("Niz je popunjen");
        }


        if(index==-1){
            this->cols[brElem]=j;
            this->rows[brElem]=i;
            this->data[brElem]=elem;
            brElem++;
        }else{
            this->data[index]=elem;
        }
    }else{
        throw overflow_error("Prekoracenje");
    }
}


template <class T>
T RijetkaMatrica<T>::operator()(int i, int j) const {
    if(i>=0 && i<n && j>=0 && j<m){
        //int index=-1;
        for(int k=0;k<brElem;k++){
            if(cols[k]==j && rows[k]==i){
                return this->data[k];
            }
        }
        throw overflow_error("Ne postoji taj element");
    }else{
        throw overflow_error("Prekoracenje matrice");
    }
}


//ako je mnozenje skalara u pitanju;
/*
template <class T>
RijetkaMatrica<T> RijetkaMatrica<T>::operator*(const T skalar) const {
    RijetkaMatrica<T> tmp=*this;

    for(int i=0;i<brElem;i++){
        tmp.data[i]*=skalar;
    }
    return tmp;
}
 */

template <class T>
RijetkaMatrica<T> RijetkaMatrica<T>::operator*(const RijetkaMatrica<T> &m1) const {
    if (this->m != m1.n) {
        throw overflow_error("Broj kolona matrice A i broj vrsta matrice B se razlikuju");
    }

    RijetkaMatrica<T> rez(this->n, m1.m);

    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < m1.m; j++) {
            T sum = 0;
            for (int k = 0; k < this->brElem; k++) {
                for (int l = 0; l < m1.brElem; l++) {
                    if (this->rows[k] == i && this->cols[k] == j && m1.rows[l] == j && m1.cols[l] == i) {
                        sum += this->data[k] * m1.data[l];
                        break;
                    }
                }
            }
            if (sum != 0) {
                rez.data[rez.brElem] = sum;
                rez.rows[rez.brElem] = i;
                rez.cols[rez.brElem] = j;
                rez.brElem++;
            }
        }
    }
    return rez;
}

template <class T>
RijetkaMatrica<T> &RijetkaMatrica<T>::operator+=(const RijetkaMatrica<T> &m1) {

    if(this->n != m1.n && this->m != m1.m) {
        throw overflow_error("Prekoracenje");
    }

    for(int i=0;i<brElem;i++){
        for(int j=0;j<m1.brElem;j++){
            if(this->cols[i]==m1.cols[j] && this->rows[i]== m1.rows[j]){
                this->data[i]+=m1.data[j];
                break;
            }
        }
    }


    for(int i=0;i<m1.brElem;i++){
        bool index= false;
        for(int j=0;j<brElem;j++){
            if(this->cols[j]==m1.cols[i] && this->rows[j]== m1.rows[i]){
                index= true;
                break;
            }
        }
        if(!index){
            this->data[brElem]=m1.data[i];
            this->rows[brElem]=m1.rows[i];
            this->cols[brElem]=m1.cols[i];
            brElem++;

        }
    }
    return *this;
}



#endif