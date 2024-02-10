//
// Created by User on 2/10/2024.
//

#ifndef ROK5_VELIKIBROJ_H
#define ROK5_VELIKIBROJ_H
#include "NeoznaceniVelikiBroj.h"

class VelikiBroj: public NeoznaceniVelikiBroj {
public:
    char znak;
    VelikiBroj(char znak, int x): NeoznaceniVelikiBroj(x),znak(znak){};

    VelikiBroj operator+(VelikiBroj broj) const;

    VelikiBroj(int x);

    friend ostream& operator<<(ostream& os, const VelikiBroj& vb);

    VelikiBroj operator*(VelikiBroj broj) const;
};


#endif //ROK5_VELIKIBROJ_H
