//
// Created by alexandru on 12.04.2022.
//

#ifndef PROB_PHRASE_H
#define PROB_PHRASE_H


class Phrase {
    char ** Words;
    int cntWords;
    bool isVowel(char c);
    int GetSize(char *word);
    int Vowels(char *word);
public:
    Phrase(const char *sentence);
    ~Phrase();
    operator int() const;
    char *operator[](int index);
    int CountLetter(int index, char c);
    int CountLetter(char c);
    char* GetLongestWord();
    int CountVowels();
};


#endif //PROB_PHRASE_H
