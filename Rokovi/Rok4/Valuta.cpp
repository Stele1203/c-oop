//
// Created by User on 2/1/2024.
//

#include "Valuta.h"
#include "iostream"
#include "string.h"
using namespace std;

Valuta::Valuta(char *naziv, double iznos) {
    if(iznos != 0){
        this->iznos=iznos;
    }else{
        return;
    }

    this->naziv= new char[strlen(naziv)+1];
    strcpy(this->naziv,naziv);

}

void Valuta::setIznos(double iznos) {
    if(iznos != 0){
        this->iznos=iznos;
    }else{
        exit(1);
    }
}

void Valuta::setNaziv(char* naziv) {
    this->naziv= new char[strlen(naziv)+1];
    strcpy(this->naziv,naziv);
}

double Valuta::getIznos() const {
    return iznos;
}

char *Valuta::getNaziv() const {
    return naziv;
}