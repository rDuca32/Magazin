//
// Created by Raul on 14.05.2024.
//

#include "Teste.h"
#include <iostream>
#include <cassert>
#include "Produs.h"
#include "Magazin.h"
#include "Service.h"
#include "MagazinFile.h"
#include "Exceptie.h"

#include <cstring>

using namespace std;

Teste::Teste() {

}

void Teste::testAll() {
    testProdus();
    testMagazin();
    testService();
    testMagazinFile();
    cout << "Testele au trecut! " << endl;
}

void Teste::testProdus() {
    try{
        Produs p1(1, "mere", 10);
        Produs p2(2, "pere", 20);

        Magazin magazin;
        magazin.adaugaProdus(p1);
        magazin.adaugaProdus(p2);

        Produs produsInvalid(-1, "cola", 10);
    }
    catch (Exceptie &ex){
        cout << "Eroare: "  << ex.getMesaj() << endl;

    }
    Produs p1(1, "mere", 10);
    Produs p2(2, "pere", 20);
    assert(p1.getCod() == 1);
    assert(p1.getNume() == "mere");
    assert(p1.getPret() == 10);
    assert(p2.getCod() == 2);

    p1.setCod(3);
    assert(p1.getCod() == 3);

    p1.setNume("banane");
    assert(p1.getNume() == "banane");

    p1.setPret(30);
    assert(p1.getPret() == 30);

    Produs p3 = p1;
    assert(p3 == p1);

    char* str = p1.toString();
    assert(strcmp(str, "3 banane 30") == 0);

    delete[] str;
}

void Teste::testMagazin() {

}

void Teste::testService() {

}

void Teste::testMagazinFile() {

}
