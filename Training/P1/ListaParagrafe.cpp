//
// Created by alexandru on 10.04.2022.
//

#include "ListaParagrafe.h"
#include <string.h>

void ListaParagrafe::add(const char *sentence) {
    int len = strlen(sentence);
    sentences[cntSentences] = new char[len + 1];
    for(int i = 0; i < len; ++i) {
        sentences[cntSentences][i] = sentence[i];
    }
    sentences[cntSentences][len] = '\0';
    cntSentences++;
}

int ListaParagrafe::size() const {
    return cntSentences;
}

char *ListaParagrafe::get(int index) const {
    return sentences[index];
}

char **ListaParagrafe::begin() {
    return sentences;
}

char **ListaParagrafe::end() {
    return (sentences + cntSentences);
}


