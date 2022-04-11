//
// Created by alexandru on 11.04.2022.
//

#ifndef P4_IMPARTIRE_H
#define P4_IMPARTIRE_H
#include "Calculator.h"
#include "Model.h"
class Impartire : public Operation{
    void Calculate(int x, int y) override;
    void PrintAns(int x, int y, int res) override;
    const char *GetName() override;
};


#endif //P4_IMPARTIRE_H
