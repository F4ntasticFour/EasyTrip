//
// Created by Safey Elrahman on 13/12/2023.
//


#ifndef EASYTRIP_NODEP_H
#define EASYTRIP_NODEP_H

template<class T>
class NodeP {
private:
    T data;
    int priority{};
    NodeP<T> *next;

public:
    // Constructor
    NodeP(T data, int priority);

    // Setter methods
    void setData(T data);
    void setPriority(int priority);
    void setNext(NodeP<T> *next);

    // Getter methods
    T getData() const;
    NodeP<T> *getNext();
    int getPriority() const;
};

// Constructor

template<class T>
NodeP<T>::NodeP(T data, int priority) : data(data), priority(priority), next(nullptr) {}

// Setter for data
template<class T>
void NodeP<T>::setData(T data) {
    this->data = data;
}

template<class T>
void NodeP<T>::setPriority(int priority) {
    this->priority = priority;
}

// Setter for next
template<class T>
void NodeP<T>::setNext(NodeP<T> *next) {
    this->next = next;
}

// Getter for data
template<class T>
T NodeP<T>::getData() const {
    return data;
}

// Getter for next
template<class T>
NodeP<T> *NodeP<T>::getNext(){
    return next;
}

template<class T>
int NodeP<T>::getPriority() const {
    return priority;
}

#endif //EASYTRIP_NODE_H


