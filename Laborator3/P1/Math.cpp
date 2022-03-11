//
// Created by alexandru on 3/11/22.
//

#include <iostream>
#include <stdarg.h>
#include "Math.h"

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return x + y;
}

int Math::Add(double x, double y, double z) {
    return x + y + z;
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return x * y;
}

int Math::Mul(double x, double y, double z) {
    return x * y * z;
}

int Math::Add(int count, ...) {
    int answer = 0;
    va_list vl;
    va_start(vl, count);
    for(int i = 0; i < count; ++i) {
        int nxt = va_arg(vl, int);
        answer += nxt;
    }
    va_end(vl);
    return answer;
}

char *Math::Add(const char *a, const char *b) {
    int aSize = 0, bSize = 0;
    while(*(a + aSize) != '\0') ++aSize;
    while(*(b + bSize) != '\0') ++bSize;
    char *ans = new char[aSize + bSize + 1];
    for(int i = 0; i < aSize; ++i) {
        *(ans + i) = a[i];
    }
    for(int i = 0; i < bSize; ++i) {
        *(ans + i + aSize) = b[i];
    }
    *(ans + aSize + bSize) = '\0';
    return ans;
}

