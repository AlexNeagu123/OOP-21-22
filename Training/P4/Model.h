//
// Created by alexandru on 11.04.2022.
//

#ifndef P4_MODEL_H
#define P4_MODEL_H
class Operation {
public:
    virtual void Calculate(int x, int y) = 0;
    virtual void PrintAns(int x, int y, int res) = 0;
    virtual const char* GetName() = 0;
};
#endif //P4_MODEL_H
