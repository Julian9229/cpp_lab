#include "filter.h"
#include <iostream>

using namespace std;

Filter::Filter() {
    data.model = "unknown";
    data.order = 1;
    data.price = 1.0;
    cout << "Конструктор Filter\n";
}

Filter::Filter(string model, int order, double price) {
    data.model = "unknown";
    data.order = 1;
    data.price = 1.0;
    setModel(model);
    setOrder(order);
    setPrice(price);
    cout << "Конструктор Filter (з параметрами)\n";
}

Filter::~Filter() {
    cout << "Деструктор Filter (" << data.model << ")\n";
}

void Filter::setModel(string model) {
    if (model.empty()) {
        cout << "Помилка: модель не може бути порожньою!\n";
        return;
    }
    data.model = model;
}

void Filter::setOrder(int order) {
    if (order < 1 || order > 10) {
        cout << "Помилка: порядок фільтра має бути від 1 до 10!\n";
        return;
    }
    data.order = order;
}

void Filter::setPrice(double price) {
    if (price <= 0) {
        cout << "Помилка: ціна має бути більшою за 0!\n";
        return;
    }
    data.price = price;
}

string Filter::getModel() const { return data.model; }
int Filter::getOrder() const { return data.order; }
double Filter::getPrice() const { return data.price; }

string Filter::getType() const {
    return "Фільтр";
}
