#include <iostream>
#include "vector.h"

struct P {
    int x, y;
    bool operator<(const P &a) const {
        if(x == a.x) {
            return y > a.y;
        }
        return x > a.x;
    }
    bool operator ==(const P &a) const {
        return (x == a.x && y == a.y);
    }
};

bool cmp(P a, P b) {
    return a.x < b.x;
}
bool eq(P a, P b) {
    return (a.x == b.x && a.y == b.y);
}

int main() {
    vector<P> v;
    for(int i = 0; i < 3; ++i) {
        P a;
        std::cin >> a.x >> a.y;
        v.push(a);
    }

    for(int i = 0; i < v.count(); ++i) {
        std::cout << v.get(i).x << ' ' << v.get(i).y << '\n';
    }
    std::cout << v.firstIndexOf(P{3, 6}) << '\n';
    std::cout << '\n';
    v.sort();
    for(int i = 0; i < v.count(); ++i) {
        std::cout << v.get(i).x << ' ' << v.get(i).y << '\n';
    }
    std::cout << '\n';

    return 0;
}
