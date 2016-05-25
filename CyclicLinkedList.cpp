#include "CyclicLinkedList.h"

template<typename Type>
CyclicLinkedList::CyclicLinkedList()
        : head(0), tail(0), size(0)
{ }

CyclicLinkedList::~CyclicLinkedList() {
    SingleNode * tmp = head;


    if(head){
        while(tmp->next != head){
            SingleNode * t = tmp;
            tmp = tmp->next;
            delete(t);
        }
    }
    delete tmp;
    head = NULL;
}