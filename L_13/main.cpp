#include <iostream>
#include "television.h"
#include "home_television.h"
#include "office_television.h"
#include "tv_catalog.h"
#include "tv_exception.h"

using namespace std;

void showByRef(Television& tv) {
    cout << "Віртуальний виклик: ";
    tv.display();
}

int main() {
    cout << "=== Лаб. №13, варіант 13: Файли та винятки (Телевізор) ===\n\n";

    const string filename = "televisions.txt";
    TelevisionCatalog catalog;

    try {
        cout << "1. Створення об'єктів (дочірні класи):\n";
        HomeTelevision home(55.0, "3840x2160", true, "вітальня");
        OfficeTelevision office(43.0, "1920x1080", false, 3);
        HomeTelevision bedroom(32.0, "2560x1440", true, "спальня");

        cout << "\n1a. Введення одного об'єкта з клавіатури (HomeTelevision::inputData):\n";
        HomeTelevision fromKeyboard;
        fromKeyboard.inputData();
        cout << "Введено: ";
        fromKeyboard.display();

        cout << "\n2. Віртуальний вивід через базове посилання:\n";
        showByRef(home);
        showByRef(office);

        cout << "\n3. Перевантаження операторів:\n";
        cout << "home: " << home << "\n";
        cout << "office: " << office << "\n";
        cout << "home == office ? " << (home == office ? "так" : "ні") << "\n";
        cout << "office < home ? " << (office < home ? "так" : "ні") << "\n";
        Television combined = home + office;
        cout << "home + office = " << combined << "\n";

        cout << "\n4. Каталог (vector структур):\n";
        catalog.add(home, "кімната=" + home.getRoom());
        catalog.add(office, "поверх=" + to_string(office.getFloor()));
        catalog.add(bedroom, "кімната=" + bedroom.getRoom());
        catalog.add(fromKeyboard, "кімната=" + fromKeyboard.getRoom());
        catalog.displayAll();

        cout << "\n5. Запис у файл (fstream):\n";
        catalog.saveToFile(filename);
        cout << "Збережено у " << filename << "\n";

        cout << "\n6. Читання з файлу (fstream):\n";
        TelevisionCatalog loaded;
        loaded.loadFromFile(filename);
        cout << "Завантажено записів: " << loaded.size() << "\n";
        loaded.displayAll();

        cout << "\n7. Результат обчислення:\n";
        cout << "Кількість записів: " << loaded.size() << "\n";
        cout << "Сума діагоналей: " << loaded.totalDiagonal() << "\"\n";
        cout << "Перший запис через []: тип=" << loaded[0].type
             << ", діагональ=" << loaded[0].screenDiagonal << "\"\n";

        cout << "\n8. Перевірка винятків валідації:\n";
        try {
            home.setScreenDiagonal(5.0);
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        try {
            office.setResolution("");
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        try {
            loaded[100];
        } catch (const ValidationException& ex) {
            cout << "Спіймано ValidationException: " << ex.what() << "\n";
        }

        cout << "\n9. Перевірка винятку файлу:\n";
        try {
            TelevisionCatalog missing;
            missing.loadFromFile("no_such_file.txt");
        } catch (const FileException& ex) {
            cout << "Спіймано FileException: " << ex.what() << "\n";
        }

    } catch (const TelevisionException& ex) {
        cerr << "TelevisionException: " << ex.what() << "\n";
    } catch (...) {
        cerr << "Невідомий виняток!\n";
    }

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
