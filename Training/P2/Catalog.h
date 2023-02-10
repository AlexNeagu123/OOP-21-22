//
// Created by alexandru on 10.04.2022.
//

#ifndef P2_CATALOG_H
#define P2_CATALOG_H
#include "Student.h"
class Catalog {
    Student studs[5];
    int cntStudents;
public :
    Catalog() : cntStudents(0) {};
    void operator += (Student it);
    int GetCount() const;
    Student &operator [] (int);
    Student &operator [] (const char* it);
};


#endif //P2_CATALOG_H
