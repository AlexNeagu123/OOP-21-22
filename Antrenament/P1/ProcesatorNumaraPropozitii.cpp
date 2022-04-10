//
// Created by alexandru on 10.04.2022.
//

#include "ProcesatorNumaraPropozitii.h"

bool ProcesatorNumaraPropozitii::isSep(char ch) {
    return (ch == '!' || ch == '.' || ch == '?');
}

void ProcesatorNumaraPropozitii::Proceseaza(char *sentence) {
    int len = strlen(sentence);
    bool B = false;
    for(int i = 0; i < len; ++i) {
        if(isSep(sentence[i])) {
            if(B) {
                cntSentences++;
            }
            B = false;
        } else {
            B = true;
        }
    }
    if(B) {
        cntSentences++;
    }
}

void ProcesatorNumaraPropozitii::Print() {
    printf("%d Propozitii\n", cntSentences);
}

