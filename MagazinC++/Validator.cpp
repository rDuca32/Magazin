//
// Created by Raul on 20.05.2024.
//

#include "Validator.h"
#include "Exceptie.h"
#include <iostream>

using namespace std;

Validator::Validator() {

}

Validator::~Validator() {

}

void Validator::validareCod(int cod) {
    if (cod<=0){
        throw Exceptie("Codul trebuie sa fie un numar pozitiv!", Exceptie::COD_INVALID);
    }
}

void Validator::validareNume(const string& nume) {
    if (nume.empty()){
        throw Exceptie("Numele nu poate fi gol!", Exceptie::NUME_INVALID);
    }
}

void Validator::validarePret(int pret) {
    if (pret<=0){
        throw Exceptie("Pretul trebuie sa fie un numar pozitiv!", Exceptie::PRET_INVALID);
    }
}

void Validator::validareBancnota(int bancnota) {
    if (bancnota!=1 && bancnota!=5 && bancnota!=10 && bancnota!=50){
        throw Exceptie("Bancnota invalida!", Exceptie::BANCNOTA_INVALIDA);
    }
}
