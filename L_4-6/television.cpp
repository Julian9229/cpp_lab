#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Television {
private:
    double screenDiagonal;
    string resolution;
    bool hasSmartTV;

public:
    Television() {
        screenDiagonal = 32.0;
        resolution = "1920x1080";
        hasSmartTV = false;
        cout << "Викликано конструктор за замовчуванням\n";
    }

    Television(double diagonal, string res, bool smart) {
        screenDiagonal = diagonal;
        resolution = res;
        hasSmartTV = smart;
        cout << "Викликано конструктор з параметрами\n";
    }

    ~Television() {
        cout << "Викликано деструктор\n";
    }

    void setScreenDiagonal(double diagonal) {
        if (diagonal < 10.0 || diagonal > 120.0) {
            cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
            return;
        }
        screenDiagonal = diagonal;
    }

    void setResolution(string res) {
        if (res.empty()) {
            cout << "Помилка: роздільна здатність не може бути порожньою!\n";
            return;
        }
        resolution = res;
    }

    void setHasSmartTV(bool smart) {
        hasSmartTV = smart;
    }

    void setScreenDiagonalByRef(double& diagonal) {
        if (diagonal < 10.0 || diagonal > 120.0) {
            cout << "Помилка: діагональ екрану має бути від 10 до 120 дюймів!\n";
            return;
        }
        screenDiagonal = diagonal;
    }

    void inputData() {
        double diagonal;
        int smartFlag;
        string res;

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
            getline(cin, res);
            if (!res.empty()) {
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

        setScreenDiagonal(diagonal);
        setResolution(res);
        setHasSmartTV(smartFlag == 1);
    }

    void displayInfo() {
        cout << "Діагональ екрану: " << screenDiagonal << "\"" << endl;
        cout << "Роздільна здатність: " << resolution << endl;
        cout << "Smart-TV: " << (hasSmartTV ? "так" : "ні") << endl;
    }
};

void changeDiagonal(Television& tv, double newDiagonal) {
    cout << "Зміна через посилання на об'єкт...\n";
    tv.setScreenDiagonal(newDiagonal);
}

int main() {
    cout << "=== Лаб. №4-6, варіант 13: Телевізор ===\n\n";

    cout << "1. Об'єкт livingRoomTV (за замовчуванням):\n";
    Television livingRoomTV;
    livingRoomTV.displayInfo();
    cout << endl;

    cout << "2. Об'єкт bedroomTV (з параметрами):\n";
    Television bedroomTV(55.0, "3840x2160", true);
    bedroomTV.displayInfo();
    cout << endl;

    cout << "3. Зміна livingRoomTV методами:\n";
    livingRoomTV.setScreenDiagonal(43.0);
    livingRoomTV.setResolution("2560x1440");
    livingRoomTV.setHasSmartTV(true);
    livingRoomTV.displayInfo();
    cout << endl;

    cout << "4. Зміна за посиланням:\n";
    double d = 50.0;
    livingRoomTV.setScreenDiagonalByRef(d);
    livingRoomTV.displayInfo();
    cout << endl;

    cout << "5. Зміна bedroomTV через функцію з посиланням:\n";
    changeDiagonal(bedroomTV, 65.0);
    bedroomTV.displayInfo();
    cout << endl;

    cout << "6. Спроба задати некоректні значення:\n";
    livingRoomTV.setScreenDiagonal(5.0);
    livingRoomTV.setResolution("");
    livingRoomTV.displayInfo();
    cout << endl;

    cout << "7. Введення даних для kitchenTV з клавіатури (метод inputData):\n";
    Television kitchenTV;
    kitchenTV.inputData();
    cout << "Результат:\n";
    kitchenTV.displayInfo();

    return 0;
}
