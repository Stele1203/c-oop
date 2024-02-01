//
// Created by User on 2/1/2024.
//

#ifndef EKIPA_FUDBALSKAEKIPA_H
#define EKIPA_FUDBALSKAEKIPA_H
#include "iostream"
using namespace std;
#include <algorithm>

#include "Ekipa.h"

class FudbalskaEkipa: public Ekipa {

private:
    int* brojevi_igraca;
public:
    FudbalskaEkipa(char* naziv, int brojIgraca, double budzet, int* brojevi_igraca): Ekipa(naziv,brojIgraca,budzet){
        this->brojevi_igraca=new int[brojIgraca];
        for(int i=0;i<brojIgraca;i++){
            this->brojevi_igraca[i]=brojevi_igraca[i];
        }
    }

    bool operator==(FudbalskaEkipa& e) const;

    friend ostream& operator<<(ostream& os, const FudbalskaEkipa& fe);

};


#endif //EKIPA_FUDBALSKAEKIPA_H
