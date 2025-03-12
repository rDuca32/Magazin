//
// Created by Raul on 20.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_VALIDATOR_H
#define _NEW_LABORATOROOP_9_10_VALIDATOR_H

#include <string>

using namespace std;

class Validator {
public:
    Validator();
    ~Validator();

    static void validareCod(int cod);
    static void validareNume(const string& nume);
    static void validarePret(int pret);
    static void validareBancnota(int bancnota);
};


#endif //_NEW_LABORATOROOP_9_10_VALIDATOR_H
