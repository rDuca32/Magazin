//
// Created by Raul on 14.05.2024.
//

#include "UI.h"
#include "Exceptie.h"
#include "Validator.h"

#include <iostream>

using namespace std;

UI::UI() {

}

UI::~UI() {

}

UI::UI(const Service &service) {
    this->service = service;
}

void UI::printMenu() {
    cout << "1. Adauga produs" << endl;
    cout << "2. Cumpara produs" << endl;
    cout << "3. Adauga bancnota" << endl;
    cout << "4. Afiseaza sold" << endl;
    cout << "5. Afiseaza produse" << endl;
    cout << "6. Sterge produs" << endl;
    cout << "7. Update produs" << endl;
    cout << "0. Iesire" << endl;
}

void UI::bancnotePredefinite() {
    service.adaugaBancnota(1, 3);
}

void UI::run() {
    bancnotePredefinite();
    int optiune;
    do{
        printMenu();
        cout << "Alegeti o optiune: " << endl;
        cin >> optiune;
        switch(optiune){
            case 1:
                adaugaProdus();
                break;
            case 2:
                cumparaProdus();
                break;
            case 3:
                adaugaBancnota();
                break;
            case 4:
                afiseazaBancnote();
                break;
            case 5:
                afiseazaProduse();
                break;
            case 6:
                stergeProdus();
                break;
            case 7:
                updateProdus();
                break;
            case 0:
                cout << "La revedere!" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
                break;
        }
    }while(optiune != 0);
}

void UI::adaugaProdus() {
    int cod;
    char nume[100];
    int pret;
    cout << "Introduceti codul produsului: " << endl;
    cin >> cod;
    cout << "Introduceti numele produsului: " << endl;
    cin.get();
    cin.getline(nume, 100);
    cout << "Introduceti pretul produsului: " << endl;
    cin >> pret;
    try{
        service.adaugaProdus(cod, nume, pret);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
    }
    cout << endl;
}

void UI::stergeProdus() {
    int cod;
    char nume[100];
    int pret;
    cout << "Introduceti codul produsului: " << endl;
    cin >> cod;
    cout << "Introduceti numele produsului: " << endl;
    cin.get();
    cin.getline(nume, 100);
    cout << "Introduceti pretul produsului: " << endl;
    cin >> pret;
    Produs produs(cod, nume, pret);
    try{
        service.removeProdus(produs);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
    }
    cout << endl;
}

void UI::updateProdus() {
    int cod, newCod;
    char nume[100], newNume[100];
    int pret, newPret;
    cout << "Introduceti codul produsului: " << endl;
    cin >> cod;
    cout << "Introduceti numele produsului: " << endl;
    cin.get();
    cin.getline(nume, 100);
    cout << "Introduceti pretul produsului: " << endl;
    cin >> pret;
    cout << "Introduceti noul cod al produsului: " << endl;
    cin >> newCod;
    cout << "Introduceti noul nume al produsului: " << endl;
    cin.get();
    cin.getline(newNume, 100);
    cout << "Introduceti noul pret al produsului: " << endl;
    cin >> newPret;

    Produs produs(cod, nume, pret);
    Produs newProdus(newCod, newNume, newPret);
    try{
        service.updateProdus(produs, newProdus);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
    };
    cout << endl;
}

void UI::cumparaProdus() {
    int cod;
    char nume[100];
    int pret;
    int plata;
    cout << "Introduceti codul produsului: " << endl;
    cin >> cod;
    cout << "Introduceti numele produsului: " << endl;
    cin.get();
    cin.getline(nume, 100);
    cout << "Introduceti pretul produsului: " << endl;
    cin >> pret;
    cout << "Introduceti suma de bani: " << endl;
    cin >> plata;
    Produs produs(cod, nume, pret);
    try{
        service.cumparaProdus(produs, plata);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
    }
    cout << endl;
}

void UI::afiseazaProduse() {
    Produs *produse = service.getAllProduse();
    for (int i = 0; i < service.getNrProduse(); i++) {
        cout << produse[i].getCod() << " " << produse[i].getNume() << " " << produse[i].getPret() << endl;
    }
    cout << endl;
}

void UI::adaugaBancnota() {
    int valoare, nrBancnote;
    cout << "Introduceti valoarea bancnotei: " << endl;
    cin >> valoare;
    cout << "Introduceti numarul de bancnote: " << endl;
    cin >> nrBancnote;
    try{
        service.adaugaBancnota(valoare, nrBancnote);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
    }
    cout << endl;
}

void UI::afiseazaBancnote() {
    cout << "Soldul este: " << service.getSoldRamas() << endl;
    cout << "Bancnotele disponibile sunt: " << endl;
    for (int i = 0; i <= service.getNrBancnote(); i++) {
        cout << service.getValoareBancnota(i) << " " << service.getNrBancnoteTip(i) << endl;
    }
    cout << endl;
}