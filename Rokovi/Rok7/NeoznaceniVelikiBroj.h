//
// Created by User on 2/9/2024.
//

#ifndef ROK5_NEOZNACENIVELIKIBROJ_H
#define ROK5_NEOZNACENIVELIKIBROJ_H
#include "iostream"
using namespace std;


class NeoznaceniVelikiBroj {
public:
    int* cifre;
    int brCifara;
public:
    static int convertToNumber(NeoznaceniVelikiBroj a);
    NeoznaceniVelikiBroj(int x);
    NeoznaceniVelikiBroj(int* cifre, int brCifara);

    friend ostream& operator<<(ostream& os,const NeoznaceniVelikiBroj& br);

    NeoznaceniVelikiBroj operator+(NeoznaceniVelikiBroj br) const;

    NeoznaceniVelikiBroj operator-(NeoznaceniVelikiBroj br) const;

    NeoznaceniVelikiBroj operator*(NeoznaceniVelikiBroj br) const;

    bool operator<(NeoznaceniVelikiBroj br) const;
};


#endif //ROK5_NEOZNACENIVELIKIBROJ_H
