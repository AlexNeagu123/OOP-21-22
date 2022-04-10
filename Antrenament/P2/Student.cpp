//
// Created by alexandru on 10.04.2022.
//

#include "Student.h"
#include <string.h>
#include <iostream>

Student::Student(const char *_name) : subjects{}, marks{}, cntSubjects(0) {
    int len = strlen(_name);
    name = new char[len + 1];
    strcpy(name, _name);
}
Student::Student() : subjects{}, marks{}, name(nullptr), cntSubjects(0) {}

char *Student::GetName() {
    return name;
}

int &Student::operator[](const char *newSub) {
    for(int i = 0; i < cntSubjects; ++i) {
        if(!strcmp(subjects[i], newSub)) {
            return marks[i];
        }
    }
    int len = strlen(newSub);
    subjects[cntSubjects] = new char[len + 1];
    strcpy(subjects[cntSubjects], newSub);
    cntSubjects++;
    return marks[cntSubjects - 1];
}

void Student::printNote() {
    for(int i = 0; i < cntSubjects; ++i) {
        printf("%s : %d\n", subjects[i], marks[i]);
    }
}

Student::operator float() {
    float avg = 0;
    for(int i = 0; i < cntSubjects; ++i) {
        avg += marks[i];
    }
    return avg / cntSubjects;
}

Student::~Student() {
    delete name;
    delete [] *subjects;
}

Student& Student::operator=(Student &him) {
    int len = strlen(him.GetName());
    name = new char[len + 1];
    strcpy(name, him.GetName());
    return (*this);
}



