#ifndef EASYTRIP_LINKEDLIST_H
#define EASYTRIP_LINKEDLIST_H

#include "Node.h"
#include <iostream>

template<class T>
class LinkedList {
private:
    Node<T> *Head;

public:
    // Constructor
    LinkedList();

    // Basic Operations
    bool isEmpty() const;

    void insertAtBeg(T data);

    void insertAtEnd(T data);

    void insertAtIndex(int index, T data);

    void printList() const;

    // Advanced Operations
    static LinkedList<T> merge(const LinkedList<T> &list1, const LinkedList<T> &list2);

    // Utility Functions
    T getItem() const;
};

#include "LinkedList.cpp"

#endif //EASYTRIP_LINKEDLIST_H
