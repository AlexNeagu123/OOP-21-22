#include <iostream>
#include "ListaParagrafe.h"
#include "Procesator.h"
#include "ProcesatorNumaraCuvinte.h"
#include "ProcesatorNumaraPropozitii.h"
int main() {

    ListaParagrafe L;
    L.add("Gavrilutz este zeu.");
    L.add("este zeu.");
    Procesator *P = new ProcesatorNumaraCuvinte();
    Procesator *P2 = new ProcesatorNumaraPropozitii();
    for(auto paragraf : L) {
        P -> Proceseaza(paragraf);
        P2 -> Proceseaza(paragraf);
    }
    P -> Print();
    P2 -> Print();
    delete P;
    delete P2;
    for(auto paragraf : L) {
        cout << paragraf << '\n';
    }
    return 0;
}
