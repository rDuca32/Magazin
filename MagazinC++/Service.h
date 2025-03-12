//
// Created by Raul on 14.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_SERVICE_H
#define _NEW_LABORATOROOP_9_10_SERVICE_H

#include "Magazin.h"

class Service {
private:
    Magazin magazin;
public:
    Service();
    ~Service();
    Service(const Magazin& magazin);

    void adaugaProdus(int cod, string nume, int pret);
    void cumparaProdus(const Produs& produs, int plata);
    bool sePoateOferiRest(int rest) const;
    void adaugaBancnota(int valoare, int nrBancnote);

    Produs* getAllProduse();

    int getNrProduse() const;
    int getNrBancnote() const;
    int getValoareBancnota(int index) const;
    int getNrBancnoteTip(int index) const;
    int getSoldRamas() const;

    void setSoldRamas(int soldRamas);

    int updateProdus(Produs produs, Produs newProdus);
    int removeProdus(Produs produs);
};


#endif //_NEW_LABORATOROOP_9_10_SERVICE_H
