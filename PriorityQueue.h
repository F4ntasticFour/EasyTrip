#ifndef EASYTRIP_PRIORITYQUEUE_H
#define EASYTRIP_PRIORITYQUEUE_H

#include "NodeP.h"
#include <iostream>

template<class T>
class PriorityQueue {
protected:
    NodeP<T>* front;

public:
    // Constructor
    PriorityQueue() : front(nullptr) {
    }

    // Priority Queue Operations
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T data, int priority) {
        NodeP<T>* newNode = new NodeP<T>(data, priority);
        if (front== nullptr) {
            front = newNode;
        }
        else {
            NodeP<T>* temp = front;
            NodeP<T>* prev = nullptr;
            while (temp != nullptr && temp->getPriority() <= priority) {
                prev = temp;
                temp = temp->getNext();
            }
            if (prev == nullptr) {
                newNode->setNext(front);
                front = newNode;
            }
            else {
                prev->setNext(newNode);
                newNode->setNext(temp);
            }
        }
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Priority Queue is empty" << std::endl;
            return;
        }
        NodeP<T>* temp = front;
        front = front->getNext();
    }

    T frontElement() const {
        if (front == nullptr) {
            std::cerr << "Priority Queue is empty" << std::endl;
            return T(); // Return default-constructed T if the queue is empty
        }
        return front->getData();
    }

    void printPriorityQueue() const {
        if (front == nullptr) {
            std::cout << "Priority Queue is empty" << std::endl;
        }
        else{
            NodeP<T>* temp = front;
            while (temp != nullptr) {
                std::cout << "(" << temp->getData() << ", " << temp->getPriority() << ") ";
                temp = temp->getNext();
            }
            std::cout << std::endl;
        }
    }

    int size() const {
        if(front == nullptr) {
            return 0;
        }
        else{
            int count = 0;
            NodeP<T>* temp = front;
            while (temp != nullptr) {
                count++;
                temp = temp->getNext();
            }
            return count;
        }

    }



};

#endif //EASYTRIP_PRIORITYQUEUE_H
