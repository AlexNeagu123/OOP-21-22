//
// Created by alexandru on 11.04.2022.
//

#ifndef P3_DOUBLELINKEDLIST_H
#define P3_DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
template<class T>
class DoubleLinkedList {
    Node<T> *cap;
public:
    DoubleLinkedList() {
        cap = nullptr;
    }
    ~DoubleLinkedList() {
        Node<T> *it = cap;
        while(it != nullptr) {
            Node<T> *aux = it;
            it = it -> next;
            delete aux;
        }
    }
    int GetCount() {
        int cnt = 0;
        Node<T> *it = cap;
        while(it != nullptr) {
            it = it -> next;
            cnt++;
        }
        return cnt;
    }
    void PushOnFront(const T& value) {
        Node<T> *InsertedNode = new Node<T> (value);
        if(cap == nullptr) {
            cap = InsertedNode;
        } else {
            InsertedNode -> next = cap;
            cap -> pred = InsertedNode;
            cap = InsertedNode;
        }
    }
    void PushOnBack(const T& value) {
        Node<T> *InsertedNode = new Node<T> (value);
        if(cap == nullptr) {
            cap = InsertedNode;
        } else {
            Node<T> *it = cap;
            while(it -> next != nullptr) {
                it = it -> next;
            }
            it -> next = InsertedNode;
            InsertedNode -> pred = it;
        }
    }
    T PopFromBack() {
        Node<T> *it = cap;
        if(it != nullptr) {
            while(it -> next != nullptr) {
                it = it -> next;
            }
            if(it == cap) {
                T aux = it -> value;
                delete it;
                cap = nullptr;
                return aux;
            }
            Node<T> *newLast = it -> pred;
            newLast -> next = nullptr;
            it -> pred = nullptr;
            T aux = it -> value;
            delete it;
            return aux;
        }
    }
    void PrintAll(void(*func)(const T&)) {
        Node<T> *it = cap;
        printf("Elements: %d => ", GetCount());
        while(it != nullptr) {
            func(it -> value);
            it = it -> next;
        }
        std::cout << '\n';
    }
};

#endif //P3_DOUBLELINKEDLIST_H
