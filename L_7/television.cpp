#include "television.h"
#include <iostream>
#include <limits>

using namespace std;

TelevisionStore::TelevisionStore() {
    count = 0;
    for (int i = 0; i < SIZE; i++) {
        televisions[i].screenDiagonal = 0.0;
        televisions[i].resolution = "";
        televisions[i].hasSmartTV = false;
    }
    cout << "Викликано конструктор\n";
}

TelevisionStore::~TelevisionStore() {
    cout << "Викликано деструктор\n";
}

void TelevisionStore::addTelevision(double diagonal, string resolution, bool smart) {
    if (count >= SIZE) {
        cout << "Помилка: масив заповнений (макс. " << SIZE << ")!\n";
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

    televisions[count].screenDiagonal = diagonal;
    televisions[count].resolution = resolution;
    televisions[count].hasSmartTV = smart;
    count++;
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

void TelevisionStore::setScreenDiagonal(int index, double diagonal) {
    if (index < 0 || index >= count) {
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
    if (index < 0 || index >= count) {
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
    if (index < 0 || index >= count) {
        cout << "Помилка: некоректний індекс!\n";
        return;
    }
    televisions.at(index).hasSmartTV = smart;
}

void TelevisionStore::displayAll() const {
    if (count == 0) {
        cout << "Немає даних для виведення.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "[" << i << "] діагональ: " << televisions[i].screenDiagonal << "\""
             << ", роздільна здатність: " << televisions[i].resolution
             << ", Smart-TV: " << (televisions[i].hasSmartTV ? "так" : "ні") << endl;
    }
}

void TelevisionStore::displayBySmartTV(bool smart) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
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

void TelevisionStore::displayByMinDiagonal(double minDiagonal) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (televisions[i].screenDiagonal >= minDiagonal) {
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
