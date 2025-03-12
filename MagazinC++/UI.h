//
// Created by Raul on 14.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_UI_H
#define _NEW_LABORATOROOP_9_10_UI_H

#include "Service.h"

class UI {
private:
    Service service;
    void printMenu();

    void adaugaProdus();
    void stergeProdus();
    void updateProdus();
    void cumparaProdus();
    void afiseazaProduse();
    void adaugaBancnota();
    void afiseazaBancnote();

public:
    UI();
    ~UI();
    UI(const Service& service);

    void run();

    void bancnotePredefinite();
};


#endif //_NEW_LABORATOROOP_9_10_UI_H
