//
// Created by Raul on 14.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_PRODUS_H
#define _NEW_LABORATOROOP_9_10_PRODUS_H

#include <string>
#include <iostream>
#include "Validator.h"

using namespace std;

class Produs {
private:
    int cod;
    string nume;
    int pret;
public:
    Produs();
    Produs(int cod, string nume, int pret);
    Produs(const Produs& produs);
    ~Produs();

    int getCod() const;
    string getNume() const;
    int getPret() const;

    void setCod(int cod);
    void setNume(string nume);
    void setPret(int pret);

    Produs& operator=(const Produs& produs);

    bool operator==(const Produs& produs) const;

    char* toString() const;
};


#endif //_NEW_LABORATOROOP_9_10_PRODUS_H
