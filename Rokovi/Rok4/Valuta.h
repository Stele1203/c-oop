//
// Created by User on 2/1/2024.
//

#ifndef VALUTA_VALUTA_H
#define VALUTA_VALUTA_H


class Valuta {
private:
    char* naziv;
    double iznos;
public:
    Valuta(char* naziv, double iznos);

    //seteri
    void setNaziv(char* naziv);
    void setIznos(double iznos);

    //geteri
    char* getNaziv() const;
    double getIznos() const;
};


#endif //VALUTA_VALUTA_H
