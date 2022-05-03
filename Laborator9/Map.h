//
// Created by alexandru on 27.04.2022.
//

#ifndef LABORATOR9_MAP_H
#define LABORATOR9_MAP_H
#include "Element.h"
using namespace std;

template<class K, class V>
class Map {
    Element<K, V> *table;
    int countElements, maxSize;
    void resize() {
        maxSize *= 2;
        auto *BigTable = new Element<K, V>[maxSize];
        for(int i = 0; i < countElements; ++i) {
            BigTable[i] = table[i];
        }
        auto *aux = table;
        table = BigTable;
        delete[] aux;
    }
    void normalize(int &currentPos) {
        while(currentPos > 0 && table[currentPos].key < table[currentPos - 1].key) {
            std::swap(table[currentPos], table[currentPos - 1]);
            table[currentPos].index = currentPos;
            table[currentPos - 1].index = currentPos - 1;
            currentPos--;
        }
    }
public:
    Map() : countElements(0), maxSize(1) {
        table = new Element<K, V>[maxSize];
    };
    void Set(const K& _key, const V& _val) {
        for (int i = 0; i < countElements; ++i) {
            if (table[i].key == _key) {
                table[i].value = _val;
                return;
            }
        }
        if(countElements == maxSize) {
            resize();
        }
        table[countElements].key = _key;
        table[countElements].value = _val;
        table[countElements].index = countElements;
        int currentPos = countElements;
        normalize(currentPos);
        countElements++;
    }
    Element<K, V>& operator [] (K _key) {
        for (int i = 0; i < countElements; ++i) {
            if (table[i].key == _key) {
                return table[i];
            }
        }
        if(countElements == maxSize) {
            resize();
        }
        table[countElements].key = _key;
        table[countElements].index = countElements;
        int currentPos = countElements;
        countElements++;
        normalize(currentPos);
        return table[currentPos];
    }
    const Element<K, V> * begin() const {
        return &table[0];
    }
    const Element<K, V> * end() const {
        return &table[countElements];
    }
    int Count() {
        return countElements;
    }
    bool Get(const K& key, V& value) const {
        for(int i = 0; i < countElements; ++i) {
            if(table[i].key == key) {
                value = table[i].value;
                return true;
            }
        }
        return false;
    }
    void Delete(const K& key) {
        int foundIndex = -1;
        for(int i = 0; i < countElements; ++i) {
            if(table[i].key == key) {
                foundIndex = i;
                break;
            }
        }
        if(foundIndex == -1 || countElements == 0) {
            return;
        }
        for(int i = foundIndex; i < countElements - 1; ++i) {
            std::swap(table[i], table[i + 1]);
            table[i].index = i;
        }
        countElements--;
    }
    void Clear() {
        countElements = 0;
    }
    bool Includes(const Map<K, V> &map) {
        for(const auto [key, value, index] : map) {
            V currentValue;
            if(!Get(key, currentValue)) {
                return false;
            }
        }
        return true;
    }

};
#endif //LABORATOR9_MAP_H
