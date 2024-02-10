// Node.cpp
#include "Node.h"

#ifndef NODE_CPP
#define NODE_CPP


template<class T>
Node<T>& Node<T>::operator+=(T a) {
    if(a <= this->value) {
        if(this->left == nullptr) {
            this->left = new Node(a);
        } else {
            *(this->left) += a;
        }
    } else {
        if(this->right == nullptr) {
            this->right = new Node(a);
        } else {
            *(this->right) += a;
        }
    }
    return *this;
}

template<class T>
T Node<T>::minValue() {
    if(this->left == nullptr) {
        return this->value;
    }
    return this->left->minValue();
}
#endif