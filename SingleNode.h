#ifndef PROJECT01_SINGLENODE_H
#define PROJECT01_SINGLENODE_H
#include <iostream>
using namespace std;

template <class Type> class SingleNode {
private:
    Type data;
    SingleNode<Type> * next;

public:
    SingleNode<Type>(Type const &data, SingleNode * next){
        this->data = data;
        this->next = next;
    };
    ~SingleNode<Type>(){};

    Type getData() const { return data; };

    SingleNode<Type> * getNext() const { return next; };

    template <typename T>
    friend class CyclicLinkedList;
};


#endif //PROJECT01_SINGLENODE_H
