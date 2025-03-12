//
// Created by Raul on 20.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_EXCEPTIE_H
#define _NEW_LABORATOROOP_9_10_EXCEPTIE_H

#include <string>
#include <vector>

using namespace std;

class Exceptie {
private:
    string mesaj;
    int codEroare;
public:
    enum CodEroare {
        COD_INVALID,
        NUME_INVALID,
        PRET_INVALID,
        BANCNOTA_INVALIDA
    };

    Exceptie(const string &mesaj, int codEroare);

    string getMesaj() const;
    int getCodEroare() const;

    const char *what() const noexcept;
};


#endif //_NEW_LABORATOROOP_9_10_EXCEPTIE_H
