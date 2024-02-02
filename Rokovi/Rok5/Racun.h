//
// Created by User on 2/2/2024.
//

#ifndef NOVCANIIZNOS_RACUN_H
#define NOVCANIIZNOS_RACUN_H
#include "NovcaniIznos.h"

static float eurPremaUsd=1.2;


class Racun: public NovcaniIznos{
    int id;
    char balans;
    int sifraValute;
public:
    Racun():id(-1),balans('+'),sifraValute(1),NovcaniIznos(){};

    Racun(int id, char balans, int sifraValute,int iznos, int centi);

    void konvertuj();

    void ispisi();

    void dodaj(const Racun& rac);

    friend int uporedi(const Racun& r1, const Racun& r2);
};


#endif //NOVCANIIZNOS_RACUN_H
