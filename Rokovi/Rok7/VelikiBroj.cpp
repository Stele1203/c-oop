//
// Created by User on 2/10/2024.
//

#include "VelikiBroj.h"

VelikiBroj VelikiBroj::operator+(VelikiBroj broj) const {
    char noviZnak;
    NeoznaceniVelikiBroj broj1= static_cast<NeoznaceniVelikiBroj>(*this);
    NeoznaceniVelikiBroj broj2= static_cast<NeoznaceniVelikiBroj>(broj);
    NeoznaceniVelikiBroj broj3(0);

    if(this->znak=='-' && broj.znak=='+'){
        if(convertToNumber(broj1)> convertToNumber(broj2)){
            broj3=broj1-broj2;
            VelikiBroj tmp('-', convertToNumber(broj3));
            return tmp;
        }else{
            broj3=broj2-broj1;
            VelikiBroj tmp('+', convertToNumber(broj3));
            return tmp;
        }
    }else if(this->znak=='+' && broj.znak=='-'){
        if(convertToNumber(broj1)> convertToNumber(broj2)){
            broj3=broj1-broj2;
            VelikiBroj tmp('+', convertToNumber(broj3));
            return tmp;
        }else{
            broj3=broj2-broj1;
            VelikiBroj tmp('-', convertToNumber(broj3));
            return tmp;
        }
    }else{
        broj3=broj1+broj2;
        VelikiBroj tmp(this->znak, convertToNumber(broj3));
        return tmp;
    }
}

VelikiBroj::VelikiBroj(int b): NeoznaceniVelikiBroj(abs(b)) {
    if(b<0){
        this->znak='-';
        b= abs(b);
    }else{
        this->znak='+';
    }
}


ostream& operator<<(ostream& os, const VelikiBroj& vb){
    NeoznaceniVelikiBroj tmp= static_cast<const NeoznaceniVelikiBroj>(vb);
    os<<vb.znak<<" ";
    os<<tmp;

    return os;

}

VelikiBroj VelikiBroj::operator*(VelikiBroj broj) const {
    NeoznaceniVelikiBroj broj1= static_cast<NeoznaceniVelikiBroj>(*this);
    NeoznaceniVelikiBroj broj2= static_cast<NeoznaceniVelikiBroj>(broj);
    NeoznaceniVelikiBroj broj3(0);
    char noviZnak='+';
    broj3=broj1*broj2;
    if(this->znak=='-' && broj.znak=='+'){
        noviZnak='-';
    }else if(this->znak=='+' && broj.znak=='-'){
        noviZnak='-';
    }

    VelikiBroj tmp(noviZnak, convertToNumber(broj3));

    return tmp;
}