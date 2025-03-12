#include <iostream>

using namespace std;

#include "Produs.h"
#include "Magazin.h"
#include "MagazinFile.h"
#include "Teste.h"
#include "Service.h"
#include "UI.h"
#include "Exceptie.h"
#include "Validator.h"
#include <cassert>

int main() {
    try{
        Produs p1(1, "mere", 10);
        Produs p2(2, "pere", 20);

        Magazin magazin;
        magazin.adaugaProdus(p1);
        magazin.adaugaProdus(p2);

        Produs produsInvalid(1, "", 10);
    }
    catch (Exceptie &ex){
        cout << "Eroare: " << ex.what() << endl;
    }

    Teste teste;
    teste.testAll();

    Magazin magazin;
    MagazinFile magazinFile("magazin.txt");
    Service service(magazinFile);
    UI ui(service);
    ui.run();
    cout << "Done! " << endl;
    return 0;
}
