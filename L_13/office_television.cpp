#include "office_television.h"
#include "tv_exception.h"
#include <iostream>

using namespace std;

OfficeTelevision::OfficeTelevision()
    : Television(), floor(1) {}

OfficeTelevision::OfficeTelevision(double diagonal, const string& resolution, bool smart, int floor)
    : Television(diagonal, resolution, smart), floor(1) {
    setFloor(floor);
}

OfficeTelevision::~OfficeTelevision() {}

void OfficeTelevision::setFloor(int f) {
    if (f < 1 || f > 100) {
        throw ValidationException("поверх має бути від 1 до 100");
    }
    floor = f;
}

int OfficeTelevision::getFloor() const {
    return floor;
}

string OfficeTelevision::getType() const {
    return "Офісний телевізор";
}

void OfficeTelevision::display() const {
    cout << "Тип: " << getType()
         << ", діагональ: " << getScreenDiagonal() << "\""
         << ", роздільна здатність: " << getResolution()
         << ", Smart-TV: " << (getHasSmartTV() ? "так" : "ні")
         << ", поверх: " << floor << "\n";
}
