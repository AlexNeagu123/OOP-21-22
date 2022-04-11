//
// Created by alexandru on 11.04.2022.
//

#include "Impartire.h"
#include <iostream>

void Impartire::Calculate(int x, int y) {
    PrintAns(x, y, x / y);
}

void Impartire::PrintAns(int x, int y, int res) {
    printf("Impartire(%d, %d) = %d\n", x, y, res);
}

const char *Impartire::GetName() {
    return "Impartire";
}
