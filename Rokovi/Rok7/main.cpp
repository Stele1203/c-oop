#include <iostream>
#include "NeoznaceniVelikiBroj.h"
#include "VelikiBroj.h"

using namespace std;

int main() {
    NeoznaceniVelikiBroj br1(211);
    NeoznaceniVelikiBroj br2(1);
    NeoznaceniVelikiBroj b3=br2-br1;
    //cout<<b3;
    //cout<<b3.convertToNumber(b3);
    VelikiBroj vb1(100);
    VelikiBroj vb2(100);
    VelikiBroj vb3=vb2*vb1;
    cout<<vb3;
    return 0;
}
