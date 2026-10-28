#include "filter_friend.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

FilterFriend::FilterFriend() {
    cout << "Конструктор FilterFriend\n";
}

FilterFriend::~FilterFriend() {
    items.clear();
    cout << "Деструктор FilterFriend\n";
}

void FilterFriend::inputLowPass(LowPassFilter& lp, string model, int order,
                                double price, double cutoffFreq, double attenuation) {
    lp.setModel(model);
    lp.setOrder(order);
    lp.setPrice(price);
    lp.setCutoffFreq(cutoffFreq);
    lp.setAttenuation(attenuation);
}

void FilterFriend::inputBandPass(BandPassFilter& bp, string model, int order,
                                 double price, double lowFreq, double highFreq) {
    bp.setModel(model);
    bp.setOrder(order);
    bp.setPrice(price);
    if (lowFreq <= 0 || lowFreq > 100000 || highFreq <= 0 || highFreq > 100000
        || lowFreq >= highFreq) {
        cout << "Помилка: нижня частота має бути меншою за верхню "
             << "(обидві в діапазоні > 0 .. 100000 Гц)!\n";
        return;
    }
    bp.lowFreq = lowFreq;
    bp.highFreq = highFreq;
}

void FilterFriend::inputLowPassFromKeyboard(LowPassFilter& lp) {
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

    inputLowPass(lp, model, order, price, cutoff, atten);
}

void FilterFriend::inputBandPassFromKeyboard(BandPassFilter& bp) {
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

    inputBandPass(bp, model, order, price, low, high);
}

void FilterFriend::printBase(Filter& filter) const {
    cout << "Тип: " << filter.getType()
         << ", модель: " << filter.data.model
         << ", порядок: " << filter.data.order
         << ", ціна: " << filter.data.price << " грн\n";
}

void FilterFriend::printLowPass(LowPassFilter& lp) const {
    cout << "Тип: " << lp.getType()
         << ", модель: " << lp.data.model
         << ", порядок: " << lp.data.order
         << ", ціна: " << lp.data.price << " грн"
         << ", частота зрізу: " << lp.cutoffFreq << " Гц"
         << ", загасання: " << lp.attenuation << " дБ\n";
}

void FilterFriend::printBandPass(BandPassFilter& bp) const {
    cout << "Тип: " << bp.getType()
         << ", модель: " << bp.data.model
         << ", порядок: " << bp.data.order
         << ", ціна: " << bp.data.price << " грн"
         << ", смуга: " << bp.lowFreq << ".." << bp.highFreq << " Гц\n";
}

void FilterFriend::addToCatalog(LowPassFilter& lp) {
    catalog_item_t item;
    item.type = lp.getType();
    item.model = lp.data.model;
    item.order = lp.data.order;
    item.price = lp.data.price;
    item.extra = "зріз=" + to_string(lp.cutoffFreq) + " Гц, загасання="
               + to_string(lp.attenuation) + " дБ";
    items.push_back(item);
}

void FilterFriend::addToCatalog(BandPassFilter& bp) {
    catalog_item_t item;
    item.type = bp.getType();
    item.model = bp.data.model;
    item.order = bp.data.order;
    item.price = bp.data.price;
    item.extra = "смуга=" + to_string(bp.lowFreq) + ".."
               + to_string(bp.highFreq) + " Гц";
    items.push_back(item);
}

void FilterFriend::displayCatalog() const {
    if (items.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        cout << "[" << i << "] тип: " << items[i].type
             << ", модель: " << items[i].model
             << ", порядок: " << items[i].order
             << ", ціна: " << items[i].price << " грн"
             << ", " << items[i].extra << "\n";
    }
}

double FilterFriend::totalPrice() const {
    double sum = 0;
    for (size_t i = 0; i < items.size(); i++) {
        sum += items[i].price;
    }
    return sum;
}

int FilterFriend::count() const {
    return (int)items.size();
}

double FilterFriend::maxPrice() const {
    if (items.empty()) {
        return 0;
    }
    double maxVal = items[0].price;
    for (size_t i = 1; i < items.size(); i++) {
        if (items[i].price > maxVal) {
            maxVal = items[i].price;
        }
    }
    return maxVal;
}
