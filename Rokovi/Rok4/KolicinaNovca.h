//
// Created by User on 2/1/2024.
//

#ifndef VALUTA_KOLICINANOVCA_H
#define VALUTA_KOLICINANOVCA_H
#include "Valuta.h"


class KolicinaNovca: public Valuta{
private:
    double kolicina;
public:
    KolicinaNovca(char* naziv, double iznos, double kolicina): Valuta(naziv,iznos),kolicina(kolicina){}

    void konvertuj(Valuta v);

    double operator+(KolicinaNovca k1) const;

    double getKolicina() const;

    KolicinaNovca& operator-=(const KolicinaNovca& kn1);

    bool operator==(const KolicinaNovca& kn1);

    operator double() const;
};


#endif //VALUTA_KOLICINANOVCA_H
