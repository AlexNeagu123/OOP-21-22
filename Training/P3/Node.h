//
// Created by alexandru on 11.04.2022.
//

#ifndef P3_NODE_H
#define P3_NODE_H

template<class T>
struct Node {
    Node *next, *pred;
    T value;
    Node(T _val) {
        value = _val;
        next = pred = nullptr;
    }
};

#endif //P3_NODE_H
