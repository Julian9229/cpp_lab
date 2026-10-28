#include "low_pass_filter.h"
#include <iostream>
#include <limits>

using namespace std;

LowPassFilter::LowPassFilter()
    : Filter(), cutoffFreq(1000.0), attenuation(40.0) {
    cout << "Конструктор LowPassFilter\n";
}

LowPassFilter::LowPassFilter(string model, int order, double price,
                             double cutoffFreq, double attenuation)
    : Filter(model, order, price), cutoffFreq(1000.0), attenuation(40.0) {
    setCutoffFreq(cutoffFreq);
    setAttenuation(attenuation);
    cout << "Конструктор LowPassFilter (з параметрами)\n";
}

LowPassFilter::~LowPassFilter() {
    cout << "Деструктор LowPassFilter\n";
}

void LowPassFilter::setCutoffFreq(double f) {
    if (f <= 0 || f > 100000) {
        cout << "Помилка: частота зрізу має бути від 0 (не включно) до 100000 Гц!\n";
        return;
    }
    cutoffFreq = f;
}

void LowPassFilter::setAttenuation(double a) {
    if (a < 1.0 || a > 120.0) {
        cout << "Помилка: загасання має бути від 1 до 120 дБ!\n";
        return;
    }
    attenuation = a;
}

void LowPassFilter::inputData() {
    string model;
    int order;
    double price;
    double cutoff;
    double atten;

    while (true) {
        cout << "Модель фільтра НЧ (можна кілька слів): ";
        getline(cin, model);
        if (!model.empty()) {
            break;
        }
        cout << "Помилка: модель не може бути порожньою!\n";
    }

    while (true) {
        cout << "Порядок (1..10): ";
        if (cin >> order && order >= 1 && order <= 10) {
            break;
        }
        cout << "Помилка: порядок фільтра має бути від 1 до 10!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Ціна (> 0): ";
        if (cin >> price && price > 0) {
            break;
        }
        cout << "Помилка: ціна має бути більшою за 0!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Частота зрізу (Гц, > 0 .. 100000): ";
        if (cin >> cutoff && cutoff > 0 && cutoff <= 100000) {
            break;
        }
        cout << "Помилка: частота зрізу має бути від 0 (не включно) до 100000 Гц!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Загасання (1..120 дБ): ";
        if (cin >> atten && atten >= 1.0 && atten <= 120.0) {
            break;
        }
        cout << "Помилка: загасання має бути від 1 до 120 дБ!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    setModel(model);
    setOrder(order);
    setPrice(price);
    setCutoffFreq(cutoff);
    setAttenuation(atten);
}

void LowPassFilter::display() const {
    cout << "Тип: " << getType()
         << ", модель: " << getModel()
         << ", порядок: " << getOrder()
         << ", ціна: " << getPrice() << " грн"
         << ", частота зрізу: " << cutoffFreq << " Гц"
         << ", загасання: " << attenuation << " дБ\n";
}

string LowPassFilter::getType() const {
    return "Фільтр нижніх частот";
}
