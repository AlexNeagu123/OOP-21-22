//
// Created by alexandru on 04.04.2022.
//

#ifndef P2_VECTOR_H
#define P2_VECTOR_H
#include<iostream>
template <class T>
class vector {
    T *List;
    int MaxSize, countElements;
    void resize() {
        MaxSize *= 2;
        T* BigList = new T[MaxSize];
        for(int i = 0; i < countElements; ++i) {
            BigList[i] = List[i];
        }
        T* aux = List;
        List = BigList;
        delete[] aux;
    }
public :
    vector() : MaxSize(1), countElements(0) {
        List = new T[MaxSize];
    };
    void push(const T &x) {
        List[countElements] = x;
        countElements++;
        if(countElements == MaxSize) {
            resize();
        }
    }
    T pop() {
        if(countElements) {
            T x = List[countElements - 1];
            countElements--;
            return x;
        }
    }
    void remove(int index) {
        if(index < 0 || index > countElements - 1) {
            exit(0);
        }
        for(int i = index + 1; i < countElements; ++i) {
            List[i - 1] = List[i];
        }
        countElements--;
    }
    void insert(int index, T x) {
        if(index < 0 || index > countElements) {
            exit(0);
        }
        if(countElements == 0) {
            List[index] = x;
            countElements++;
        } else {
            for(int i = countElements; i > index; --i) {
                List[i] = List[i - 1];
            }
            List[index] = x;
            countElements++;
        }
        if(countElements == MaxSize) {
            resize();
        }
    }
    int count() {
        return countElements;
    }
    const T &get(int index) {
        if(index < 0 || index > countElements - 1) {
            exit(0);
        }
        return List[index];
    }
    void sort(bool(*func)(T, T) = nullptr) {
        if(func == nullptr) {
            for(int i = 0; i < countElements; ++i) {
                for(int j = 0; j < countElements - 1; ++j) {
                    if(!(List[j] < List[j + 1])) {
                        std::swap(List[j], List[j + 1]);
                    }
                }
            }
            return;
        }
        for(int i = 0; i < countElements; ++i) {
            for(int j = 0; j < countElements - 1; ++j) {
                if(!func(List[j], List[j + 1])) {
                    std::swap(List[j], List[j + 1]);
                }
            }
        }
    }
    void set(int index, const T &x) {
        if(index < 0 || index > countElements - 1) {
            exit(0);
        }
        List[index] = x;
    }
    int firstIndexOf(const T &obj, bool(*func)(T, T) = nullptr) {
        // callback function not present
        if(func == nullptr) {
            for(int i = 0; i < countElements; ++i) {
                if(List[i] == obj) {
                    return i;
                }
            }
            return -1;
        }
        // callback function present
        for(int i = 0; i < countElements; ++i) {
            if(func(List[i], obj)) {
                return i;
            }
        }
        return -1;
    }
};



#endif //P2_VECTOR_H
