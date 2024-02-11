//
// Created by User on 2/11/2024.
//

#ifndef RIJETKAMATRICA_RIJETKAMATRICA_H
#define RIJETKAMATRICA_RIJETKAMATRICA_H

template <class T>
class RijetkaMatrica {
private:
    T data[10];
    int rows[10];
    int cols[10];
    int n;
    int m;
    int brElem;

public:
    RijetkaMatrica(int n,int m):brElem(0),m(m),n(n){};

    void set(T elem, int i, int j);

    T operator()(int i,int j) const;

    ///ako je u pitanju mnozenje sa skalarom
    //RijetkaMatrica<T> operator*(const T skalar) const;

    RijetkaMatrica<T> operator*(const RijetkaMatrica& m1) const;

    RijetkaMatrica<T>& operator+=(const RijetkaMatrica& m1);
};

#include "RijetkaMatrica.cpp"
#endif //RIJETKAMATRICA_RIJETKAMATRICA_H
