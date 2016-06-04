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
            while(tmp->next != NULL){
                DoubleNode<Type> * t = tmp;
                tmp = tmp->next;
                tmp->previous = NULL;
                delete(t);
                size--;
            }
        }
        delete tmp;
        size--;
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

    Type front() const { try {
            if (size == 0) { throw 404; }
            cout << head->getData() << endl;
            return head->getData();
        }
        catch (int x) { cout << "Error " << x << " List is Empty." << endl; }
    };// retrieve object stored in head

    Type back() const { try {
            if (size == 0) { throw 404; }
            cout << tail->getData() << endl;
            return tail->getData();
        }
        catch (int x) { cout << "Error " << x << " List is Empty." << endl; }
    }; //retrieve object stored in tail

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
            newNode->previous = nullptr;
            head->previous = newNode;
            head = newNode;
        }
    }; // add node to front of linked list head = newNode

    void push_back(Type const & newNodeValue){
        DoubleNode<Type> * newNode = new DoubleNode<Type>(newNodeValue, nullptr, nullptr);
        size++;
        if(size == 1) {
            newNode->next = head;
            head = newNode;
            tail = newNode;
            head->previous = nullptr;
            tail->previous = nullptr;
            cout << "this was the first node" << endl;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }; // add node to back of list, tail = newNode

    DoubleNode<Type> * pop_front(){
        try {
            if(size == 0){ throw 404;}
            DoubleNode<Type> *temp = head;
            head = head->next;
            delete temp;
            head->previous = nullptr;
            size--;
            return head;

        }
        catch(int x){ cout << "Error " << x << " List is Empty." << endl;}
    }; // delete front node, returns object stored in node being popped

    int erase(Type const & arg){
        int beginningSize = size;
        DoubleNode<Type> * cur = NULL;
        DoubleNode<Type> *  prev = NULL;

        if(head->data == arg) {
            pop_front();
        }

        cur = head->next;
        prev = head;

        while(cur != NULL){
            if(cur->data == arg){
                if(cur->next == NULL){
                    prev->next = NULL;
                    tail = prev;
                } else {
                    prev->next = cur->next;
                    prev  = cur->next->previous;
                }



                delete cur;
                size--;
                break;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        if(beginningSize == size){
            cout << "Element was not found!" << endl;
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
