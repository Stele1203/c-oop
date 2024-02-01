#include <iostream>
using namespace std;
#include "Ekipa.h"
#include "FudbalskaEkipa.h"

int main() {
    Ekipa e1("Real Madriddd");
    Ekipa e2("Barcelona",1,2);
    //e1.ispisiEkipu();
    cout<<e1;
    cout<<e2;
    ++e2;
    Ekipa e3= e2++;
    cout<<e3;
    //e3.ispisiEkipu();
    //e2.ispisiEkipu();
    int brojevi[] = {1,2};
    int brojevi2[] = {1,2,3};
    FudbalskaEkipa e4("Barcelona",2,222,brojevi);
    FudbalskaEkipa e5("Test",3,222,brojevi2);
    if(e4==e5){
        cout<<"da"<<endl;
    } else{
        cout<<"ne"<<endl;
    }

    e1.najveciBudzet()->ispisiEkipu();
    cout<<e4;
    return 0;
}
