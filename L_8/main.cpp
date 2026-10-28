#include <iostream>
#include "television.h"

using namespace std;

int main() {
    cout << "=== Лаб. №8, варіант 13: Телевізор (vector) ===\n\n";

    TelevisionStore store;

    cout << "1. Додавання (push_back):\n";
    store.addTelevision(32.0, "1920x1080", false);
    store.addTelevision(55.0, "3840x2160", true);
    store.addTelevision(43.0, "2560x1440", true);
    store.displayAll();

    cout << "\n1a. Введення одного об'єкта з клавіатури (метод inputTelevision):\n";
    store.inputTelevision();
    store.displayAll();

    cout << "\n2. Вставка на позицію 1:\n";
    store.insertTelevision(1, 50.0, "2560x1440", true);
    store.displayAll();

    cout << "\n3. Обмін елементів [0] і [2]:\n";
    store.swapTelevisions(0, 2);
    store.displayAll();

    cout << "\n4. Видалення елемента [1]:\n";
    store.removeTelevision(1);
    store.displayAll();

    cout << "\n5. Зміна полів і валідація:\n";
    store.setScreenDiagonal(0, 65.0);
    store.setResolution(0, "");
    store.addTelevision(5.0, "тест", true);
    store.displayAll();

    cout << "\n6. Телевізори зі Smart-TV:\n";
    store.displayBySmartTV(true);

    cout << "\n7. Очищення:\n";
    store.clearAll();
    store.displayAll();

    return 0;
}
