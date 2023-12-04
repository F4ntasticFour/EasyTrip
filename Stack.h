#ifndef EASYTRIP_STACK_H
#define EASYTRIP_STACK_H

#include "Node.h"
#include <iostream>

template<class T>
class Stack {
private:
    Node<T> *top;

public:
    // Constructor
    Stack();

    // Stack Operations
    bool isEmpty() const;

    void push(T data);

    void pop();

    T topElement() const;

    void printStack() const;
};

#include "Stack.cpp"

#endif //EASYTRIP_STACK_H
