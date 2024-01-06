// Queue.h

#ifndef EASYTRIP_QUEUE_H
#define EASYTRIP_QUEUE_H


#include <iostream>
#include "Node.h"

template<class T>
class Queue {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    // Constructor
    Queue() : front(nullptr), rear(nullptr) {}

    // Queue Operations
    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T> *temp = front;
        front = front->getNext();
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    T frontElement() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
            return T(); // Return default-constructed T if the queue is empty
        }
        return front->getData();
    }

    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        Node<T> *temp = front;
        while (temp != nullptr) {
            std::cout << temp->getData();
            if (temp->getNext() != nullptr) {
                std::cout << " -> ";
            }
            temp = temp->getNext();
        }
        std::cout << "end" << std::endl;
    }
    int getLength() {
        if(front == nullptr && rear == nullptr) {
            return 0;
        }
        int count = 0;
        Node<T> *temp = front;
        while (temp != nullptr) {
            count++;
            temp = temp->getNext();
        }
        return count;
    }
};


#endif //EASYTRIP_QUEUE_H
