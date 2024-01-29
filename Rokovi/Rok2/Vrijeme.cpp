//
// Created by User on 1/28/2024.
//
#include "iostream"
#include "Vrijeme.h"
using namespace std;

bool Vrijeme::checkMin(int min) {
    if(min<0 || min>59){
        return false;
    }
    return true;
}

bool Vrijeme::checkSat(int sat) {
    if(sat<0 || sat>23){
        return false;
    }
    return true;
}

bool Vrijeme::validVrijeme(int sat, int min) {
    if(checkSat(sat) && checkMin(min)){
        return true;
    }
    return false;
}

Vrijeme::Vrijeme(int sat, int min) {
    if(validVrijeme(sat,min)){
        this->min=min;
        this->sat=sat;
    }else{
        cout<<"Vrijeme nije validno";
        return;
    }
}


int Vrijeme::getSat() const {
    return sat;
}

int Vrijeme::getMin() const {
    return min;
}

void Vrijeme::setSat(int sat) {
    this->sat=sat;
}

void Vrijeme::setMin(int min) {
    this->min=min;
}

Vrijeme& Vrijeme::operator++() {
    min++;
    if(!checkMin(min)){
        min=0;
        sat++;
        if(!checkSat(sat)){
            sat=0;
        }
    }
    return *this;
}

void Vrijeme::ispisiVrijeme() const {
    cout<< this->sat<<" "<< this->min<<endl;
}