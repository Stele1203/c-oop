//
// Created by User on 2/10/2024.
//

#ifndef VEKTOR_GENERICKA_VEKTOR_H
#define VEKTOR_GENERICKA_VEKTOR_H

template <class T>
class Vektor {
private:
    T data[10];
    bool zauzet[10];

public:
    Vektor();

    Vektor<T>& operator+=(T t);
    Vektor<T>& operator-=(T t);

    T operator[](int pos);

    bool operator==(const Vektor<T> vekor);
};


#endif //VEKTOR_GENERICKA_VEKTOR_H
