//
// Created by alexandru on 10.04.2022.
//

#ifndef ANTRENAMENT_LISTAPARAGRAFE_H
#define ANTRENAMENT_LISTAPARAGRAFE_H
#include <vector>
using namespace std;
class ListaParagrafe {
    char *sentences[100];
    int cntSentences;
public :
    ListaParagrafe() : cntSentences(0), sentences{} {};
    void add(const char *sentence);
    int size() const;
    char *get(int index) const;
    char** begin();
    char** end();
};
#endif //ANTRENAMENT_LISTAPARAGRAFE_H
