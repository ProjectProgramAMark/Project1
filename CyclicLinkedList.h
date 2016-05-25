#ifndef PROJECT1_CYCLICLINKEDLIST_H
#define PROJECT1_CYCLICLINKEDLIST_H
#include "SingleNode.h
#include "SingleNode.h"

template<typename Type> class CyclicLinkedList {
private:
    SingleNode * head;
    SingleNode * tail;

    int size;

public:
    CyclicLinkedList();
    ~CyclicLinkedList();


    int getSize() const; //returns size

    bool empty() const; // checks to see if linked list is empty

    Type front() const; // retrieve object stored in head

    Type back() const; //retrieve object stored in tail

    SingleNode<Type> * getHead() const; // returns the head pointer

    SingleNode<Type> * getTail() const; //returns the tail pointer

    int getCount(Type const & arg) const; // returns number of nodes in a linked list equal to arg



    void push_front(Type const & newNode); // add node to front of linked list head = newNode

    void push_back(Type const & newNode); // add node to back of list, tail = newNode

    Type pop_front(); // delete front node, returns object stored in node being popped

    int erase(Type const & arg); // delete nodes in linked list equal to arg




};


#endif //PROJECT1_CYCLICLINKEDLIST_H
