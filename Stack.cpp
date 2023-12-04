#include "Stack.h"
#include "Node.h"

template<class T>
Stack<T>::Stack() : top(nullptr) {}

template<class T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template<class T>
void Stack<T>::push(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(top);
    top = newNode;
}

template<class T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node<T> *temp = top;
    top = top->getNext();
    delete temp;
}

template<class T>
T Stack<T>::topElement() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty" << std::endl;
        return T(); // Return default-constructed T if the stack is empty
    }
    return top->getData();
}

template<class T>
void Stack<T>::printStack() const {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    Node<T> *temp = top;
    while (temp != nullptr) {
        std::cout << temp->getData();
        if (temp->getNext() != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->getNext();
    }
    std::cout << "end" << std::endl;
}
