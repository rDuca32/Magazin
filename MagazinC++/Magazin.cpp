//
// Created by Raul on 14.05.2024.
//

#include "Magazin.h"

#include <iostream>
#include <cstring>
#include "Validator.h"

using namespace std;

Magazin::Magazin() {
    nrProduse = 0;
    produse = nullptr;
}

Magazin::Magazin(Produs *produse, int nrProduse) {
    this->produse = produse;
    this->nrProduse = nrProduse;
}

Magazin::Magazin(const Magazin &magazin) {
    if (magazin.produse != nullptr) {
        this->produse = magazin.produse;
        this->nrProduse = magazin.nrProduse;
    }
}

Magazin::~Magazin() {
    delete[] produse;
}

Produs Magazin::getProdus(int cod) const {
    return produse[cod];
}

Produs *Magazin::getProduse() const {
    return produse;
}

int Magazin::getNrProduse() const {
    return nrProduse;
}


void Magazin::setProduse(Produs *produse, int nrProduse) {
    this->produse = produse;
    this->nrProduse = nrProduse;
}


Magazin &Magazin::operator=(const Magazin &magazin) {
    if (this != &magazin) {
        this->produse = magazin.produse;
        this->nrProduse = magazin.nrProduse;
    }
    return *this;
}

bool Magazin::operator==(const Magazin &magazin) const {
    return this->produse == magazin.produse && this->nrProduse == magazin.nrProduse && this->nrBancnote == magazin.nrBancnote;
}

char *Magazin::toString() const {
    char* str = new char[100];
    for (int i = 0; i < nrProduse; i++) {
        strcat(str, produse[i].toString());
        strcat(str, "\n");
    }
    return str;
}

void Magazin::adaugaProdus(const Produs& produs) {
    if (existaProdus(produs.getCod())) {
        cout << "Produsul exista deja" << endl;
        return;
    }
    Produs* newProduse = new Produs[nrProduse + 1];
    for (int i = 0; i < nrProduse; i++) {
        newProduse[i] = produse[i];
    }
    newProduse[nrProduse] = produs;
    nrProduse++;
    delete[] produse;
    produse = newProduse;
}

void Magazin::cumparaProdus(const Produs &produs, int plata) {
    Validator::validareBancnota(plata);
    if (!existaProdus(produs.getCod())) {
        cout << "Produsul nu exista" << endl;
        return;
    }
    bool produsCumparat = false;
    if (plata < produs.getPret()) {
        cout << "Plata insuficienta" << endl;
        return;
    }
    int rest = plata - produs.getPret();
    if (rest == 0) {
        cout << "Ati cumparat produsul " << produs.getNume() << endl;
        adaugaBancnota(plata, 1);
        return;
    }
    else{
        if (sePoateOferiRest(rest)) {
            if (rest > 0) {
                produsCumparat = true;
                cout << "Ati cumparat produsul " << produs.getNume() << " si restul este " << rest << endl;
                adaugaBancnota(plata, 1);
                for (int i = 0; i < 4; i++) {
                    while (rest >= valoareBancnote[i]) {
                        rest -= valoareBancnote[i];
                        nrBancnote[i]--;
                    }
                }
            }
        }
        else {
            cout << "Nu se poate oferi rest" << endl;
        }
    }
    if(produsCumparat) {
        removeProdus(produs.getCod());
    }
    else {
        cout << "Nu s-a putut cumpara produsul" << endl;
    }
}

bool Magazin::sePoateOferiRest(int rest) const {
    for (int i = 0; i < 4; i++) {
        if (rest >= valoareBancnote[i] * nrBancnote[i]) {
            rest -= valoareBancnote[i] * nrBancnote[i];
            if (rest == 0) {
                return true;
            }
        }
    }
    return rest == 0;
}

int Magazin::getSoldRamas() const {
    int soldRamas = 0;
    for (int i = 0; i < 4; i++) {
        soldRamas += valoareBancnote[i] * nrBancnote[i];
    }
    return soldRamas;
}

void Magazin::setNrProduse(int nrProduse) {
    this->nrProduse = nrProduse;
}

void Magazin::setSoldRamas(int soldRamas) {
    for (int i = 0; i < 4; i++) {
        nrBancnote[i] = soldRamas / valoareBancnote[i];
        soldRamas %= valoareBancnote[i];
    }
}

int Magazin::getPlata(int valoare) const {
    return valoare;
}

int Magazin::getNrBancnote() const {
    int nr = 0;
    for (int i = 0; i < 4; i++) {
        nr += nrBancnote[i];
    }
    return nr;
}

int Magazin::removeProdus(int cod) {
    Validator::validareCod(cod);
    if (!existaProdus(cod)) {
        return 0;
    }
    for (int i = 0; i < nrProduse; i++) {
        if (produse[i].getCod() == cod) {
            for (int j = i; j < nrProduse - 1; j++) {
                produse[j] = produse[j + 1];
            }
            nrProduse--;
            return 1;
        }
    }
    return 0;
}

int Magazin::updateProdus(int cod, string nume, int pret, int newCod, string newNume, int newPret) {
    Validator::validareCod(cod);
    Validator::validareNume(nume);
    Validator::validarePret(pret);
    Produs produs(cod, nume, pret);
    if (!existaProdus(cod)) {
        return 0;
    }
    for (int i = 0; i < nrProduse; i++) {
        if (produse[i] == produs) {
            produse[i].setCod(newCod);
            produse[i].setNume(newNume);
            produse[i].setPret(newPret);
            return 1;
        }
    }
    return 0;
}

void Magazin::adaugaBancnota(int valoare, int nr) {
    Validator::validareBancnota(valoare);
    for (int i = 0; i < 4; i++) {
        if (valoare == valoareBancnote[i]) {
            nrBancnote[i] += nr;
        }
    }
}

int Magazin::getValoareBancnota(int index) const {
    return valoareBancnote[index];
}

int Magazin::getNrBancnoteTip(int index) const {
    return nrBancnote[index];
}

bool Magazin::existaProdus(int cod) const {
    for (int i = 0; i < nrProduse; i++) {
        if (produse[i].getCod() == cod) {
            return true;
        }
    }
    return false;
}

