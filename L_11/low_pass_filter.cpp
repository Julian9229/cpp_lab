#include "low_pass_filter.h"
#include <iostream>

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

string LowPassFilter::getType() const {
    return "Фільтр нижніх частот";
}
