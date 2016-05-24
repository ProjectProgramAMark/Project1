#include "SingleNode.h"

template<typename Type>
SingleNode::SingleNode(Type const &value, SingleNode *nextNode)
        : data(value), next(nextNode)
{ };

template<typename Type>
SingleNode::~SingleNode() { };

template<typename Type>
Type SingleNode::getData() const {
    return data;
};

template<typename Type>
SingleNode* SingleNode::getNext() const {
    return next;
};