//
// Created by User on 1/29/2024.
//
#include <iostream>
#include "Interval.h"

using namespace std;

int Interval::getTrajanje() const {
    return trajanje;
}

void Interval::setTrajanje(int trajanje) {
    this->trajanje=trajanje;
}

Interval& Interval::operator+=(int minInt) {
    min += minInt;
    if (min > 59) {
        min = min % 60;
        sat++;
        if (sat > 23) {
            throw overflow_error("Prekoracenje vremena");
        }
    }
    return *this;
}

Vrijeme Interval::kraj() {
    int traj = getTrajanje();

    if (min >= 60) {
        int tren = min / 60;
        min = min % 60;
        sat += tren;
    }

    min += traj;

    if (min > 59) {
        int tren = min / 60;
        min = min % 60;
        sat += tren;
    }

    return Vrijeme(sat, min);
}

bool Interval::operator>(const Interval& desni) const {
    // Provera da li levi interval sadrži desni
    return (getSat() < desni.getSat()) ||
           (getSat() == desni.getSat() && getMin() <= desni.getMin());
}