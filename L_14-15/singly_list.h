#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include "list_node.h"

class SinglyList {
private:
    ListNode* head;
    ListNode* tail;
    int count;

    void displayBackwardRecursive(ListNode* node, int index) const;

public:
    SinglyList();
    ~SinglyList();

    SinglyList(const SinglyList&) = delete;
    SinglyList& operator=(const SinglyList&) = delete;

    bool isEmpty() const;
    int size() const;

    void pushFront(const Television& value);
    void pushBack(const Television& value);
    bool insertAfter(const Television& afterValue, const Television& value);

    bool popFront();
    bool popBack();
    bool removeByValue(const Television& value);

    void displayForward() const;
    void displayBackward() const;

    void clear();
};

#endif
