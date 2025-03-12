//
// Created by Raul on 14.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_MAGAZIN_H
#define _NEW_LABORATOROOP_9_10_MAGAZIN_H

#include "Produs.h"

class Magazin {
private:
    Produs* produse;
    int nrProduse;
    int valoareBancnote[4] = {1, 5, 10, 50};
    int nrBancnote[4] = {0, 0, 0, 0};
public:
    Magazin();
    Magazin(Produs* produse, int nrProduse);
    Magazin(const Magazin& magazin);
    ~Magazin();

    Produs getProdus(int cod) const;
    Produs* getProduse() const;
    int getNrProduse() const;
    int getSoldRamas() const;
    int getPlata(int valoare) const;
    int getNrBancnote() const;
    int getValoareBancnota(int index) const;
    int getNrBancnoteTip(int index) const;

    void setProduse(Produs* produse, int nrProduse);
    void setNrProduse(int nrProduse);
    void setSoldRamas(int soldRamas);

    Magazin& operator=(const Magazin& magazin);

    bool operator==(const Magazin& magazin) const;

    char* toString() const;

    void adaugaProdus(const Produs& produs);
    void cumparaProdus(const Produs& produs, int plata);
    bool sePoateOferiRest(int rest) const;
    void adaugaBancnota(int valoare, int nr);

    int removeProdus(int cod);
    int updateProdus(int cod, string nume, int pret, int newCod, string newNume, int newPret);

    bool existaProdus(int cod) const;
};


#endif //_NEW_LABORATOROOP_9_10_MAGAZIN_H
