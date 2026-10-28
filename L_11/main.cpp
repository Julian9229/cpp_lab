#include <iostream>
#include "low_pass_filter.h"
#include "band_pass_filter.h"
#include "filter_friend.h"

using namespace std;

int main() {
    cout << "=== Лаб. №11, варіант 13: Дружні класи (Фільтр) ===\n\n";

    FilterFriend helper;

    cout << "1. Створення об'єктів:\n";
    LowPassFilter lp1;
    LowPassFilter lp2;
    BandPassFilter bp1;
    BandPassFilter bp2;

    cout << "\n2. Введення даних через дружній клас:\n";
    helper.inputLowPass(lp1, "Butterworth LPF", 2, 1500, 1000.0, 40.0);
    helper.inputLowPass(lp2, "Chebyshev LPF", 4, 2800, 500.0, 60.0);
    helper.inputBandPass(bp1, "Telephone BPF", 2, 1200, 300.0, 3400.0);
    helper.inputBandPass(bp2, "Audio BPF", 3, 3500, 20.0, 20000.0);

    cout << "\n2a. Введення одного об'єкта з клавіатури:\n";
    LowPassFilter lpKeyboard;
    helper.inputLowPassFromKeyboard(lpKeyboard);
    helper.printLowPass(lpKeyboard);

    cout << "\n3. Вивід через дружній клас (доступ до private):\n";
    helper.printLowPass(lp1);
    helper.printLowPass(lp2);
    helper.printBandPass(bp1);
    helper.printBandPass(bp2);

    cout << "\n4. Вивід базової частини через friend:\n";
    helper.printBase(lp1);
    helper.printBase(bp1);

    cout << "\n5. Каталог (vector структур catalog_item_t):\n";
    helper.addToCatalog(lp1);
    helper.addToCatalog(lp2);
    helper.addToCatalog(bp1);
    helper.addToCatalog(bp2);
    helper.displayCatalog();

    cout << "\n6. Валідація некоректних даних:\n";
    helper.inputLowPass(lp1, "Butterworth LPF", 2, 1500, 1000.0, 200.0);
    helper.inputBandPass(bp1, "Telephone BPF", 2, 1200, 300.0, 100.0);
    cout << "Після спроби некоректної зміни:\n";
    helper.printLowPass(lp1);
    helper.printBandPass(bp1);

    cout << "\n7. Результат обчислення:\n";
    cout << "Кількість записів у каталозі: " << helper.count() << endl;
    cout << "Загальна вартість: " << helper.totalPrice() << " грн\n";
    cout << "Максимальна ціна: " << helper.maxPrice() << " грн\n";

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
