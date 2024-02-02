//
// Created by User on 2/2/2024.
//
#include <iostream>
#include "Racun.h"
using namespace std;
#include "math.h"

int uporedi(const Racun& r1, const Racun& r3){
    Racun r2=r3;
    if(r1.sifraValute != r2.sifraValute){
        r2.konvertuj();
    }
    if(r1.balans=='+' && r2.balans=='-'){
        return 1;
    }else if(r1.balans=='-' && r2.balans=='+'){
        return 0;
    }else if(r1.balans=='-'){
        if(r1.iznos<r2.iznos){
            return 1;
        }else if(r1.iznos>r2.iznos){
            return 0;
        }else{
            if(r1.centi<r2.centi){
                return 1;
            }else if(r2.centi<r1.centi){
                return 0;
            }else{
                return 1;
            }
        }
    }else if(r1.balans=='+'){
        if(r1.iznos<r2.iznos){
            return 0;
        }else if(r1.iznos>r2.iznos){
            return 1;
        }else{
            if(r1.centi<r2.centi){
                return 0;
            }else if(r2.centi<r1.centi){
                return 1;
            }else{
                return 1;
            }
        }
    }
}

Racun::Racun(int id, char balans, int sifraValute, int iznos, int centi):NovcaniIznos(iznos,centi) {
    if(balans != '+' && balans !='-'){
        return;
    }

    if(sifraValute != 1 && sifraValute !=2){
        return;
    }
    this->id=id;
    this->balans=balans;
    this->sifraValute=sifraValute;
}

void Racun::konvertuj() {
    if(this->sifraValute==1){
        this->centi=this->centi*eurPremaUsd;
        this->iznos*=eurPremaUsd;
        while(centi>100){
            centi=centi%100;
            iznos+=1;
        }
        this->sifraValute=2;
        return;
    }

    if(this->sifraValute==2){
        this->centi/=eurPremaUsd;
        this->iznos/=eurPremaUsd;
        while(centi>100){
            centi=centi%100;
            iznos+=1;
        }
        this->sifraValute=1;
        return;
    }
}

void Racun::ispisi() {
    cout<<this->id<<" Sifra valute: "<<this->sifraValute<<" Balans "<< this->balans<<" Stanje "<< this->iznos<<":"<<this->centi<<endl;
}

void Racun::dodaj(const Racun &rac) {
    Racun tmp= rac;
    if(tmp.sifraValute != this->sifraValute){
        tmp.konvertuj();
    }
    if(tmp.balans==this->balans){
        this->centi+=tmp.centi;
        this->iznos+=tmp.iznos;
        while(this->centi>100){
            this->centi= this->centi%100;
            this->iznos+=1;
        }
        return;
    }

        if(this->iznos>= tmp.iznos){
            this->centi-=tmp.centi;
            this->iznos-=tmp.iznos;
            if(this->centi<0){
                this->centi=100- this->centi;
                this->iznos-=1;
            }
        }else{
            this->centi-=tmp.centi;
            this->iznos-=tmp.iznos;
            if(this->centi<0){
                this->centi=100- this->centi;
                this->iznos-=1;
            }
            if(this->balans=='+'){
                this->balans='-';
            }else{
                this->balans='+';
            }
            this->iznos= abs(this->iznos);
        }


}