//
// Created by User on 2/2/2024.
//

#include "NovcaniIznos.h"

NovcaniIznos::NovcaniIznos() {
    this->iznos=0;
    this->centi=0;
}

NovcaniIznos::NovcaniIznos(int iznos, int centi) {
    if(iznos<0 || centi<0 || centi>100){
        return;
    }
    this->iznos=iznos;
    this->centi=centi;
}

int NovcaniIznos::getIznos() const {
    return this->iznos;
}

int NovcaniIznos::getCenti() const {
    return this->centi;
}

void NovcaniIznos::setIznos(int iznos) {
    if(iznos<0){
        return;
    }
    this->iznos=iznos;
}

void NovcaniIznos::setCenti(int centi) {
    if(centi<0 || centi>10){
        return;
    }
    this->centi=centi;
}
