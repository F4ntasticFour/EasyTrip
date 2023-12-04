//
// Created by Safey Elrahman on 04/12/2023.
//

#include "Node.h"

// Constructor
template<class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

// Setter for data
template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}

// Setter for next
template<class T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}

// Getter for data
template<class T>
T Node<T>::getData() const {
    return data;
}

// Getter for next
template<class T>
Node<T> *Node<T>::getNext() const {
    return next;
}
