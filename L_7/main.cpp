#include <iostream>
#include "television.h"

using namespace std;

int main() {
    cout << "=== Лаб. №7, варіант 13: Телевізор ===\n\n";

    TelevisionStore store;

    cout << "Вхідні дані (жорстко задані):\n";
    store.addTelevision(32.0, "1920x1080", false);
    store.addTelevision(55.0, "3840x2160", true);
    store.addTelevision(43.0, "2560x1440", true);
    store.addTelevision(65.0, "3840x2160", true);

    cout << "\nВведення одного об'єкта з клавіатури (метод inputTelevision):\n";
    store.inputTelevision();

    cout << "\nУсі записи:\n";
    store.displayAll();

    cout << "\nЗміна запису [1]:\n";
    store.setScreenDiagonal(1, 50.0);
    store.setResolution(1, "2560x1440");
    store.displayAll();

    cout << "\nПеревірка валідації:\n";
    store.addTelevision(5.0, "тест", true);
    store.setResolution(0, "");

    cout << "\nТелевізори зі Smart-TV:\n";
    store.displayBySmartTV(true);

    cout << "\nТелевізори з діагоналлю >= 50\":\n";
    store.displayByMinDiagonal(50.0);

    cout << "\nТелевізори з діагоналлю >= 100\":\n";
    store.displayByMinDiagonal(100.0);

    return 0;
}
