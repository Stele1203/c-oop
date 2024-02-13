#include <iostream>
#include "String.h"
#include "RijetkaMatrica.h"
using namespace std;
/**/
int main() {
    /*String s("Stefan");
    cout<<s;
    String s2(s);
    cout<<s2;
    String s3=s+s2;
    cout<<s3;

    s3+='m';
    cout<<s3;

    if(s=s3){
        cout<<endl<<"Da"<<endl;
    }else{
        cout<<"ne";
    }*/

    RijetkaMatrica<int> test(4,4);
    RijetkaMatrica<int> test2(4,4);
    RijetkaMatrica<int> test3(0,0);
    test.dodaj(0,0,12);
    test.dodaj(0,1,12);
    test.dodaj(0,2,12);
    test.dodaj(0,3,12);

    test2.dodaj(0,0,12);
    test2.dodaj(0,1,12);
    test2.dodaj(0,2,12);
    test2.dodaj(0,3,12);

    test3=test+test2;

    //test3=test+test2;
    cout<<test3;
    //test3.ispisi(test3);


    return 0;
}
