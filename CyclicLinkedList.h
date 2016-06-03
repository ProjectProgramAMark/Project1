#ifndef PROJECT1_CYCLICLINKEDLIST_H
#define PROJECT1_CYCLICLINKEDLIST_H
#include "SingleNode.h"

template<class Type> class CyclicLinkedList {
private:
    SingleNode<Type> * head;
    SingleNode<Type> * tail;

    int size;

public:
    CyclicLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~CyclicLinkedList(){
        SingleNode<Type> * tmp = head;


        if(head){
            while(tmp->next != head){
                SingleNode<Type> * t = tmp;
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

    SingleNode<Type> * getHead() const { cout << head << endl; return head; }; // returns the head pointer

    SingleNode<Type> * getTail() const { cout << tail << endl; return tail; }; //returns the tail pointer

    int getCount(Type const & arg) const {
        int count = 0;
        SingleNode<Type> * ptr = head;

        while(ptr != tail){
            if(ptr->data == arg){
                count++;
            }
        }
        if(tail->data == arg)
            count++;
        cout << count << endl;
        return count; }; // returns number of nodes in a linked list equal to arg



    void push_front(Type const & newNodeValue){
        SingleNode<Type> * newNode = new SingleNode<Type>(newNodeValue, head);
        SingleNode<Type> * current = head;
        size++;
        if(size == 1) {
            head = newNode;
            newNode->next = newNode;
            tail = head;
        } else {
            //(a) Find out the last node using a loop.
            while(current->next != head) {
                cout << current->getData() << endl;
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }

    }; // add node to front of linked list head = newNode

    void push_back(Type const & newNodeValue){
        SingleNode<Type> * newNode = new SingleNode<Type>(newNodeValue, head);
        SingleNode<Type> * current = head;
        size++;
        if(size == 1) {
            head = newNode;
            newNode->next = newNode;
            tail = head;
        } else {
            while(current->next != head) {
                cout << current->getData() << endl;
                current = current->next;
            }
            newNode->next = head;
            current->next = newNode;
            tail = newNode;
        }
    }; // add node to back of list, tail = newNode

    SingleNode<Type> * pop_front(){
        SingleNode<Type> *temp = head;
        head = head->next;
        delete temp;
        tail->next = head;
    }; // delete front node, returns object stored in node being popped

    int erase(Type const & arg){
        SingleNode<Type> * ptr = head;

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

        SingleNode<Type> * ptr = head;
        if(ptr != nullptr) {
            do {
                cout << ptr->getData() << " -> ";
                ptr = ptr->next;
            } while(ptr != head);
            cout << endl;
        }
    }

};


#endif //PROJECT1_CYCLICLINKEDLIST_H
