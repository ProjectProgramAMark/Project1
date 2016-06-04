#ifndef PROJECT1_CYCLICLINKEDLIST_H
#define PROJECT1_CYCLICLINKEDLIST_H
#include "SingleNode.h"

template<class Type> class CyclicLinkedList {
private:
    SingleNode<Type> * head;
    SingleNode<Type> * tail;

    int size;

public:
    CyclicLinkedList(){                            //Creates linked list setting pointers to null and size to 0
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~CyclicLinkedList() {
        SingleNode<Type> * tmp = head;


        if(head){
            while(tmp->next != head){           //Traverses linked list deleting every node after head
                SingleNode<Type> * t = tmp;
                tmp = tmp->next;
                delete(t);
                size--;
            }
        }
        delete tmp;                             //Deletes head node
        size--;
        head = NULL;                            //Sets head node to NULL
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

    Type front() const {
        try {
            if (empty()) { throw 404; }
            cout << head->getData() << endl;
            return head->getData();
        }
        catch (int x) { cout << "Error " << x << endl; }
    };// retrieve object stored in head

    Type back() const { try {
            if (empty()) { throw 404; }
            cout << tail->getData() << endl;
            return tail->getData();
        }
        catch (int x) { cout << "Error " << x << endl; }
    };//retrieve object stored in tail

    SingleNode<Type> * getHead() const { cout << head << endl; return head; }; // returns the head pointer

    SingleNode<Type> * getTail() const { cout << tail << endl; return tail; }; //returns the tail pointer

    int getCount(Type const & arg) const {
        int count = 0;
        SingleNode<Type> * ptr = head;

        while(ptr != tail){                               //Traverses linked list starting at head and counts
            if(ptr->data == arg){                         //number of times arg is found in list. Loop ends at node
                count++;                                  //before tail
            }
            ptr = ptr->next;
        }
        if(tail->data == arg)                             //Checks is tail node data equals arg and counts
            count++;
        cout << count << endl;
        return count;
    }; // returns number of nodes in a linked list equal to arg



    void push_front(Type const & newNodeValue){
        SingleNode<Type> * newNode = new SingleNode<Type>(newNodeValue, head); //creates node that points to head
        SingleNode<Type> * current = head;
        size++;
        if(size == 1) {                                         //if this is the first node in the linked list
            head = newNode;                                     //head is the newNode, newNode points to self and
            newNode->next = newNode;                            //tail = head because of lists cyclcal nature
            tail = head;
        } else {
            //Find out the last node using a loop.
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
            head = newNode;                         //same implementation as push_front
            newNode->next = newNode;
            tail = head;
        } else {
            while(current->next != head) {          //traverses to end of the list
                cout << current->getData() << endl;
                current = current->next;
            }
            newNode->next = head;                   //newNode will point to head and the
            current->next = newNode;                //previous last element will point to newNode
            tail = newNode;
        }
    }; // add node to back of list, tail = newNode

    SingleNode<Type> * pop_front(){
        try {
            if (empty()) { throw 404; }
            SingleNode<Type> *temp = head;              //stores node to be deleted in temp
            head = head->next;
            delete temp;
            tail->next = head;
            size--;
            return head;
        }
        catch(int x){cout << "Error " << x << endl;}
    }; // delete front node, returns object stored in node being popped

    int erase(Type const & arg){
        int beginningSize = size;
        SingleNode<Type> *cur = NULL;
        SingleNode<Type> *prev = NULL;

        if(head->data == arg){
            pop_front();
        }

        cur = head->next;
        prev = head;

        while(cur != head){                         //Traverse linked list to end
            if(cur->data == arg){
                prev->next = cur->next;             //prev points to cur->next so cur is no longer needed for link

                if(cur == tail){
                    tail = prev;                    //checks if cur is tail; if it is the prev->next points to head
                }                                   //and tail only needs to equal prev

                delete cur;
                size--;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        // Check if the size isn't the same, which means the element wasn't found
        if(beginningSize == size) {
            cout << "Element was not found! Sorry bub" << endl;
        }
        cout << size << endl;
        return size;
    }; // delete nodes in linked list equal to arg

    void printList(){

        SingleNode<Type> * ptr = head;
        if(ptr != nullptr) {                            //checks if list is empty
            do {
                cout << ptr->getData() << " -> ";       //traverses list to end, printing head first
                ptr = ptr->next;
            } while(ptr != head);
            cout << endl;
        }
    }

};


#endif //PROJECT1_CYCLICLINKEDLIST_H
