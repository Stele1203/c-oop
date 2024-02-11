//
// Created by User on 2/11/2024.
//

#ifndef VEKTOR2_VEKTOR_H
#define VEKTOR2_VEKTOR_H

template <class T>
class Vektor {
private:
    T data[10];
    bool zauzet[10];
public:
    Vektor();
    void dodaj(T elem);
    void Ukloni(int i);

    void rotirajZaK(int k);

    Vektor<T> defragmentKopija();
};

#include "Vektor.cpp"
#endif //VEKTOR2_VEKTOR_H
