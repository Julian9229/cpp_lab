#include "television.h"
#include <limits>

using namespace std;

Television::Television()
    : screenDiagonal(32.0), resolution("1920x1080"), hasSmartTV(false) {}

Television::Television(double diagonal, const string& resolution, bool smart)
    : screenDiagonal(32.0), resolution("1920x1080"), hasSmartTV(false) {
    setScreenDiagonal(diagonal);
    setResolution(resolution);
    setHasSmartTV(smart);
}

Television::~Television() {}

void Television::setScreenDiagonal(double diagonal) {
    if (diagonal < 10.0 || diagonal > 120.0) {
        screenDiagonal = 32.0;
        return;
    }
    screenDiagonal = diagonal;
}

void Television::setResolution(const string& res) {
    if (res.empty()) {
        resolution = "1920x1080";
    } else {
        resolution = res;
    }
}

void Television::setHasSmartTV(bool smart) {
    hasSmartTV = smart;
}

void Television::inputData() {
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

double Television::getScreenDiagonal() const { return screenDiagonal; }
string Television::getResolution() const { return resolution; }
bool Television::getHasSmartTV() const { return hasSmartTV; }

void Television::display() const {
    cout << "діагональ: " << screenDiagonal << "\""
         << ", роздільна здатність: " << resolution
         << ", Smart-TV: " << (hasSmartTV ? "так" : "ні");
}

bool Television::equals(const Television& other) const {
    return screenDiagonal == other.screenDiagonal
        && resolution == other.resolution
        && hasSmartTV == other.hasSmartTV;
}

ostream& operator<<(ostream& out, const Television& tv) {
    out << "діагональ: " << tv.screenDiagonal << "\""
        << ", роздільна здатність: " << tv.resolution
        << ", Smart-TV: " << (tv.hasSmartTV ? "так" : "ні");
    return out;
}
