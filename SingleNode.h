#ifndef PROJECT01_SINGLENODE_H
#define PROJECT01_SINGLENODE_H
#include <iostream>
using namespace std;

template <typename Type>;

class SingleNode {
private:
    Type data;
    SingleNode * next;

public:
    SingleNode(Type const & value, SingleNode * nextNode);
    ~SingleNode();

    Type getData() const;

    SingleNode * getNext() const;

};


#endif //PROJECT01_SINGLENODE_H
