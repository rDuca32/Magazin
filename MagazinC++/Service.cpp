//
// Created by Raul on 14.05.2024.
//

#include "Service.h"

Service::Service() {

}

Service::~Service() {

}

Service::Service(const Magazin &magazin) {
    this->magazin = magazin;
}

void Service::adaugaProdus(int cod, string nume, int pret) {
    Produs produs(cod, nume, pret);
    magazin.adaugaProdus(produs);
}

void Service::cumparaProdus(const Produs &produs, int plata) {
    magazin.cumparaProdus(produs, plata);
}

bool Service::sePoateOferiRest(int rest) const {
    return magazin.sePoateOferiRest(rest);
}

Produs *Service::getAllProduse() {
    return magazin.getProduse();
}

int Service::getNrProduse() const {
    return magazin.getNrProduse();
}

int Service::getNrBancnote() const {
    return magazin.getNrBancnote();
}

int Service::getSoldRamas() const {
    return magazin.getSoldRamas();
}

int Service::updateProdus(Produs produs, Produs newProdus) {
    for (int i = 0; i < magazin.getNrProduse(); i++) {
        if (magazin.getProduse()[i].getCod() == produs.getCod()) {
            magazin.updateProdus(produs.getCod(), produs.getNume(), produs.getPret(), newProdus.getCod(), newProdus.getNume(), newProdus.getPret());
            return 1;
        }
    }
}

int Service::removeProdus(Produs produs) {
    for (int i = 0; i < magazin.getNrProduse(); i++) {
        if (magazin.getProduse()[i] == produs) {
            magazin.removeProdus(produs.getCod());
            return 1;
        }
    }
    return 0;
}

void Service::adaugaBancnota(int valoare, int nrBancnote) {
    magazin.adaugaBancnota(valoare, nrBancnote);
}

void Service::setSoldRamas(int soldRamas) {
    magazin.setSoldRamas(soldRamas);
}

int Service::getValoareBancnota(int index) const {
    return magazin.getValoareBancnota(index);
}

int Service::getNrBancnoteTip(int index) const {
    return magazin.getNrBancnoteTip(index);
}
