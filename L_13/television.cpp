#include "television.h"
#include "tv_exception.h"

using namespace std;

Television::Television() {
    data.screenDiagonal = 32.0;
    data.resolution = "1920x1080";
    data.hasSmartTV = false;
}

Television::Television(double diagonal, const string& resolution, bool smart) {
    data.screenDiagonal = 32.0;
    data.resolution = "1920x1080";
    data.hasSmartTV = false;
    setScreenDiagonal(diagonal);
    setResolution(resolution);
    setHasSmartTV(smart);
}

Television::~Television() {}

void Television::setScreenDiagonal(double diagonal) {
    if (diagonal < 10.0 || diagonal > 120.0) {
        throw ValidationException("діагональ екрану має бути від 10 до 120 дюймів");
    }
    data.screenDiagonal = diagonal;
}

void Television::setResolution(const string& resolution) {
    if (resolution.empty()) {
        throw ValidationException("роздільна здатність не може бути порожньою");
    }
    data.resolution = resolution;
}

void Television::setHasSmartTV(bool smart) {
    data.hasSmartTV = smart;
}

double Television::getScreenDiagonal() const { return data.screenDiagonal; }
string Television::getResolution() const { return data.resolution; }
bool Television::getHasSmartTV() const { return data.hasSmartTV; }

string Television::getType() const {
    return "Телевізор";
}

void Television::display() const {
    cout << "Тип: " << getType()
         << ", діагональ: " << data.screenDiagonal << "\""
         << ", роздільна здатність: " << data.resolution
         << ", Smart-TV: " << (data.hasSmartTV ? "так" : "ні") << "\n";
}

bool operator==(const Television& a, const Television& b) {
    return a.data.screenDiagonal == b.data.screenDiagonal
        && a.data.resolution == b.data.resolution
        && a.data.hasSmartTV == b.data.hasSmartTV;
}

bool operator<(const Television& a, const Television& b) {
    return a.data.screenDiagonal < b.data.screenDiagonal;
}

Television operator+(const Television& a, const Television& b) {
    double diagonal = (a.data.screenDiagonal > b.data.screenDiagonal)
                          ? a.data.screenDiagonal
                          : b.data.screenDiagonal;
    bool smart = a.data.hasSmartTV || b.data.hasSmartTV;
    string resolution = a.data.resolution + " / " + b.data.resolution;
    return Television(diagonal, resolution, smart);
}

ostream& operator<<(ostream& out, const Television& tv) {
    out << tv.getType()
        << " | діагональ: " << tv.data.screenDiagonal << "\""
        << " | роздільна здатність: " << tv.data.resolution
        << " | Smart-TV: " << (tv.data.hasSmartTV ? "так" : "ні");
    return out;
}
