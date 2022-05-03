#include <iostream>
#include "Map.h"
#include "Element.h"
using namespace std;

int main() {

    Map<int, const char*> m;
    m[30] = "C++";
    m[10] = "test";
    m[20] = "Poo";
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(20, "result");
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    const char *d;
    m.Get(20, d);
    printf("%s\n", d);
    Map<int, const char*> m1;
    m1[30] = "the";
    m1[15] = "ta";
    cout << m.Includes(m1) << '\n';
    auto mmm = m[100];
    for (auto[key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;

}
