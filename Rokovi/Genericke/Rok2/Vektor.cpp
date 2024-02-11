//
// Created by User on 2/10/2024.
//

#include "Vektor.h"

template <class T>
Vektor<T>::Vektor() {
    for(int i=0;i<10;i++){
        this->zauzet[i]= false;
    }
}

template <class T>
Vektor<T> &Vektor<T>::operator+=(T t) {
    for(int i=0;i<10;i++){
        if(this->zauzet[i]== false){
            this->data[i]=t;
            return *this;
        }
    }
    throw 1;
}

template <class T>
Vektor<T> &Vektor<T>::operator-=(T t) {
    for(int i=0;i<10;i++){
        if(this->data[i]==t){
            this->data[i]=0;
            this->zauzet[i]= false;
            return *this;
        }
    }
}

template <class T>
T Vektor<T>::operator[](int pos) {
    if(this->zauzet[pos]== false)
        throw 1;
    return this->data[pos];
}

template <class T>
bool Vektor<T>::operator==(const Vektor<T> vekor) {
    int c=0;
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(this->data[i]==vekor.data[j]){
                c++;
            }
        }
    }

    if(c!=10)
        return false;
    c=0;
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(this->data[j]==vekor.data[i]){
                c++;
            }
        }
    }
    if(c!=10)
        return false;
    return true;
}