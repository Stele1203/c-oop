//
// Created by User on 2/1/2024.
//
#include <iostream>
#include "Ekipa.h"
#include "string.h"
using namespace std;

Ekipa Ekipa::najveci("Default", 0, 0);


void Ekipa::ispisiEkipu() {
    cout<<naziv<<" "<<budzet<<" "<<brojIgraca<<endl;
}

void Ekipa::setNaziv(char* naziv) {
    this->naziv=new char[strlen(naziv)+1];
    strcpy(this->naziv,naziv);
}

void Ekipa::setIznos(double iznos) {
    this->budzet=iznos;
}

char* Ekipa::getNaziv() const {
    return naziv;
}

double Ekipa::getIznos() const {
    return budzet;
}

Ekipa* Ekipa::najveciBudzet() {
    return &najveci;
}

Ekipa &Ekipa::operator++() {
    ++this->brojIgraca;
    return *this;
}

Ekipa Ekipa::operator++(int) {
    Ekipa stari = *this;
    ++this->brojIgraca;
    return stari;
}

ostream& operator<<(ostream& os, const Ekipa& e){
    os<<e.naziv<<" "<<e.brojIgraca<<" "<<e.budzet<<endl;
    return os;
}



