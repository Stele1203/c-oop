#include <iostream>
using namespace std;
#include "Racun.h"
#include "NovcaniIznos.h"

int main() {
    Racun r1(1,'+',1,100,100);
    Racun r2(2,'+',1,200,0);
    r1.ispisi();
    //r1.dodaj(r2);
    r1.ispisi();

    cout<<endl<<uporedi(r1,r2);
    return 0;
}
