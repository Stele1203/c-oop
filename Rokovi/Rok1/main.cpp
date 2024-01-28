#include <iostream>
#include "Datum.h"
#include "DatumStack.h"

using namespace std;
int main() {
    Datum d1;
    Datum d2(1,2,2005);
    Datum d3(3,2,2002);
    Datum d4(2,4,2009);
    Datum d5(12,3,1999);

    DatumStack stek;
    stek.push(d1);
    stek.push(d2);
    stek.push(d3);
    stek.push(d4);
    stek.push(d5);

    stek.ispisiStack();
    cout<<endl;

    stek.sortiraj();
    stek.ispisiStack();


    return 0;
}
