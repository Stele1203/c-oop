//
// Created by User on 1/28/2024.
//

#ifndef KOL1_DATUM_H
#define KOL1_DATUM_H


class Datum {
public:
    int d;
    int m;
    int g;

    void setD(int d);
    void setM(int m);
    void setG(int g);

    int getD();
    int getM();
    int getG();

    Datum();
    Datum(int d,int m,int g);

    int compareTo(Datum tmp_datum);
    void ispisiDatum();
};


#endif //KOL1_DATUM_H
