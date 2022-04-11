//
// Created by alexandru on 11.04.2022.
//

#ifndef P4_CALCULATOR_H
#define P4_CALCULATOR_H
#include "Model.h"

class Calculator {
    Operation *List[10];
    int nrOps;
public :
    operator int();
    bool operator [] (const char* _name);
    Calculator() : nrOps(0), List{} {};
    void operator += (Operation *obj);
    void operator -= (const char *_name);
    virtual void Compute(int x, int y);
};


#endif //P4_CALCULATOR_H
