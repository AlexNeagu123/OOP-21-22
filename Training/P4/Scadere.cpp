//
// Created by alexandru on 11.04.2022.
//

#include "Scadere.h"
#include <iostream>

void Scadere::Calculate(int x, int y) {
    PrintAns(x, y, x - y);
}
void Scadere::PrintAns(int x, int y, int res) {
    printf("Scadere(%d, %d) = %d\n", x, y, res);
}

const char *Scadere::GetName() {
    return "Scadere";
}

