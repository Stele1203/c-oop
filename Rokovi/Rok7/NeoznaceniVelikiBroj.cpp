//
// Created by User on 2/9/2024.
//

#include "NeoznaceniVelikiBroj.h"
#include "math.h"

NeoznaceniVelikiBroj::NeoznaceniVelikiBroj(int x) {
    int tmp=x;
    brCifara=0;
    if(tmp==0){
        brCifara++;
    }else {
        while (tmp > 0) {
            brCifara++;
            tmp /= 10;
        }
    }
    cifre=new int[brCifara];

    if(x==0){
        cifre[0]=0;
    }else {
        for (int i = 0; i < brCifara; i++) {
            cifre[i] = x % 10;
            x /= 10;
        }
    }
}

NeoznaceniVelikiBroj::NeoznaceniVelikiBroj(int *cifre, int brCifara) {
    this->cifre=new int[brCifara];

    for(int i=0;i<brCifara;i++){
        this->cifre[i]=cifre[i];
    }
    this->brCifara=brCifara;
}

ostream& operator<<(ostream& os,const NeoznaceniVelikiBroj& br){
    for(int i=br.brCifara-1;i>=0;i--){
        cout<<br.cifre[i]<<" ";
    }
    cout<<endl;
}

NeoznaceniVelikiBroj NeoznaceniVelikiBroj::operator+(NeoznaceniVelikiBroj br) const {
    int maxEl=max(br.brCifara,this->brCifara);
    int minEl= min(br.brCifara,this->brCifara);
    int noviBrojElemenata=maxEl;
    int* noviBroj= new int[maxEl];
    int pamti=0;
    for(int i=0;i<minEl;i++){
        int broj=this->cifre[i]+br.cifre[i]+pamti;
        if(broj<10){
            noviBroj[i]=broj;
            pamti=0;
        }else{
            noviBroj[i]=broj%10;
            pamti=1;
        }

    }
    if(pamti>0 && maxEl==minEl){
        int* tmp= new int[maxEl+1];
        for(int i=0;i<maxEl;i++){
            tmp[i]=noviBroj[i];
        }
        delete[] noviBroj;
        noviBroj= new int[maxEl+1];
        for(int i=0;i<maxEl;i++){
            noviBroj[i]=tmp[i];
        }
        noviBroj[maxEl+1]=pamti;
        noviBrojElemenata++;
        pamti=0;
    }
    int raz=maxEl-minEl;
    int i=0;
    while (raz>0){
        if(br.brCifara>this->brCifara){
            int broj=br.cifre[minEl]+pamti;
            if(broj<10){
                noviBroj[minEl]=broj;
                pamti=0;
            }else{
                noviBroj[minEl]=broj%10;
                pamti=1;
            }
        }else{
            int broj=this->cifre[minEl]+pamti;
            if(broj<10){
                noviBroj[minEl]=broj;
                pamti=0;
            }else{
                noviBroj[minEl]=broj%10;
                pamti=1;
            }
        }
        minEl++;
        raz--;
    }

    if(pamti>0 && maxEl==minEl){
        int* tmp= new int[maxEl+1];
        for(int i=0;i<maxEl;i++){
            tmp[i]=noviBroj[i];

        }
        delete[] noviBroj;
        noviBroj= new int[maxEl+1];
        for(int i=0;i<maxEl;i++){
            noviBroj[i]=tmp[i];
        }
        noviBroj[maxEl]=pamti;
        noviBrojElemenata++;
        pamti=0;
    }

    NeoznaceniVelikiBroj brojNovi(noviBroj,noviBrojElemenata);
    return brojNovi;
}


int NeoznaceniVelikiBroj::convertToNumber(NeoznaceniVelikiBroj a) {
    int broj=0;
    for(int i=a.brCifara-1;i>=0;i--){
        broj*=10;
        broj=(broj+a.cifre[i]);
    }
    return broj;
}

NeoznaceniVelikiBroj NeoznaceniVelikiBroj::operator-(NeoznaceniVelikiBroj br) const {
    int prvi=convertToNumber(*this);
    int drugi= convertToNumber(br);

    NeoznaceniVelikiBroj brojic(abs(prvi-drugi));
    return brojic;
}

NeoznaceniVelikiBroj NeoznaceniVelikiBroj::operator*(NeoznaceniVelikiBroj br) const {
    int prvi=convertToNumber(*this);
    int drugi= convertToNumber(br);
    NeoznaceniVelikiBroj brojic(prvi*drugi);
    return brojic;
}

bool NeoznaceniVelikiBroj::operator<(NeoznaceniVelikiBroj br) const {
    int prvi=convertToNumber(*this);
    int drugi= convertToNumber(br);
    return prvi<drugi;
}

