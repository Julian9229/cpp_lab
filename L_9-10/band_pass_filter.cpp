#include "band_pass_filter.h"
#include <iostream>
#include <limits>

using namespace std;

BandPassFilter::BandPassFilter()
    : Filter(), lowFreq(300.0), highFreq(3400.0) {
    cout << "Конструктор BandPassFilter\n";
}

BandPassFilter::BandPassFilter(string model, int order, double price,
                               double lowFreq, double highFreq)
    : Filter(model, order, price), lowFreq(1.0), highFreq(100000.0) {
    setLowFreq(lowFreq);
    setHighFreq(highFreq);
    cout << "Конструктор BandPassFilter (з параметрами)\n";
}

BandPassFilter::~BandPassFilter() {
    cout << "Деструктор BandPassFilter\n";
}

void BandPassFilter::setLowFreq(double f) {
    if (f <= 0 || f > 100000) {
        cout << "Помилка: нижня частота має бути від 0 (не включно) до 100000 Гц!\n";
        return;
    }
    if (f >= highFreq) {
        cout << "Помилка: нижня частота має бути меншою за верхню!\n";
        return;
    }
    lowFreq = f;
}

void BandPassFilter::setHighFreq(double f) {
    if (f <= 0 || f > 100000) {
        cout << "Помилка: верхня частота має бути від 0 (не включно) до 100000 Гц!\n";
        return;
    }
    if (f <= lowFreq) {
        cout << "Помилка: верхня частота має бути більшою за нижню!\n";
        return;
    }
    highFreq = f;
}

void BandPassFilter::inputData() {
    string model;
    int order;
    double price;
    double low;
    double high;

    while (true) {
        cout << "Модель смугового фільтра (можна кілька слів): ";
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
        cout << "Нижня частота (Гц, > 0 .. 100000): ";
        if (cin >> low && low > 0 && low <= 100000) {
            break;
        }
        cout << "Помилка: нижня частота має бути від 0 (не включно) до 100000 Гц!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Верхня частота (Гц, > нижньої .. 100000): ";
        if (cin >> high && high > low && high <= 100000) {
            break;
        }
        cout << "Помилка: верхня частота має бути більшою за нижню і до 100000 Гц!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    setModel(model);
    setOrder(order);
    setPrice(price);
    // set high first to a safe default so setLowFreq can succeed, then both
    highFreq = 100000.0;
    setLowFreq(low);
    setHighFreq(high);
}

void BandPassFilter::display() const {
    cout << "Тип: " << getType()
         << ", модель: " << getModel()
         << ", порядок: " << getOrder()
         << ", ціна: " << getPrice() << " грн"
         << ", смуга: " << lowFreq << ".." << highFreq << " Гц\n";
}

string BandPassFilter::getType() const {
    return "Смуговий фільтр";
}
