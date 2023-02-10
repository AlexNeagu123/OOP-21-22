//
// Created by alexandru on 10.04.2022.
//

#include "Catalog.h"
#include <string.h>
#include <iostream>
using namespace std;
void Catalog::operator+=(Student it) {
    studs[cntStudents++] = it;
}
int Catalog::GetCount() const {
    return cntStudents;
}

Student &Catalog::operator[](int index) {
    return studs[index];
}

Student &Catalog::operator[](const char* it) {
    for(int i = 0; i < cntStudents; ++i) {
        if(!strcmp(studs[i].GetName(), it)) {
            return studs[i];
        }
    }
}

