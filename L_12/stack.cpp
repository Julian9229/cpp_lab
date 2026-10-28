#include "stack.h"
#include <limits>

using namespace std;

Stack::Stack() {
}

Stack::~Stack() {
}

void Stack::push(int value) {
    data.push_back(value);
}

void Stack::inputPush() {
    int value;
    while (true) {
        cout << "Елемент стеку (ціле число): ";
        if (cin >> value) {
            push(value);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cout << "Помилка: введіть ціле число!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int Stack::size() const {
    return (int)data.size();
}

bool Stack::empty() const {
    return data.empty();
}

int Stack::top() const {
    if (data.empty()) {
        cout << "Помилка: стек порожній!\n";
        return 0;
    }
    return data.back();
}

int Stack::at(int index) const {
    if (index < 0 || index >= (int)data.size()) {
        cout << "Помилка: некоректний індекс елемента стеку!\n";
        return 0;
    }
    return data[index];
}

void Stack::display() const {
    cout << *this;
}

bool operator<(const Stack& a, const Stack& b) {
    return a.data.size() < b.data.size();
}

Stack operator+(const Stack& st, int value) {
    Stack result = st;
    result.push(value);
    return result;
}

ostream& operator<<(ostream& out, const Stack& st) {
    out << "розмір=" << st.data.size() << ", елементи (дно -> верх): [";
    for (size_t i = 0; i < st.data.size(); i++) {
        out << st.data[i];
        if (i + 1 < st.data.size()) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
