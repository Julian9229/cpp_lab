#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "stack.h"

const int STACK_ARRAY_SIZE = 8;

class StackArray {
private:
    Stack stacks[STACK_ARRAY_SIZE];
    int count;

public:
    StackArray();
    ~StackArray();

    void add(const Stack& st);
    int size() const;

    Stack& operator[](int index);
    const Stack& operator[](int index) const;

    void selectionSortBySizeDesc();
    Stack mergeAll() const;
    void displayAll() const;
};

#endif
