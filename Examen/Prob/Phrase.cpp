//
// Created by alexandru on 12.04.2022.
//

#include "Phrase.h"
#include <iostream>

Phrase::Phrase(const char *sentence) {
    // ALOCARE DE MEMORIE
    Words = new char* [200];
    for(int i = 0; i < 200; ++i) {
        Words[i] = new char [200];
    }
    cntWords = 0;
    const char *p = sentence;
    int cursor = 0;
    bool space = true;
    while(*p != '\0') {
        if(*p == ' ') {
            if(!space) {
                Words[cntWords][cursor] = '\0';
                cntWords++;
                space = true;
                cursor = 0;
            }
        } else {
            Words[cntWords][cursor++] = *p;
            space = false;
        }
        p++;
    }
    if(cursor > 0) {
        Words[cntWords][cursor] = '\0';
        cntWords++;
        cursor = 0;
    }
}

Phrase::operator int() const {
    return cntWords;
}

char *Phrase::operator[](int index) {
    if(index >= 0 && index < cntWords) {
        return Words[index];
    }
}

int Phrase::CountLetter(int index, char c) {
    if(index >= 0 && index < cntWords) {
        int cnt = 0;
        int sz = GetSize(Words[index]);
        for(int i = 0; i < sz; ++i) {
            if(Words[index][i] == c) {
                cnt++;
            }
        }
        return cnt;
    }
}

int Phrase::CountLetter(char c) {
    int cnt = 0;
    for(int i = 0; i < cntWords; ++i) {
        cnt += CountLetter(i, c);
    }
    return cnt;
}

int Phrase::GetSize(char *word) {
    char *p = word;
    int sz = 0;
    while(*p != '\0') {
        sz++;
        p++;
    }
    return sz;
}

char* Phrase::GetLongestWord() {
    int index = 0;
    for(int i = 1; i < cntWords; ++i) {
        if(GetSize(Words[i]) > GetSize(Words[index])) {
            index = i;
        }
    }
    return Words[index];
}

int Phrase::CountVowels() {
    int cnt = 0;
    for(int i = 0; i < cntWords; ++i) {
        cnt += Vowels(Words[i]);
    }
    return cnt;
}

bool Phrase::isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int Phrase::Vowels(char *word) {
    int cnt = 0;
    int sz = GetSize(word);
    for(int i = 0; i < sz; ++i) {
        if(isVowel(word[i])) {
            cnt++;
        }
    }
    return cnt;
}

Phrase::~Phrase() {
    delete [] Words;
}

