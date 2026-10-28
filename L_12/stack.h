#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;

public:
    Stack();
    ~Stack();

    void push(int value);
    void inputPush();
    int size() const;
    bool empty() const;
    int top() const;
    int at(int index) const; // 0 = дно, size-1 = верх
    void display() const;

    // порівняння за кількістю елементів
    friend bool operator<(const Stack& a, const Stack& b);

    // додавання елемента у стек (повертає новий стек)
    friend Stack operator+(const Stack& st, int value);

    friend std::ostream& operator<<(std::ostream& out, const Stack& st);
};

#endif
