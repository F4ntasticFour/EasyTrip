#ifndef EASYTRIP_NODE_H
#define EASYTRIP_NODE_H

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    // Constructor
    explicit Node(T data);

    // Setter methods
    void setData(T data);
    void setNext(Node<T> *next);

    // Getter methods
    T getData();
    Node<T> *getNext();
};

// Constructor
template<class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}


// Setter for data
template<class T>
void Node<T>::setData(T data) {
    this->data = data;
}


// Setter for next
template<class T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}

// Getter for data
template<class T>
T Node<T>::getData(){
    return data;
}

// Getter for next
template<class T>
Node<T> * Node<T>::getNext(){
    return next;
}



#endif //EASYTRIP_NODE_H
