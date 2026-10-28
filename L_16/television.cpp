#include "television.h"
#include <cstring>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void Television::allocate(double diagonal, bool smart, const char* res, size_t inputs) {
    if (diagonal < 10.0 || diagonal > 120.0) {
        diagonal = 32.0;
    }
    if (inputs < 1) {
        inputs = 1;
    }
    if (res == nullptr || res[0] == '\0') {
        res = "1920x1080";
    }

    screenDiagonal = diagonal;
    hasSmartTV = smart;
    inputCount = inputs;

    this->inputs = new int[inputCount];
    for (size_t i = 0; i < inputCount; ++i) {
        this->inputs[i] = static_cast<int>(i + 1);
    }

    size_t len = strlen(res);
    resolution = new char[len + 1];
    strcpy(resolution, res);
}

void Television::freeResources() {
    delete[] inputs;
    delete[] resolution;
    inputs = nullptr;
    resolution = nullptr;
    inputCount = 0;
    screenDiagonal = 0.0;
    hasSmartTV = false;
}

Television::Television(double diagonal, bool smart, const char* res, size_t inputCount)
    : screenDiagonal(0.0), resolution(nullptr), hasSmartTV(false),
      inputs(nullptr), inputCount(0) {
    allocate(diagonal, smart, res, inputCount);
    cout << "[Constructor] Ресурс виділено, діагональ: " << screenDiagonal
         << "\", адреса inputs: " << inputs
         << ", адреса resolution: " << static_cast<void*>(resolution) << "\n";
}

Television::~Television() {
    if (inputs != nullptr || resolution != nullptr) {
        cout << "[Destructor] Звільнення ресурсу, адреса inputs: " << inputs << "\n";
    } else {
        cout << "[Destructor] Об'єкт порожній, видаляти нічого\n";
    }
    freeResources();
}

Television::Television(const Television& other)
    : screenDiagonal(0.0), resolution(nullptr), hasSmartTV(false),
      inputs(nullptr), inputCount(0) {
    allocate(other.screenDiagonal, other.hasSmartTV, other.resolution, other.inputCount);
    for (size_t i = 0; i < inputCount; ++i) {
        inputs[i] = other.inputs[i];
    }
    cout << "[Copy Constructor] Глибоке копіювання, адреса inputs: " << inputs << "\n";
}

Television& Television::operator=(const Television& other) {
    if (this != &other) {
        freeResources();
        allocate(other.screenDiagonal, other.hasSmartTV, other.resolution, other.inputCount);
        for (size_t i = 0; i < inputCount; ++i) {
            inputs[i] = other.inputs[i];
        }
    }
    cout << "[Copy Assignment] Копіююче присвоювання\n";
    return *this;
}

Television::Television(Television&& other) noexcept
    : screenDiagonal(other.screenDiagonal),
      resolution(other.resolution),
      hasSmartTV(other.hasSmartTV),
      inputs(other.inputs),
      inputCount(other.inputCount) {
    other.screenDiagonal = 0.0;
    other.resolution = nullptr;
    other.hasSmartTV = false;
    other.inputs = nullptr;
    other.inputCount = 0;
    cout << "[Move Constructor] Ресурс передано, адреса inputs: " << inputs << "\n";
}

Television& Television::operator=(Television&& other) noexcept {
    if (this != &other) {
        freeResources();
        screenDiagonal = other.screenDiagonal;
        resolution = other.resolution;
        hasSmartTV = other.hasSmartTV;
        inputs = other.inputs;
        inputCount = other.inputCount;
        other.screenDiagonal = 0.0;
        other.resolution = nullptr;
        other.hasSmartTV = false;
        other.inputs = nullptr;
        other.inputCount = 0;
    }
    cout << "[Move Assignment] Присвоювання переміщенням\n";
    return *this;
}

Television Television::inputFromKeyboard() {
    double diagonal;
    int smartFlag;
    size_t inputs;
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

    while (true) {
        cout << "Кількість входів HDMI (>= 1): ";
        if (cin >> inputs && inputs >= 1) {
            break;
        }
        cout << "Помилка: кількість входів має бути >= 1!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        cout << "Роздільна здатність (наприклад 3840x2160): ";
        getline(cin, res);
        if (!res.empty()) {
            break;
        }
        cout << "Помилка: роздільна здатність не може бути порожньою!\n";
    }

    return Television(diagonal, smartFlag == 1, res.c_str(), inputs);
}

double Television::getScreenDiagonal() const { return screenDiagonal; }
bool Television::getHasSmartTV() const { return hasSmartTV; }
const char* Television::getResolution() const { return resolution; }
const int* Television::getInputs() const { return inputs; }
size_t Television::getInputCount() const { return inputCount; }

void Television::display() const {
    cout << "діагональ: " << screenDiagonal << "\""
         << ", роздільна здатність: " << (resolution ? resolution : "(порожньо)")
         << ", Smart-TV: " << (hasSmartTV ? "так" : "ні")
         << ", входів: " << inputCount
         << ", inputs@: " << inputs << "\n";
}
