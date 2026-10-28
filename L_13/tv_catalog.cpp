#include "tv_catalog.h"
#include "tv_exception.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

TelevisionCatalog::TelevisionCatalog() {
    cout << "Конструктор TelevisionCatalog\n";
}

TelevisionCatalog::~TelevisionCatalog() {
    cout << "Деструктор TelevisionCatalog\n";
}

void TelevisionCatalog::add(const Television& tv, const string& extra) {
    catalog_rec_t rec;
    rec.type = tv.getType();
    rec.screenDiagonal = tv.getScreenDiagonal();
    rec.resolution = tv.getResolution();
    rec.hasSmartTV = tv.getHasSmartTV();
    rec.extra = extra;
    records.push_back(rec);
}

void TelevisionCatalog::clear() {
    records.clear();
}

int TelevisionCatalog::size() const {
    return (int)records.size();
}

void TelevisionCatalog::displayAll() const {
    if (records.empty()) {
        cout << "Каталог порожній.\n";
        return;
    }
    for (size_t i = 0; i < records.size(); i++) {
        cout << "[" << i << "] тип: " << records[i].type
             << ", діагональ: " << records[i].screenDiagonal << "\""
             << ", роздільна здатність: " << records[i].resolution
             << ", Smart-TV: " << (records[i].hasSmartTV ? "так" : "ні");
        if (!records[i].extra.empty()) {
            cout << ", " << records[i].extra;
        }
        cout << "\n";
    }
}

double TelevisionCatalog::totalDiagonal() const {
    double sum = 0;
    for (size_t i = 0; i < records.size(); i++) {
        sum += records[i].screenDiagonal;
    }
    return sum;
}

catalog_rec_t& TelevisionCatalog::operator[](int index) {
    if (index < 0 || index >= (int)records.size()) {
        throw ValidationException("некоректний індекс каталогу");
    }
    return records[index];
}

const catalog_rec_t& TelevisionCatalog::operator[](int index) const {
    if (index < 0 || index >= (int)records.size()) {
        throw ValidationException("некоректний індекс каталогу");
    }
    return records[index];
}

void TelevisionCatalog::saveToFile(const string& filename) const {
    fstream file(filename, ios::out | ios::trunc);
    if (!file) {
        throw FileException("не вдалося відкрити файл для запису: " + filename);
    }

    for (size_t i = 0; i < records.size(); i++) {
        file << records[i].type << ';'
             << records[i].screenDiagonal << ';'
             << records[i].resolution << ';'
             << (records[i].hasSmartTV ? 1 : 0) << ';'
             << records[i].extra << '\n';
    }

    file.close();
}

void TelevisionCatalog::loadFromFile(const string& filename) {
    fstream file(filename, ios::in);
    if (!file) {
        throw FileException("не вдалося відкрити файл для читання: " + filename);
    }

    records.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        catalog_rec_t rec;
        stringstream ss(line);
        string diagonalStr, smartStr;

        if (!getline(ss, rec.type, ';') ||
            !getline(ss, diagonalStr, ';') ||
            !getline(ss, rec.resolution, ';') ||
            !getline(ss, smartStr, ';')) {
            file.close();
            throw FileException("пошкоджений формат рядка у файлі");
        }
        getline(ss, rec.extra);

        try {
            rec.screenDiagonal = stod(diagonalStr);
            rec.hasSmartTV = (stoi(smartStr) != 0);
        } catch (...) {
            file.close();
            throw FileException("помилка розбору числових полів у файлі");
        }

        if (rec.screenDiagonal < 10.0 || rec.screenDiagonal > 120.0) {
            file.close();
            throw ValidationException("у файлі некоректна діагональ екрану");
        }
        if (rec.resolution.empty()) {
            file.close();
            throw ValidationException("у файлі порожня роздільна здатність");
        }

        records.push_back(rec);
    }

    file.close();
}
