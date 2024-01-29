#include <iostream>
using namespace std;
#include "Vrijeme.h"
#include "Interval.h"

int main() {
    Vrijeme v1(22,3);
    v1.ispisiVrijeme();
    ++v1;
    v1.ispisiVrijeme();
    Interval int1(10,20,20);
    Interval int2(10, 10, 10);

    cout << (int1 > int2);

    return 0;
}
