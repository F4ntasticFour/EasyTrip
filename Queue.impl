#include "Queue.h"

template<class T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template<class T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template<class T>
void Queue<T>::Enqueue(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->setNext(newNode);
        rear = newNode;
    }
}

template<class T>
void Queue<T>::Dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node<T> *temp = front;
    front = front->getNext();
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

template<class T>
T Queue<T>::frontElement() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty" << std::endl;
        return T(); // Return default-constructed T if the queue is empty
    }
    return front->getData();
}

template<class T>
void Queue<T>::printQueue() const {
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
