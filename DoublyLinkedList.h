#ifndef PROJECT1_DOUBLYLINKEDLIST_H
#define PROJECT1_DOUBLYLINKEDLIST_H
#include "DoubleNode.h"

template<class Type> class DoublyLinkedList {
private:
    DoubleNode<Type> * head;
    DoubleNode<Type> * tail;

    int size;

public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~DoublyLinkedList(){
        DoubleNode<Type> * tmp = head;


        if(head){
            while(tmp->next != head){
                DoubleNode<Type> * t = tmp;
                tmp = tmp->next;
                delete(t);
            }
        }
        delete tmp;
        head = NULL;
    };


    int getSize() const { cout << size << endl; return size; }; //returns size

    bool empty() const { if (size == 0){
            cout << "List Is Empty" << endl;
            return true;
        }
        else{
            cout << "List Is Not Empty" << endl;
            return false;
        }
    }; // checks to see if linked list is empty

    Type front() const { cout << head->getData() << endl; return head->getData(); };// retrieve object stored in head

    Type back() const { cout << tail->getData() << endl; return tail->getData(); }; //retrieve object stored in tail

    DoubleNode<Type> * getHead() const { cout << head << endl; return head; }; // returns the head pointer

    DoubleNode<Type> * getTail() const { cout << tail << endl; return tail; }; //returns the tail pointer

    int getCount(Type const & arg) const {
        int count = 0;
        DoubleNode<Type> * ptr = head;

        while(ptr != tail){
            if(ptr->data == arg){
                count++;
            }
            ptr = ptr->next;
        }
        if(tail->data == arg)
            count++;
        cout << count << endl;
        return count;
    }; // returns number of nodes in a linked list equal to arg



    void push_front(Type const & newNodeValue){
        DoubleNode<Type> * newNode = new DoubleNode<Type>(newNodeValue, nullptr, nullptr);
        size++;
        if(size == 1) {
            newNode->next = head;
            head = newNode;
            tail = newNode;
            head->previous = nullptr;
            tail->previous = nullptr;
            cout << "this was the first node" << endl;
        }
        else {
            newNode->next = head;
            newNode->previous = NULL;
            head->previous = newNode;
            head = newNode;
        }
    }; // add node to front of linked list head = newNode

    void push_back(Type const & newNode){
        DoubleNode<Type> * newPtr = new  DoubleNode<Type>(newNode, nullptr, nullptr);
        tail->next = newPtr;
        tail = newPtr;
        size++;
    }; // add node to back of list, tail = newNode

    SingleNode<Type> * pop_front(){
        DoubleNode<Type> *temp = head;
        head = head->next;
        delete temp;
        head->previous = NULL;
        size--;
    }; // delete front node, returns object stored in node being popped

    int erase(Type const & arg){
        DoubleNode<Type> * ptr = head;

        while(ptr != nullptr){
            if(head && ptr->data == arg){
                head = ptr->next;
                delete ptr;
                ptr = head;
                size--;
            }
            else if(ptr->data == arg){
                delete ptr;
                ptr = ptr->next;
                size--;
            }
            ptr = ptr->next;
        }
        cout << size << endl;
        return size;
    }; // delete nodes in linked list equal to arg

    void printList(){

        DoubleNode<Type> * ptr = head;
        while(ptr != nullptr){
            cout << ptr->data << " -> " ;
            ptr = ptr->next;
        }
        cout << endl;
    }

};

#endif //PROJECT1_DOUBLYLINKEDLIST_H
