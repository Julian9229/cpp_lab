#include "singly_list.h"
#include <iostream>

using namespace std;

SinglyList::SinglyList()
    : head(nullptr), tail(nullptr), count(0) {}

SinglyList::~SinglyList() {
    clear();
}

bool SinglyList::isEmpty() const {
    return head == nullptr;
}

int SinglyList::size() const {
    return count;
}

void SinglyList::pushFront(const Television& value) {
    ListNode* node = new ListNode(value);
    if (isEmpty()) {
        head = tail = node;
    } else {
        node->next = head;
        head = node;
    }
    ++count;
    cout << "Додано на початок: " << value << "\n";
}

void SinglyList::pushBack(const Television& value) {
    ListNode* node = new ListNode(value);
    if (isEmpty()) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    ++count;
    cout << "Додано в кінець: " << value << "\n";
}

bool SinglyList::insertAfter(const Television& afterValue, const Television& value) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->data.equals(afterValue)) {
            ListNode* node = new ListNode(value);
            node->next = current->next;
            current->next = node;
            if (current == tail) {
                tail = node;
            }
            ++count;
            cout << "Вставлено після [" << afterValue << "]: " << value << "\n";
            return true;
        }
        current = current->next;
    }
    cout << "Елемент для вставки після нього не знайдено.\n";
    return false;
}

bool SinglyList::popFront() {
    if (isEmpty()) {
        cout << "Список порожній — неможливо видалити з початку.\n";
        return false;
    }
    ListNode* temp = head;
    cout << "Видалено з початку: " << temp->data << "\n";
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    delete temp;
    --count;
    return true;
}

bool SinglyList::popBack() {
    if (isEmpty()) {
        cout << "Список порожній — неможливо видалити з кінця.\n";
        return false;
    }
    cout << "Видалено з кінця: " << tail->data << "\n";
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        ListNode* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    --count;
    return true;
}

bool SinglyList::removeByValue(const Television& value) {
    if (isEmpty()) {
        cout << "Елемент для видалення не знайдено.\n";
        return false;
    }

    if (head->data.equals(value)) {
        return popFront();
    }

    ListNode* current = head;
    while (current->next != nullptr) {
        if (current->next->data.equals(value)) {
            ListNode* toDelete = current->next;
            cout << "Видалено за значенням: " << toDelete->data << "\n";
            current->next = toDelete->next;
            if (toDelete == tail) {
                tail = current;
            }
            delete toDelete;
            --count;
            return true;
        }
        current = current->next;
    }

    cout << "Елемент для видалення не знайдено.\n";
    return false;
}

void SinglyList::displayForward() const {
    if (isEmpty()) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Прямий вивід (head -> tail):\n";
    ListNode* current = head;
    int i = 1;
    while (current != nullptr) {
        cout << "  " << i << ") " << current->data << "\n";
        current = current->next;
        ++i;
    }
}

void SinglyList::displayBackwardRecursive(ListNode* node, int index) const {
    if (node == nullptr) {
        return;
    }
    displayBackwardRecursive(node->next, index + 1);
    // після рекурсії: спочатку хвіст (index == count), потім до голови (index == 1)
    cout << "  " << index << ") " << node->data << "\n";
}

void SinglyList::displayBackward() const {
    if (isEmpty()) {
        cout << "Список порожній.\n";
        return;
    }
    cout << "Зворотний вивід (рекурсія, tail -> head):\n";
    displayBackwardRecursive(head, 1);
}

void SinglyList::clear() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}
