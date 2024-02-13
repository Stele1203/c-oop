//
// Created by User on 2/13/2024.
//

#ifndef ROK3_RIJETKAMATRICA_H
#define ROK3_RIJETKAMATRICA_H
#include <iostream>
using namespace std;
template<class T>
class RijetkaMatrica {
    T data[10];
    int row[10];
    int col[10];
    int n,m,brElem;
public:
    RijetkaMatrica(int n,int m);
    void dodaj(int r,int c,T elem);
    T operator()(int j,int i);
    //friend ostream& operator<<(ostream& os, const RijetkaMatrica<T>& m1);
    void ispisi(RijetkaMatrica<T> m1);

    int sumaVrste(int row);

    friend RijetkaMatrica<T> operator+(const RijetkaMatrica<T>& matrica1, const RijetkaMatrica<T>& matrica2) {
        if(matrica1.m != matrica2.m || matrica1.n != matrica2.n){
            throw invalid_argument("Nevalidne matrice");
        }

        RijetkaMatrica<T> nova(matrica2.n, matrica2.m);
        int brojac = 0;

        for(int i = 0; i < matrica1.brElem; i++) {
            bool mrk = false;
            for(int j = 0; j < matrica2.brElem; j++) {
                if(matrica1.row[i] == matrica2.row[j] && matrica1.col[i] == matrica2.col[j]) {
                    nova.data[brojac] = matrica1.data[i] + matrica2.data[j];
                    nova.col[brojac] = matrica2.col[j];
                    nova.row[brojac] = matrica2.row[j];
                    nova.brElem++;
                    brojac++;
                    mrk = true;
                    break;
                }
            }
            if(!mrk) {
                nova.data[brojac] = matrica1.data[i];
                nova.col[brojac] = matrica1.col[i];
                nova.row[brojac] = matrica1.row[i];
                nova.brElem++;
                brojac++;
            }
        }

        for(int i = 0; i < matrica2.brElem; i++) {
            bool mrk = false;
            for(int j = 0; j < matrica1.brElem; j++) {
                if(matrica1.row[j] == matrica2.row[i] && matrica1.col[j] == matrica2.col[i]) {
                    mrk = true;
                    break;
                }
            }
            if(!mrk) {
                nova.data[brojac] = matrica2.data[i];
                nova.col[brojac] = matrica2.col[i];
                nova.row[brojac] = matrica2.row[i];
                brojac++;
                nova.brElem++;
            }
        }

        //nova.brElem = brojac;
        return nova;
    }

    friend ostream& operator<<(ostream& os, const RijetkaMatrica<T>& m1){
        for(int i=0;i<m1.brElem;i++){
            cout<<m1.data[i]<<" "<<m1.col[i]<<" "<<m1.row[i]<<endl;
        }
    }
};

template<class T>
void RijetkaMatrica<T>::ispisi(RijetkaMatrica<T> m1) {
    for(int i=0;i<m1.brElem;i++){
        cout<<m1.data[i]<<" "<<m1.col[i]<<" "<<m1.row[i]<<endl;
    }
}

//template<class T>
//template<class T>


#include "RijetkaMatrica.cpp"
#endif //ROK3_RIJETKAMATRICA_H
