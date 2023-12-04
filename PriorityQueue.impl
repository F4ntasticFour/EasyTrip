#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue() : front(nullptr) {}

template<class T>
bool PriorityQueue<T>::isEmpty() const {
    return front == nullptr;
}

template<class T>
void PriorityQueue<T>::enqueue(T data, int priority) {
    Node<T> *temp = new Node<T>(data, priority);

    if (isEmpty() || front->getPriority() > priority) {
        temp->setNext(front);
        front = temp;
    } else {
        Node<T> *current = front;
        while (current->getNext() != nullptr && current->getNext()->getPriority() <= priority) {
            current = current->getNext();
        }
        temp->setNext(current->getNext());
        current->setNext(temp);
    }
}

template<class T>
void PriorityQueue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty" << std::endl;
        return;
    }
    Node<T> *temp = front;
    front = front->getNext();
    delete temp;
}

template<class T>
T PriorityQueue<T>::frontElement() const {
    if (isEmpty()) {
        std::cerr << "Priority Queue is empty" << std::endl;
        return T(); // Return default-constructed T if the queue is empty
    }
    return front->getData();
}

template<class T>
void PriorityQueue<T>::printPriorityQueue() const {
    if (isEmpty()) {
        std::cout << "Priority Queue is empty" << std::endl;
        return;
    }
    Node<T> *temp = front;
    while (temp != nullptr) {
        std::cout << "(" << temp->getData() << ", " << temp->getPriority() << ") ";
        temp = temp->getNext();
    }
    std::cout << std::endl;
}

