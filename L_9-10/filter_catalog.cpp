#include "filter_catalog.h"
#include <iostream>

using namespace std;

FilterCatalog::FilterCatalog() {
    cout << "Конструктор FilterCatalog\n";
}

FilterCatalog::~FilterCatalog() {
    filters.clear();
    cout << "Деструктор FilterCatalog\n";
}

void FilterCatalog::add(Filter* filter) {
    if (filter == nullptr) {
        cout << "Помилка: порожній вказівник!\n";
        return;
    }
    filters.push_back(filter);
}

void FilterCatalog::displayAll() const {
    if (filters.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < filters.size(); i++) {
        cout << "[" << i << "] ";
        filters[i]->display();
    }
}

double FilterCatalog::totalPrice() const {
    double sum = 0;
    for (size_t i = 0; i < filters.size(); i++) {
        sum += filters[i]->getPrice();
    }
    return sum;
}

int FilterCatalog::count() const {
    return (int)filters.size();
}
