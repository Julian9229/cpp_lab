#include "band_pass_filter.h"
#include <iostream>

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

string BandPassFilter::getType() const {
    return "Смуговий фільтр";
}
