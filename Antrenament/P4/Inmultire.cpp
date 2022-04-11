//
// Created by alexandru on 11.04.2022.
//

#include "Inmultire.h"
#include <iostream>

void Inmultire::Calculate(int x, int y) {
    PrintAns(x, y, x * y);
}

void Inmultire::PrintAns(int x, int y, int res) {
    printf("Inmultire(%d, %d) = %d\n", x, y, res);
}

const char *Inmultire::GetName() {
    return "Inmultire";
}

