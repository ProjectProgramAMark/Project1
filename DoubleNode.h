#ifndef PROJECT1_DOUBLENODE_H
#define PROJECT1_DOUBLENODE_H
#include <iostream>
using namespace std;

template <class Type> class DoubleNode {
private:
    Type data;
    DoubleNode<Type> * next;
    DoubleNode<Type> * previous;

public:
    DoubleNode<Type>(Type const &data, DoubleNode * next, DoubleNode * previous){
        this->data = data;
        this->next = next;
        this->previous = previous;
    };
    ~DoubleNode<Type>(){};

    Type getData() const { return data; };

    DoubleNode<Type> * getNext() const { return next; };

    DoubleNode<Type> * getPrev() const { return previous; };

    template <typename T>
    friend class DoublyLinkedList;
};

#endif //PROJECT1_DOUBLENODE_H
