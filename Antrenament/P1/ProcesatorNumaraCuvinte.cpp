//
// Created by alexandru on 10.04.2022.
//

#include "ProcesatorNumaraCuvinte.h"
#include "Procesator.h"

bool ProcesatorNumaraCuvinte::is_sep(char ch) {
    return (ch == ' ' || ch == ',' || ch == '!' || ch == '.' || ch == '?');
}
void ProcesatorNumaraCuvinte::update(char *w) {
    bool B = false;
    for(int i = 0; i < cntWords; ++i) {
        if(!strcmp(w, words[i])) {
            freq[i]++;
            B = true;
            break;
        }
    }
    if(!B) {
        freq[cntWords] = 1;
        words[cntWords] = new char [100];
        strcpy(words[cntWords], w);
        cntWords++;
    }
}

void ProcesatorNumaraCuvinte::Print() {
    for(int i = 0; i < cntWords; ++i) {
        std::cout << words[i] << ' ' << freq[i] << ' ';
    }
    std::cout << '\n';
}

void ProcesatorNumaraCuvinte::Proceseaza(char *sentence) {
    char *w = new char[100];
    int counter = 0, len = strlen(sentence);
    for(int i = 0; i < len; ++i) {
        if(is_sep(sentence[i])) {
            if(counter > 0) {
                w[counter] = '\0';
                update(w);
                counter = 0;
            }
        } else {
            w[counter++] = sentence[i];
        }
    }
    if(counter > 0) {
        w[counter] = '\0';
        update(w);
        counter = 0;
    }
}

