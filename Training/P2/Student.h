//
// Created by alexandru on 10.04.2022.
//

#ifndef P2_STUDENT_H
#define P2_STUDENT_H
class Student {
    char *name, *subjects[100];
    int marks[100], cntSubjects;
public:
    Student(const char * _name);
    Student();
    ~Student();
    Student& operator = (Student& );
    char *GetName();
    int &operator [] (const char *);
    void printNote();
    operator float();
};
#endif //P2_STUDENT_H
