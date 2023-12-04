#ifndef EASYTRIP_NODE_H
#define EASYTRIP_NODE_H


template<class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    // Constructor
    Node(T data);


    // Setter methods
    void setData(T data);

    void setNext(Node<T> *next);

    // Getter methods
    T getData() const;

    Node<T> *getNext() const;
};

#include "Node.impl"

#endif //EASYTRIP_NODE_H
