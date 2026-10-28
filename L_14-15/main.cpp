#include <iostream>
#include "television.h"
#include "singly_list.h"

using namespace std;

int main() {
    cout << "=== Лаб. №14-15, варіант 13: Однозв'язний список (Телевізор) ===\n\n";

    SinglyList list;

    cout << "1. Перевірка порожнього списку:\n";
    cout << "isEmpty() = " << (list.isEmpty() ? "так" : "ні") << "\n";
    cout << "size() = " << list.size() << "\n\n";

    cout << "2. Додавання елементів:\n";
    Television a(55.0, "3840x2160", true);
    Television b(43.0, "1920x1080", false);
    Television c(32.0, "2560x1440", true);
    Television d(65.0, "3840x2160", true);
    Television e(50.0, "1920x1080", false);

    cout << "\n2a. Введення одного об'єкта з клавіатури (Television::inputData):\n";
    Television fromKeyboard;
    fromKeyboard.inputData();
    cout << "Введено: " << fromKeyboard << "\n";

    list.pushBack(a);
    list.pushBack(b);
    list.pushFront(c);
    list.pushBack(d);
    list.pushBack(fromKeyboard);
    cout << "\n";

    cout << "3. Вставка після елемента:\n";
    list.insertAfter(a, e);
    cout << "\n";

    cout << "4. Прямий вивід:\n";
    list.displayForward();
    cout << "Кількість елементів: " << list.size() << "\n\n";

    cout << "5. Зворотний вивід (рекурсія — у однозв'язному немає prev):\n";
    list.displayBackward();
    cout << "\n";

    cout << "6. Видалення з початку:\n";
    list.popFront();
    list.displayForward();
    cout << "\n";

    cout << "7. Видалення з кінця:\n";
    list.popBack();
    list.displayForward();
    cout << "\n";

    cout << "8. Видалення за значенням:\n";
    list.removeByValue(b);
    list.displayForward();
    cout << "\n";

    cout << "9. Спроба видалити неіснуючий елемент:\n";
    Television missing(99.0, "800x600", false);
    list.removeByValue(missing);
    cout << "\n";

    cout << "10. Фінальний стан:\n";
    cout << "isEmpty() = " << (list.isEmpty() ? "так" : "ні") << "\n";
    cout << "size() = " << list.size() << "\n";
    list.displayForward();
    list.displayBackward();

    return 0;
}
