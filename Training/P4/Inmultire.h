//
// Created by alexandru on 11.04.2022.
//

#ifndef P4_INMULTIRE_H
#define P4_INMULTIRE_H
#include "Calculator.h"
#include "Model.h"
class Inmultire : public Operation {
    void Calculate(int x, int y) override;
    void PrintAns(int x, int y, int res) override;
    const char* GetName() override;
};

#endif //P4_INMULTIRE_H
