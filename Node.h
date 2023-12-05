#ifndef EASYTRIP_NODE_H
#define EASYTRIP_NODE_H


template<class T>
class Node {
private:
    T data;
    int priority;
    Node<T> *next;

public:
    // Constructor
    Node(T data, int priority);
    Node(T data);


    // Setter methods
    void setData(T data);
    void setPriority(int priority);

    void setNext(Node<T> *next);

    // Getter methods
    T getData() const;

    Node<T> *getNext() const;

    Node<T> *getPriority() const;
};

#include "Node.impl"

#endif //EASYTRIP_NODE_H
