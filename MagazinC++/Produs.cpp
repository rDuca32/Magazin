//
// Created by Raul on 14.05.2024.
//

#include "Produs.h"
#include "Validator.h"

#include <cstring>

using namespace std;

Produs::Produs() {
    this->cod = 0;
    this->nume = "";
    this->pret = 0;
}

Produs::Produs(int cod, string nume, int pret) {
    Validator::validareCod(cod);
    Validator::validareNume(nume);
    Validator::validarePret(pret);
    this->cod = cod;
    this->nume = nume;
    this->pret = pret;
}

Produs::Produs(const Produs &produs) {
    Validator::validareCod(produs.cod);
    Validator::validareNume(produs.nume);
    Validator::validarePret(produs.pret);
    this->cod = produs.cod;
    this->nume = produs.nume;
    this->pret = produs.pret;
}

Produs::~Produs() {

}

int Produs::getCod() const {
    return this->cod;
}

string Produs::getNume() const {
    return this->nume;
}

int Produs::getPret() const {
    return this->pret;
}

void Produs::setCod(int cod) {
    Validator::validareCod(cod);
    this->cod = cod;
}

void Produs::setNume(string nume) {
    Validator::validareNume(nume);
    this->nume = nume;
}

void Produs::setPret(int pret) {
    Validator::validarePret(pret);
    this->pret = pret;
}

Produs &Produs::operator=(const Produs &produs) {
    Validator::validareCod(produs.cod);
    Validator::validareNume(produs.nume);
    Validator::validarePret(produs.pret);
    if (this != &produs) {
        this->cod = produs.cod;
        this->nume = produs.nume;
        this->pret = produs.pret;
    }
    return *this;
}

bool Produs::operator==(const Produs &produs) const {
    return this->cod == produs.cod && this->nume == produs.nume && this->pret == produs.pret;
}

char *Produs::toString() const {
    char *s = new char[100];
    sprintf(s, "%d %s %d", this->cod, this->nume.c_str(), this->pret);
    return s;
}
