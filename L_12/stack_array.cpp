#include "stack_array.h"
#include <iostream>

using namespace std;

StackArray::StackArray() {
    count = 0;
    cout << "Конструктор StackArray\n";
}

StackArray::~StackArray() {
    cout << "Деструктор StackArray\n";
}

void StackArray::add(const Stack& st) {
    if (count >= STACK_ARRAY_SIZE) {
        cout << "Помилка: масив стеків заповнений!\n";
        return;
    }
    stacks[count] = st;
    count++;
}

int StackArray::size() const {
    return count;
}

Stack& StackArray::operator[](int index) {
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return stacks[0];
    }
    return stacks[index];
}

const Stack& StackArray::operator[](int index) const {
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return stacks[0];
    }
    return stacks[index];
}

void StackArray::selectionSortBySizeDesc() {
    // сортування вибором за спаданням кількості елементів (через operator<)
    for (int i = 0; i < count - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (stacks[maxIndex] < stacks[j]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Stack temp = stacks[i];
            stacks[i] = stacks[maxIndex];
            stacks[maxIndex] = temp;
        }
    }
}

Stack StackArray::mergeAll() const {
    Stack result;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < stacks[i].size(); j++) {
            result = result + stacks[i].at(j);
        }
    }
    return result;
}

void StackArray::displayAll() const {
    if (count == 0) {
        cout << "Масив порожній.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] " << stacks[i] << "\n";
    }
}
