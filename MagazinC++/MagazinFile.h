//
// Created by Raul on 14.05.2024.
//

#ifndef _NEW_LABORATOROOP_9_10_MAGAZINFILE_H
#define _NEW_LABORATOROOP_9_10_MAGAZINFILE_H

#include "Magazin.h"

class MagazinFile: public Magazin{
private:
    char* fileName;
public:
    MagazinFile();
    MagazinFile(const char* file);
    ~MagazinFile();
    MagazinFile(const MagazinFile& magazinFile);

    void loadFromFile();
    void saveToFile();

    void adaugaProdus(const Produs& produs);
    void stergeProdus(int cod);
    int getNrProduse();
    Produs getProdus(int index);

};


#endif //_NEW_LABORATOROOP_9_10_MAGAZINFILE_H
