#ifndef EASYTRIP_PRIORITYQUEUE_H
#define EASYTRIP_PRIORITYQUEUE_H

#include "Node.h"
#include <iostream>

template<class T>
class PriorityQueue {
private:
    Node<T> *front;

public:
    // Constructor
    PriorityQueue();

    // Priority Queue Operations
    bool isEmpty() const;
    void enqueue(T data, int priority);
    void dequeue();
    T frontElement() const;
    void printPriorityQueue() const;
};

#include "PriorityQueue.cpp"

#endif //EASYTRIP_PRIORITYQUEUE_H
