//
// Created by alexandru on 11.04.2022.
//

#include "Calculator.h"
#include <iostream>
#include "cstring"

void Calculator::Compute(int x, int y) {
    for(int i = 0; i < nrOps; ++i) {
        List[i] -> Calculate(x, y);
    }
}

void Calculator::operator+=(Operation *obj) {
    bool gasit = false;
    for(int i = 0; i < nrOps; ++i) {
        if(!strcmp(obj -> GetName(), List[i] -> GetName())) {
            gasit = true;
            break;
        }
    }
    if(!gasit) {
        List[nrOps++] = obj;
    }
}

Calculator::operator int() {
    return nrOps;
}

bool Calculator::operator[](const char *_name) {
    for(int i = 0; i < nrOps; ++i) {
        if(!strcmp(List[i] -> GetName(), _name)) {
            return true;
        }
    }
    return false;
}

void Calculator::operator-=(const char *_name) {
    int index = -1;
    for(int i = 0; i < nrOps; ++i) {
        if (!strcmp(List[i]->GetName(), _name)) {
            index = i;
        }
    }
    for(int i = index + 1; i < nrOps; ++i) {
        List[i - 1] = List[i];
    }
    nrOps--;
}
