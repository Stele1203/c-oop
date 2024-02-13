//
// Created by User on 2/13/2024.
//

#ifndef ROK3_RIJETKAMATRICA_CPP
#define ROK3_RIJETKAMATRICA_CPP
#include "RijetkaMatrica.h"

template<class T>
RijetkaMatrica<T>::RijetkaMatrica(int n, int m) {
    this->n=n;
    this->m=m;
    this->brElem=0;
}

template<class T>
void RijetkaMatrica<T>::dodaj(int r, int c, T elem) {
    if(brElem==10 || r<0 || r>=n || c<0 || c>=m){
        throw invalid_argument("Greska");
    }
    this->data[brElem]=elem;
    this->row[brElem]=r;
    this->col[brElem]=c;
    brElem++;
}


template<class T>
T RijetkaMatrica<T>::operator()(int j, int i) {
    if(j<0 || j>=m || i<0 || i>=n){
        throw overflow_error("Greska ne validna dimenzija");
    }

    for(int k=0;k<brElem;k++){
        if(col[k]==j && row[k]==i){
            return data[k];
        }
    }
    throw overflow_error("Ne postoji taj element");
}

template<class T>
int RijetkaMatrica<T>::sumaVrste(int row) {
    int sum=0;
    for(int i=0;i<brElem;i++){
        if(this->row[i]==row){
            sum+=data[i];
        }
    }
    return sum;
}
/*
template<class T>
RijetkaMatrica<T>& operator+(const RijetkaMatrica<T> matrica1, const RijetkaMatrica<T> matrica2) {
    if(matrica1.m != matrica2.m && matrica1.n != matrica2.n){
        throw invalid_argument("Nevalidne matrice");
    }
    RijetkaMatrica<T> nova(matrica2.n,matrica2.m);
    int brojac=0;
    for(int i=0;i<matrica1.brElem;i++){
        bool mrk= false;
        for(int j=0;j<matrica2.brElem;i++){
            if(matrica1.row[i]== matrica2.row[j] && matrica1.col[i]== matrica2.col[j]){
                nova.data[brojac]=matrica1.data[i]+matrica2.data[j];
                nova.col[brojac]=matrica2.col[j];
                nova.row[brojac]=matrica2.row[j];
                brojac++;
                mrk= true;
            }
        }
        if(mrk== false){
            nova.data[brojac]=matrica1.data[i];
            nova.col[brojac]=matrica1.col[i];
            nova.row[brojac]=matrica1.row[i];
            brojac++;
        }
    }

    for(int i=0;i<matrica2.brElem;i++){
        bool mrk= false;
        for(int j=0;j<matrica1.brElem;j++){
            if(matrica1.row[j]== matrica2.row[i] && matrica1.col[j]== matrica2.col[i]){
                mrk= true;
            }
        }
        if(!mrk){
            nova.data[brojac]=matrica2.data[i];
            nova.col[brojac]=matrica2.col[i];
            nova.row[brojac]=matrica2.row[i];
            brojac++;
        }
    }
    return nova;
}
*/




#endif //ROK3_RIJETKAMATRICA_H
