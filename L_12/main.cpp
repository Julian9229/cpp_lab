#include <iostream>
#include "stack.h"
#include "stack_array.h"

using namespace std;

int main() {
    cout << "=== Лаб. №12: Перевантаження операторів (стек) ===\n\n";

    cout << "1. Створення стеків і оператор + (додавання елемента):\n";
    Stack s1;
    s1 = s1 + 10;
    s1 = s1 + 20;
    s1 = s1 + 30;

    Stack s2;
    s2 = s2 + 1;
    s2 = s2 + 2;

    Stack s3;
    s3 = s3 + 100;
    s3 = s3 + 200;
    s3 = s3 + 300;
    s3 = s3 + 400;
    s3 = s3 + 500;

    Stack s4;
    s4 = s4 + 7;

    cout << "s1 = " << s1 << "\n";
    cout << "s2 = " << s2 << "\n";
    cout << "s3 = " << s3 << "\n";
    cout << "s4 = " << s4 << "\n";

    cout << "\n1a. Введення одного елемента з клавіатури у s4:\n";
    s4.inputPush();
    cout << "s4 = " << s4 << "\n";

    cout << "\n2. Оператор < (порівняння за кількістю елементів):\n";
    cout << "s2 < s1 ? " << (s2 < s1 ? "так" : "ні")
         << " (розміри " << s2.size() << " і " << s1.size() << ")\n";
    cout << "s1 < s3 ? " << (s1 < s3 ? "так" : "ні")
         << " (розміри " << s1.size() << " і " << s3.size() << ")\n";
    cout << "s3 < s2 ? " << (s3 < s2 ? "так" : "ні") << "\n";

    cout << "\n3. Масив стеків (до сортування):\n";
    StackArray arr;
    arr.add(s1);
    arr.add(s2);
    arr.add(s3);
    arr.add(s4);
    arr.displayAll();

    cout << "\n4. Сортування вибором за спаданням кількості елементів:\n";
    arr.selectionSortBySizeDesc();
    arr.displayAll();

    cout << "\n5. Об'єднання елементів усіх стеків масиву в один стек:\n";
    Stack merged = arr.mergeAll();
    cout << "merged = " << merged << "\n";

    cout << "\n6. Доступ через operator[]:\n";
    cout << "arr[0] = " << arr[0] << "\n";
    arr[0] = arr[0] + 999;
    cout << "після arr[0] = arr[0] + 999: " << arr[0] << "\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
