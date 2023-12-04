#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() : Head(nullptr) {}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return Head == nullptr;
}

template<class T>
void LinkedList<T>::insertAtBeg(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(Head);
    Head = newNode;
}

template<class T>
void LinkedList<T>::insertAtEnd(T data) {
    Node<T> *newNode = new Node<T>(data);
    if (isEmpty()) {
        Head = newNode;
    } else {
        Node<T> *temp = Head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template<class T>
void LinkedList<T>::insertAtIndex(int index, T data) {
    if (index < 0) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    if (index == 0) {
        insertAtBeg(data);
        return;
    }
    Node<T> *temp = Head;
    for (int i = 0; temp != nullptr && i < index - 1; i++) {
        temp = temp->getNext();
    }
    if (temp == nullptr || temp->getNext() == nullptr) {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(temp->getNext());
    temp->setNext(newNode);
}

template<class T>
void LinkedList<T>::printList() const {
    Node<T> *temp = Head;
    if (isEmpty()) {
        std::cout << "List is Empty" << std::endl;
    } else {
        while (temp != nullptr) {
            std::cout << temp->getData() << " -> ";
            temp = temp->getNext();
        }
        std::cout << "end" << std::endl;
    }
}

template<class T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T> &list1, const LinkedList<T> &list2) {
    LinkedList<T> mergedList;
    Node<T> *temp1 = list1.Head;
    Node<T> *temp2 = list2.Head;
    while (temp1 != nullptr) {
        mergedList.insertAtEnd(temp1->getData());
        temp1 = temp1->getNext();
    }
    while (temp2 != nullptr) {
        mergedList.insertAtEnd(temp2->getData());
        temp2 = temp2->getNext();
    }
    return mergedList;
}

template<class T>
T LinkedList<T>::getItem() const {
    Node<T> *temp = Head;
    while (temp != nullptr && temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    return temp != nullptr ? temp->getData() : T();
}
