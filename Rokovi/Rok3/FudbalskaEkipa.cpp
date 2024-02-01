//
// Created by User on 2/1/2024.
//

#include "FudbalskaEkipa.h"
#include "Ekipa.h"

bool FudbalskaEkipa::operator==(FudbalskaEkipa &e) const {
    if(this->brojIgraca != e.brojIgraca){
        return false;
    }
    sort(this->brojevi_igraca,this->brojevi_igraca+brojIgraca);
    sort(e.brojevi_igraca,e.brojevi_igraca+brojIgraca);
    for(int i=0;i<brojIgraca;i++){
        if(e.brojevi_igraca[i] != this->brojevi_igraca[i]){
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const FudbalskaEkipa& fe) {
    os<<static_cast<const Ekipa&>(fe);
    os<<"Brojevi igraca: ";

    for(int i=0;i<fe.brojIgraca;i++){
        os<<fe.brojevi_igraca[i]<<" ";
    }
    return os;
}