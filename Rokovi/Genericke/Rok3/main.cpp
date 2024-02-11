#include <iostream>
#include "RijetkaMatrica.h"
int main() {

    RijetkaMatrica<int> test(2,2);

    test.set(2,0,0);
    test.set(2,0,1);
    test.set(2,1,0);

    RijetkaMatrica<int> test2(2,2);

    test2.set(2,0,0);
    test2.set(2,0,1);
    test2.set(2,1,0);
    test2.set(2,1,1);

    RijetkaMatrica<int> test3=test*test2;

    test+=test2;

    cout<<test.operator()(1,1);
    return 0;
}
