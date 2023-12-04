//
// Created by Safey Elrahman on 04/12/2023.
//

#ifndef EASYTRIP_QUEUE_H
#define EASYTRIP_QUEUE_H

#include "Node.h"
#include <iostream>

template<class T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    // Constructor
    Queue();

    // Queue Operations
    bool isEmpty() const;

    void Enqueue(T data);

    void Dequeue();

    T frontElement() const;

    void printQueue() const;
};

#include "Queue.impl"

#endif //EASYTRIP_QUEUE_H
