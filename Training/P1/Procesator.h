//
// Created by alexandru on 10.04.2022.
//

#ifndef ANTRENAMENT_PROCESATOR_H
#define ANTRENAMENT_PROCESATOR_H
#include "string.h"
#include "iostream"
class Procesator {
public :
    virtual void Proceseaza(char * sentence) = 0;
    virtual void Print() = 0;
};
#endif //ANTRENAMENT_PROCESATOR_H
