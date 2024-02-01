//
// Created by User on 2/1/2024.
//

#include "KolicinaNovca.h"
#include "math.h"
#include "iostream"
void KolicinaNovca::konvertuj(Valuta v) {
    double kolicinaZlata=this->kolicina/ this->getIznos();
    this->setNaziv(v.getNaziv());
    this->setIznos(v.getIznos());
    kolicina=this->getIznos()*kolicinaZlata;
}


double KolicinaNovca::operator+(KolicinaNovca k1) const {
    k1.konvertuj(static_cast<const Valuta>(k1));
    k1.kolicina+= this->kolicina;
    return k1.kolicina;
}

double KolicinaNovca::getKolicina() const {
    return this->kolicina;
}

KolicinaNovca &KolicinaNovca::operator-=(const KolicinaNovca &kn1) {
    KolicinaNovca tmp= kn1;

    tmp.konvertuj(static_cast<const Valuta&>(*this));
    this->kolicina-=tmp.kolicina;
    this->kolicina=abs(this->kolicina);
    return *this;
}

bool KolicinaNovca::operator==(const KolicinaNovca &kn1) {
    KolicinaNovca tmp= kn1;
    tmp.konvertuj(static_cast<const Valuta&>(*this));
    if(tmp.kolicina==this->kolicina){
        return true;
    }else{
        return false;
    }
}

KolicinaNovca::operator double() const {
    return kolicina/this->getIznos();
}