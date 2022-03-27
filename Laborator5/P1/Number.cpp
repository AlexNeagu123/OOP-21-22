#include "Number.h"
#include <iostream>
#include <cstring>
using namespace std;

// USEFUL PRIVATE FUNCTIONS
int Number::toTen(const char* nr, int base) {
    int answer = 0;
    for (int i = 0; i < strlen(nr); ++i) {
        answer *= base;
        if (nr[i] >= '0' && nr[i] <= '9') {
            answer += nr[i] - '0';
        }
        else {
            answer += 10 + (nr[i] - 'A');
        }
    }
    return answer;
}
char* Number::fromTen(int nr, int base) {
    if (nr == 0) {
        char* answer = (char*)"0\0";
        return answer;
    }
    int copyNr = nr, answerSize = 0;
    while (copyNr) {
        answerSize++;
        copyNr /= base;
    }
    char* answer = new char[answerSize + 1];
    int current = answerSize - 1;
    while (nr) {
        int dig = nr % base;
        char character = dig < 10 ? '0' + dig : 'A' + (dig - 10);
        answer[current--] = character;
        nr /= base;
    }
    answer[answerSize] = '\0';
    return answer;
}
// PRIVATE CONSTRUCTOR DEFINED BY ME
Number::Number(int valueBase10, int _base) {
    value = fromTen(valueBase10, _base);
    base = _base;
    numberSize = strlen(value);
    ten = valueBase10;
}
// CONSTRUCTORS
Number::Number(const char* _value, int _base) {
    base = _base;
    ten = toTen(_value, _base);
    numberSize = strlen(_value);
    value = new char[numberSize + 1];
    for (int i = 0; i < numberSize; ++i) {
        value[i] = _value[i];
    }
    value[numberSize] = '\0';
}
Number::Number(int valueBase10) {
    value = fromTen(valueBase10, 10);
    base = 10;
    ten = valueBase10;
    numberSize = strlen(value);
}
// COPY CONSTRUCTOR
Number::Number(const Number& obj) {
    base = obj.base;
    ten = obj.ten;
    numberSize = obj.numberSize;
    value = new char[numberSize + 1];
    for (int i = 0; i < numberSize; ++i) {
        value[i] = obj.value[i];
    }
    value[numberSize] = '\0';
}
Number::Number(Number&& obj) {
    value = obj.value;
    base = obj.base;
    ten = obj.ten;
    numberSize = obj.numberSize;
    obj.value = nullptr;
}
// DESTRUCTOR
Number::~Number() {
    delete[] value;
}
// MAIN FUNCTIONS
void Number::SwitchBase(int newBase) {
    value = fromTen(ten, newBase);
    numberSize = strlen(value);
    base = newBase;
}
void Number::Print() {
    cout << value << '\n';
}
int Number::GetDigitsCount() {
    return (int)numberSize;
}
int Number::GetBase() {
    return base;
}
// OPERATORS
Number operator+(const Number& a, const Number& b) {
    int add = a.ten + b.ten;
    int resultBase = max(a.base, b.base);
    Number answer = { add, resultBase };
    return answer;
}
Number operator-(const Number& a, const Number& b) {
    int sub = a.ten > b.ten ? a.ten - b.ten : b.ten - a.ten;
    int resultBase = max(a.base, b.base);
    Number answer = { sub, resultBase };
    return answer;
}
char Number::operator[](int index) {
    if (index >= 0 && index < numberSize) {
        return value[index];
    }
    return 0;
}
Number& Number::operator=(const Number& obj) {

    base = obj.base;
    ten = obj.ten;
    numberSize = obj.numberSize;
    delete[] value;
    value = new char[numberSize + 1];
    for (int i = 0; i < numberSize; ++i) {
        value[i] = obj.value[i];
    }
    value[numberSize] = '\0';
    return (*this);
}
Number& Number::operator=(const char* him) {
    int intHim = toTen(him, 10);
    value = fromTen(intHim, base);
    numberSize = strlen(value);
    ten = intHim;
    return (*this);
}
Number& Number::operator=(int him) {
    value = fromTen(him, base);
    numberSize = strlen(value);
    ten = him;
    return (*this);
}
bool Number::operator<(const Number& him) const {
    return (ten < him.ten);
}
bool Number::operator<=(const Number& him) const {
    return (ten <= him.ten);
}
bool Number::operator>(const Number& him) const {
    return (ten > him.ten);
}
bool Number::operator>=(const Number& him) const {
    return (ten >= him.ten);
}
bool Number::operator==(const Number& him) const {
    return (ten == him.ten);
}
bool Number::operator!=(const Number& him) const {
    return (ten != him.ten);
}

void operator+=(Number& me, const Number& him) {
    Number add = { me.ten + him.ten, max(me.base, him.base) };
    me = add;
}

void operator-=(Number& me, const Number& him) {
    Number sub = { me.ten >= him.ten ? me.ten - him.ten : him.ten - me.ten, max(me.base, him.base) };
    me = sub;
}

Number& Number::operator--() {
    for (int i = 0; i <= (int)numberSize - 2; ++i) {
        value[i] = value[i + 1];
    }
    numberSize--;
    value[numberSize] = '\0';
    ten = toTen(value, base);
    return (*this);
}

Number Number::operator--(int) {
    Number TempObject = *this;
    numberSize--;
    value[numberSize] = '\0';
    ten = toTen(value, base);
    return TempObject;
}