#include <iostream>
#include <string>
#include "television.h"
#include "max_utils.h"
#include "repository.h"
#include "pair_box.h"

using namespace std;

int main() {
    cout << "=== Лаб. №18, варіант 13: Шаблони (Телевізор) ===\n\n";

    cout << "1. Шаблон функції max_value:\n";
    cout << "  max int: " << max_value(10, 25) << "\n";
    cout << "  max double: " << max_value(3.14, 2.71) << "\n";
    cout << "  max string: "
         << max_value(string("3840x2160"), string("1920x1080")) << "\n";

    Television a(55.0, "3840x2160", true);
    Television b(65.0, "1920x1080", false);
    cout << "  max Television (за діагоналлю): "
         << max_value(a, b) << "\n";

    cout << "\n1a. Введення одного об'єкта з клавіатури (Television::inputData):\n";
    Television fromKeyboard;
    fromKeyboard.inputData();
    cout << "  введено: " << fromKeyboard << "\n";
    cout << "  max(a, fromKeyboard): " << max_value(a, fromKeyboard) << "\n";

    cout << "  max const char* (повна спеціалізація функції): "
         << max_value<const char*>("OLED", "LED") << "\n\n";

    cout << "2. Шаблон функції print_value + спеціалізація bool:\n";
    cout << "  int: ";
    print_value(42);
    cout << "  bool: ";
    print_value(true);
    cout << "\n";

    cout << "3. Шаблон класу Repository (загальний):\n";
    Repository<int> diagonalInches(55);
    Repository<double> level(43.5);
    Repository<Television> tv(Television(32.0, "2560x1440", true));
    diagonalInches.print();
    level.print();
    tv.print();
    cout << "\n";

    cout << "4. Часткова спеціалізація Repository<T*>:\n";
    int count = 65;
    Repository<int*> ptrRepo(&count);
    ptrRepo.print();
    cout << "\n";

    cout << "5. Повна спеціалізація Repository<bool>:\n";
    Repository<bool> smart(true);
    Repository<bool> noSmart(false);
    smart.print();
    noSmart.print();
    cout << "\n";

    cout << "6. Шаблон класу PairBox (загальний):\n";
    PairBox<int, double> p1(55, 3.14);
    p1.print_pair();
    PairBox<string, bool> p2("C++ templates", true);
    p2.print_pair();
    PairBox<int, Television> p3(55, Television(55.0, "3840x2160", true));
    p3.print_pair();
    cout << "\n";

    cout << "7. Часткова спеціалізація PairBox<T, T>:\n";
    PairBox<int, int> sameInts(43, 65);
    sameInts.print_pair();
    PairBox<Television, Television> sameTvs(
        Television(32.0, "1920x1080", false),
        Television(55.0, "3840x2160", true));
    sameTvs.print_pair();
    cout << "\n";

    cout << "8. Повна спеціалізація PairBox<bool, string>:\n";
    PairBox<bool, string> fields(true, "3840x2160");
    fields.print_pair();

    cout << "\n=== Кінець програми ===\n";
    return 0;
}
