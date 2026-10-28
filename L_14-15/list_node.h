#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "television.h"

class ListNode {
public:
    Television data;
    ListNode* next;

    ListNode();
    explicit ListNode(const Television& value);
    ~ListNode();
};

#endif
