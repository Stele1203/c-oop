//
// Created by User on 2/1/2024.
//

#ifndef EKIPA_EKIPA_H
#define EKIPA_EKIPA_H
#include "string.h"
#include <iostream>

using namespace std;

class Ekipa {
public:
    char* naziv;
    int brojIgraca;
    double budzet;
public:
    Ekipa(char* naziv, int brojIgraca=0, double budzet=0):brojIgraca(brojIgraca),budzet(budzet){
        this->naziv= new char[strlen(naziv)+1];
        strcpy(this->naziv,naziv);
        if (najveci.budzet > this->budzet) {
            najveci=najveci;
        }
        najveci = *this;
    }

    void ispisiEkipu();

    static Ekipa najveci;

    //seteri
    void setNaziv(char* naziv);
    void setIznos(double iznos);

    //geteri
    char* getNaziv() const;
    double getIznos() const;

    static Ekipa* najveciBudzet();

    //d
    Ekipa& operator++();

    Ekipa operator++(int );

    friend ostream& operator<<(ostream& os, const Ekipa& e);
};


#endif //EKIPA_EKIPA_H
