//
// Created by Raul on 14.05.2024.
//

#include "MagazinFile.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Exceptie.h"

using namespace std;


MagazinFile::MagazinFile() {

}

MagazinFile::MagazinFile(const char *file) {
    fileName = new char[strlen(file) + 1];
    strcpy(fileName, file);
    loadFromFile();
}

MagazinFile::~MagazinFile() {
    delete[] fileName;
}

void MagazinFile::loadFromFile() {
    ifstream f(fileName);
    int cod;
    string nume;
    int pret;
    while (f >> cod >> nume >> pret) {
        Produs p(cod, nume, pret);
        try{
            adaugaProdus(p);
        }
        catch (Exceptie &ex){
            cout << "Eroare: " << ex.getCodEroare() << " - " << ex.getMesaj() << endl;
        }
    }
    f.close();
}

int MagazinFile::getNrProduse() {
    return Magazin::getNrProduse();
}

Produs MagazinFile::getProdus(int index) {
    return Magazin::getProdus(index);
}

void MagazinFile::adaugaProdus(const Produs &produs) {
    Magazin::adaugaProdus(produs);
    saveToFile();
}

void MagazinFile::stergeProdus(int cod) {
    Magazin::removeProdus(cod);
    saveToFile();
}

void MagazinFile::saveToFile() {
    ofstream f(fileName);
    for (int i = 0; i < getNrProduse(); i++) {
        Produs p = getProdus(i);
        f << p.toString() << endl;
    }
    f.close();
}

MagazinFile::MagazinFile(const MagazinFile &magazinFile) {
    fileName = new char[strlen(magazinFile.fileName) + 1];
    strcpy(fileName, magazinFile.fileName);
    loadFromFile();
}


