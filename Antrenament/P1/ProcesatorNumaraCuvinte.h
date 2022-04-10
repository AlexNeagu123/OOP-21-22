//
// Created by alexandru on 10.04.2022.
//

#ifndef ANTRENAMENT_PROCESATORNUMARACUVINTE_H
#define ANTRENAMENT_PROCESATORNUMARACUVINTE_H

#include "Procesator.h"

class ProcesatorNumaraCuvinte : public Procesator {
    char *words[100];
    int freq[100], cntWords;
    bool is_sep(char ch);
    void update(char *w);
public :
    ProcesatorNumaraCuvinte() : words{}, freq{}, cntWords(0) {}
    ~ProcesatorNumaraCuvinte() {
        delete [] *words;
    }
    void Proceseaza(char *sentence) override;
    void Print() override;
};
#endif //ANTRENAMENT_PROCESATORNUMARACUVINTE_H
