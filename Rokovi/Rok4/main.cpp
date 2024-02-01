#include <iostream>
using namespace std;
#include "Valuta.h"
#include "KolicinaNovca.h"

int main() {
    Valuta k3("Dolar",3);
    //Valuta k3("Dolar",3);
    KolicinaNovca k1("Dolar",3,520);
    KolicinaNovca k2("Euro",4,623);

    //k2.konvertuj(k3);
    //cout << k2.getNaziv() << " " << k2.getIznos() << " " << k2.getKolicina();

    //cout<<endl<<k1+k2;
    k2-=k1;
    cout << k2.getNaziv() << " " << k2.getIznos() << " " << k2.getKolicina()<<endl;
    if(k1==k1){
        cout<<"da"<<endl;
    }else{
        cout<<"ne"<<endl;
    }

    double zlato=static_cast<double>(k2);
    cout<<(zlato)<<endl;

    return 0;
}
