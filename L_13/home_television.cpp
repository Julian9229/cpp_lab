#include "home_television.h"
#include "tv_exception.h"
#include <iostream>
#include <limits>

using namespace std;

HomeTelevision::HomeTelevision()
    : Television(), room("вітальня") {}

HomeTelevision::HomeTelevision(double diagonal, const string& resolution, bool smart,
                               const string& room)
    : Television(diagonal, resolution, smart), room("вітальня") {
    setRoom(room);
}

HomeTelevision::~HomeTelevision() {}

void HomeTelevision::setRoom(const string& r) {
    if (r.empty()) {
        throw ValidationException("кімната не може бути порожньою");
    }
    room = r;
}

string HomeTelevision::getRoom() const {
    return room;
}

void HomeTelevision::inputData() {
    double diagonal;
    int smartFlag;
    string resolution;
    string r;

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Кімната (можна кілька слів): ";
        getline(cin, r);
        if (!r.empty()) {
            break;
        }
        cout << "Помилка: кімната не може бути порожньою!\n";
    }

    setScreenDiagonal(diagonal);
    setResolution(resolution);
    setHasSmartTV(smartFlag == 1);
    setRoom(r);
}

string HomeTelevision::getType() const {
    return "Домашній телевізор";
}

void HomeTelevision::display() const {
    cout << "Тип: " << getType()
         << ", діагональ: " << getScreenDiagonal() << "\""
         << ", роздільна здатність: " << getResolution()
         << ", Smart-TV: " << (getHasSmartTV() ? "так" : "ні")
         << ", кімната: " << room << "\n";
}
