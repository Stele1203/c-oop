//
// Created by User on 2/11/2024.
//

#ifndef NODE_GENERICKA_NODE_H
#define NODE_GENERICKA_NODE_H

template<class T>

class Node {
private:
    T value;
    Node* left;
    Node* right;
public:
    Node(T value):value(value),left(0),right(0){};

    Node<T>& operator+=(T a);

    T minValue();
};

#include "Node.cpp"
#endif //NODE_GENERICKA_NODE_H
