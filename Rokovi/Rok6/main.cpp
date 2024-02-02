#include <iostream>
using namespace std;
#include "String.h"

int main() {
    char nizKar[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char niz2[11] = {'k', 's', 'f', 'm', 'e', 'f', 'g', 'h', 'i', 'j'};

    String s1(nizKar);
    String s2(niz2);
    //cout<<s1.duzina()<<endl;
    s1.ispisi();
    s2.ispisi();
    //String s3=s1+s2;
    //s3.ispisi();
    s1+='k';
    cout<<s1;
    return 0;
}

