//
// Created by User on 1/29/2024.
//

#ifndef KOL2_INTERVAL_H
#define KOL2_INTERVAL_H
#include "Vrijeme.h"



class Interval: public Vrijeme{
private:
    int trajanje;
public:
    int getTrajanje() const;
    void setTrajanje(int trajanje);

    Interval(int sat, int min, int trajanje): Vrijeme(sat,min),trajanje(trajanje){}

    Interval& operator+=(int minInt);
    bool operator>(const Interval& desni) const;
    Vrijeme kraj();


};


#endif //KOL2_INTERVAL_H
