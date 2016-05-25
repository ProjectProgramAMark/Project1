#ifndef PROJECT01_SINGLENODE_H
#define PROJECT01_SINGLENODE_H
#include <iostream>
using namespace std;

template <class Type> class SingleNode {
private:
    Type data;
    SingleNode * next;

public:
    SingleNode(Type const &data, SingleNode * next){
        this->data = data;
        this->next = next;
    }
    ~SingleNode();

    Type getData() const { return data; };

    SingleNode * getNext() const { return next; };

    friend class CyclicLinkedList;
};


#endif //PROJECT01_SINGLENODE_H
