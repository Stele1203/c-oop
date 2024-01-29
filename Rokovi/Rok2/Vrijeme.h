//
// Created by User on 1/28/2024.
//

#ifndef KOL2_VRIJEME_H
#define KOL2_VRIJEME_H


class Vrijeme {
protected:
    int sat;
    int min;
public:
    static bool checkMin(int min);
    static bool checkSat(int sat);
    static bool validVrijeme(int sat, int min);
    Vrijeme& operator++();
    void ispisiVrijeme() const;



    void setSat(int sat);
    void setMin(int min);

    int getSat() const;
    int getMin() const;


    Vrijeme(int sat, int min);
};


#endif //KOL2_VRIJEME_H
