#include <iostream>
#include <utility>
#include "television.h"

using namespace std;

void takeByValue(Television obj) {
    cout << "  всередині takeByValue: ";
    obj.display();
}

Television returnByValue(Television obj) {
    cout << "  всередині returnByValue: ";
    obj.display();
    cout << "  повернення obj з функції...\n";
    return obj;
}

int main() {
    cout << "=== Лаб. №16, варіант 13: Копіювання та переміщення (Телевізор) ===\n\n";

    cout << "1. Конструктор з параметром:\n";
    Television a(55.0, true, "3840x2160", 4);
    a.display();
    cout << "\n";

    cout << "1a. Введення одного об'єкта з клавіатури (Television::inputFromKeyboard):\n";
    Television fromKeyboard = Television::inputFromKeyboard();
    cout << "  введено: ";
    fromKeyboard.display();
    cout << "\n";

    cout << "2. Конструктор копіювання (Television b = a):\n";
    Television b = a;
    cout << "  a: ";
    a.display();
    cout << "  b: ";
    b.display();
    cout << "\n";

    cout << "3. Оператор присвоювання копіюванням (c = a):\n";
    Television c(32.0, false, "1920x1080", 2);
    c = a;
    cout << "  c: ";
    c.display();
    cout << "\n";

    cout << "4. Передача у функцію за значенням (копіювання):\n";
    takeByValue(a);
    cout << "  після виклику a: ";
    a.display();
    cout << "\n";

    cout << "5. Конструктор переміщення (Television d = std::move(b)):\n";
    Television d = std::move(b);
    cout << "  d: ";
    d.display();
    cout << "  b (після move): ";
    b.display();
    cout << "\n";

    cout << "6. Оператор присвоювання переміщенням (c = std::move(d)):\n";
    c = std::move(d);
    cout << "  c: ";
    c.display();
    cout << "  d (після move): ";
    d.display();
    cout << "\n";

    cout << "7. Передача у функцію через std::move:\n";
    takeByValue(std::move(a));
    cout << "  a (після move у функцію): ";
    a.display();
    cout << "\n";

    cout << "8. Повернення з функції (move з параметра):\n";
    Television e = returnByValue(Television(65.0, true, "3840x2160", 3));
    cout << "  e: ";
    e.display();
    cout << "\n";

    cout << "9. Завершення main (деструктори):\n";
    return 0;
}
