//
// Created by alexandru on 27.04.2022.
//

#ifndef LABORATOR9_ELEMENT_H
#define LABORATOR9_ELEMENT_H

template<class K, class V>
struct Element {
    K key;
    V value;
    int index;
    Element() : key{}, value{}, index{} {};
    Element& operator = (V _value) {
        value = _value;
        return (*this);
    }
};

#endif //LABORATOR9_ELEMENT_H

