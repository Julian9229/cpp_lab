#include <iostream>
#include "low_pass_filter.h"
#include "band_pass_filter.h"
#include "filter_catalog.h"

using namespace std;

void showByRef(Filter& filter) {
    cout << "Через посилання на базовий клас: ";
    filter.display();
}

int main() {
    cout << "=== Лаб. №9-10, варіант 13: Фільтр -> НЧ, смуговий ===\n\n";

    cout << "1. Створення об'єктів:\n";
    LowPassFilter lp1("Butterworth LPF", 2, 1500, 1000.0, 40.0);
    LowPassFilter lp2("Chebyshev LPF", 4, 2800, 500.0, 60.0);
    BandPassFilter bp1("Telephone BPF", 2, 1200, 300.0, 3400.0);
    BandPassFilter bp2("Audio BPF", 3, 3500, 20.0, 20000.0);

    cout << "\n1a. Введення одного об'єкта з клавіатури (LowPassFilter::inputData):\n";
    LowPassFilter lpKeyboard;
    lpKeyboard.inputData();
    cout << "Введено: ";
    lpKeyboard.display();

    cout << "\n2. Віртуальний виклик через посилання:\n";
    showByRef(lp1);
    showByRef(bp1);

    cout << "\n3. Каталог (vector вказівників, поліморфізм):\n";
    FilterCatalog catalog;
    catalog.add(&lp1);
    catalog.add(&lp2);
    catalog.add(&bp1);
    catalog.add(&bp2);
    catalog.add(&lpKeyboard);

    cout << "Вхідні дані / усі фільтри:\n";
    catalog.displayAll();

    cout << "\n4. Зміна полів і валідація:\n";
    lp1.setOrder(3);
    lp1.setAttenuation(200);
    bp1.setHighFreq(100);
    bp1.setLowFreq(400);
    catalog.displayAll();

    cout << "\n5. Результат обчислення:\n";
    cout << "Кількість фільтрів: " << catalog.count() << endl;
    cout << "Загальна вартість: " << catalog.totalPrice() << " грн\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
