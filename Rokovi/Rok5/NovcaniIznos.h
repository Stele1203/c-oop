//
// Created by User on 2/2/2024.
//

#ifndef NOVCANIIZNOS_NOVCANIIZNOS_H
#define NOVCANIIZNOS_NOVCANIIZNOS_H


class NovcaniIznos {
protected:
    int iznos;
    int centi;
public:
    NovcaniIznos();
    NovcaniIznos(int iznos,int centi);

    void setIznos(int iznos);
    void setCenti(int centi);

    int getIznos() const;
    int getCenti() const;

};


#endif //NOVCANIIZNOS_NOVCANIIZNOS_H
