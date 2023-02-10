//
// Created by alexandru on 10.04.2022.
//

#ifndef ANTRENAMENT_PROCESATORNUMARAPROPOZITII_H
#define ANTRENAMENT_PROCESATORNUMARAPROPOZITII_H
#include "Procesator.h"
class ProcesatorNumaraPropozitii : public Procesator {
    int cntSentences = 0;
    bool isSep(char ch);
public:
    void Proceseaza(char *sentence) override;
    void Print() override;
};
#endif //ANTRENAMENT_PROCESATORNUMARAPROPOZITII_H
