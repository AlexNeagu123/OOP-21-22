//
// Created by alexandru on 21.03.2022.
//

#ifndef P1_NUMBER_H
#define P1_NUMBER_H
//
// Created by alexandru on 21.03.2022.
//
#pragma once
class Number
{
    char* value;
    unsigned int numberSize;
    int base, ten;
    static int toTen(const char* nr, int base);
    static char* fromTen(int nr, int base);
    Number(int valueBase10, int base);
    // add data members

public:
    Number(const char* value, int base); // where base is between 2 and 16
    Number(int valueBase10);
    Number(const Number& obj);
    Number(Number&& obj);
    ~Number();
    // add operators and copy/move constructor
    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
    char operator[](int index);
    bool operator <(const Number& him) const;
    bool operator <=(const Number& him) const;
    bool operator >(const Number& him) const;
    bool operator >=(const Number& him) const;
    bool operator ==(const Number& him) const;
    bool operator !=(const Number& him) const;
    friend void operator +=(Number& me, const Number& him);
    friend void operator -=(Number& me, const Number& him);
    Number& operator--();
    Number operator--(int);
    Number& operator=(const Number& obj);
    Number& operator=(const char* him);
    Number& operator=(int him);
    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount(); // returns the number of digits for the current number
    int GetBase(); // returns the current base
};
#endif //P1_NUMBER_H
