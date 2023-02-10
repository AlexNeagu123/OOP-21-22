//
// Created by alexandru on 11.04.2022.
//

#include "Adunare.h"
#include <iostream>

void Adunare::PrintAns(int x, int y, int res) {
    printf("Adunare(%d, %d) = %d\n", x, y, res);
}

void Adunare::Calculate(int x, int y) {
    PrintAns(x, y, x + y);
}

const char *Adunare::GetName() {
    return "Adunare";
}

