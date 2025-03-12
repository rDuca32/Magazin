//
// Created by Raul on 20.05.2024.
//

#include "Exceptie.h"

Exceptie::Exceptie(const string &mesaj, int codEroare) {
    this->mesaj = mesaj;
    this->codEroare = codEroare;
}

string Exceptie::getMesaj() const {
    return mesaj;
}

int Exceptie::getCodEroare() const {
    return codEroare;
}

const char *Exceptie::what() const noexcept {
    return mesaj.c_str();
}
