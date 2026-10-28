#include "television.h"
#include <iostream>
#include <limits>

using namespace std;

TelevisionStore::TelevisionStore() {
    cout << "Викликано конструктор\n";
}

TelevisionStore::~TelevisionStore() {
    cout << "Викликано деструктор\n";
}

void TelevisionStore::addTelevision(double diagonal, string resolution, bool smart) {
    if (diagonal < 10.0 || diagonal > 120.0) {
        cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
        return;
    }
    if (resolution.empty()) {
        cout << "Помилка: роздільна здатність не може бути порожньою!\n";
        return;
    }

    television_s_t item;
    item.screenDiagonal = diagonal;
    item.resolution = resolution;
    item.hasSmartTV = smart;
    televisions.push_back(item);
}

void TelevisionStore::inputTelevision() {
    double diagonal;
    int smartFlag;
    string resolution;

    while (true) {
        cout << "Діагональ екрану (дюйми, 10..120): ";
        if (cin >> diagonal && diagonal >= 10.0 && diagonal <= 120.0) {
            break;
        }
        cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Роздільна здатність (наприклад 3840x2160): ";
        getline(cin, resolution);
        if (!resolution.empty()) {
            break;
        }
        cout << "Помилка: роздільна здатність не може бути порожньою!\n";
    }

    while (true) {
        cout << "Наявність Smart-TV (1 - так, 0 - ні): ";
        if (cin >> smartFlag && (smartFlag == 0 || smartFlag == 1)) {
            break;
        }
        cout << "Помилка: введіть 0 або 1!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    addTelevision(diagonal, resolution, smartFlag == 1);
}

void TelevisionStore::insertTelevision(int index, double diagonal, string resolution, bool smart) {
    if (index < 0 || index > (int)televisions.size()) {
        cout << "Помилка: некоректний індекс для вставки!\n";
        return;
    }
    if (diagonal < 10.0 || diagonal > 120.0) {
        cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
        return;
    }
    if (resolution.empty()) {
        cout << "Помилка: роздільна здатність не може бути порожньою!\n";
        return;
    }

    television_s_t item;
    item.screenDiagonal = diagonal;
    item.resolution = resolution;
    item.hasSmartTV = smart;
    televisions.insert(televisions.begin() + index, item);
}

void TelevisionStore::removeTelevision(int index) {
    if (index < 0 || index >= (int)televisions.size()) {
        cout << "Помилка: некоректний індекс для видалення!\n";
        return;
    }
    televisions.erase(televisions.begin() + index);
}

void TelevisionStore::swapTelevisions(int i, int j) {
    if (i < 0 || j < 0 || i >= (int)televisions.size() || j >= (int)televisions.size()) {
        cout << "Помилка: некоректні індекси для обміну!\n";
        return;
    }
    swap(televisions[i], televisions[j]);
}

void TelevisionStore::clearAll() {
    televisions.clear();
    cout << "Усі записи очищено.\n";
}

void TelevisionStore::setScreenDiagonal(int index, double diagonal) {
    if (index < 0 || index >= (int)televisions.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (diagonal < 10.0 || diagonal > 120.0) {
        cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
        return;
    }
    televisions.at(index).screenDiagonal = diagonal;
}

void TelevisionStore::setResolution(int index, string resolution) {
    if (index < 0 || index >= (int)televisions.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    if (resolution.empty()) {
        cout << "Помилка: роздільна здатність не може бути порожньою!\n";
        return;
    }
    televisions.at(index).resolution = resolution;
}

void TelevisionStore::setHasSmartTV(int index, bool smart) {
    if (index < 0 || index >= (int)televisions.size()) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    televisions.at(index).hasSmartTV = smart;
}

void TelevisionStore::displayAll() const {
    if (televisions.empty()) {
        cout << "Немає даних для виведення.\n";
        return;
    }
    for (size_t i = 0; i < televisions.size(); i++) {
        cout << "[" << i << "] діагональ: " << televisions[i].screenDiagonal << "\""
             << ", роздільна здатність: " << televisions[i].resolution
             << ", Smart-TV: " << (televisions[i].hasSmartTV ? "так" : "ні") << endl;
    }
}

void TelevisionStore::displayBySmartTV(bool smart) const {
    bool found = false;
    for (size_t i = 0; i < televisions.size(); i++) {
        if (televisions[i].hasSmartTV == smart) {
            cout << "[" << i << "] діагональ: " << televisions[i].screenDiagonal << "\""
                 << ", роздільна здатність: " << televisions[i].resolution
                 << ", Smart-TV: " << (televisions[i].hasSmartTV ? "так" : "ні") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Телевізорів з таким критерієм не знайдено.\n";
    }
}
