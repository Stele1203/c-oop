//
// Created by User on 1/28/2024.
//

#ifndef KOL1_DATUMSTACK_H
#define KOL1_DATUMSTACK_H
#include "Datum.h"

class DatumStack {
    Datum* niz;
    int kapacitet;
    int brElem;

public:
    DatumStack();

    void push(Datum d);
    Datum pop();
    DatumStack& sortiraj();
    void ispisiStack();
};


#endif //KOL1_DATUMSTACK_H
