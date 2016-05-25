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

int CyclicLinkedList::getSize() const {
    return size;
}

bool CyclicLinkedList::empty() const {
    return size == 0;
}

template<typename Type>
Type CyclicLinkedList::front() const {
    return head;
}

template<typename Type>
Type CyclicLinkedList::back() const {
    return tail;
}

template<typename Type>
SingleNode<Type>* CyclicLinkedList::getHead() const {
    return head->data;
}

template<typename Type>
SingleNode<Type>* CyclicLinkedList::getTail() const {
    return tail->data;
}

template<typename Type>
int CyclicLinkedList::getCount(Type const &arg) const {
    int count = 0;
    SingleNode * ptr = head;

    while(ptr != tail){
        if(ptr->data == arg){
            count++;
        }
    }
    if(tail->data == arg)
        count++;

    return count;
}

template<typename Type>
void CyclicLinkedList::push_front(Type const &newNode) {
    SingleNode * newPtr = new SingleNode(newNode, head);
    head = newPtr;
    size++;
}

template<typename Type>
void CyclicLinkedList::push_back(Type const &newNode) {
    SingleNode * newPtr = new SingleNode(newNode, head);
    tail->next = newPtr;
    tail = newPtr;
    size++;
}

template<typename Type>
Type CyclicLinkedList::pop_front() {
    SingleNode * ptr = head;
    delete head;
    head = ptr->next;
    return ptr;
}

template<typename Type>
int CyclicLinkedList::erase(Type const &arg) {
    SingleNode * ptr = head;

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
}



