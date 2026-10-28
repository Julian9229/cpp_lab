#ifndef TV_CATALOG_H
#define TV_CATALOG_H

#include "television.h"
#include <string>
#include <vector>

struct catalog_rec_t {
    std::string type;
    double screenDiagonal;
    std::string resolution;
    bool hasSmartTV;
    std::string extra;
};

class TelevisionCatalog {
private:
    std::vector<catalog_rec_t> records;

public:
    TelevisionCatalog();
    ~TelevisionCatalog();

    void add(const Television& tv, const std::string& extra = "");
    void clear();
    int size() const;
    void displayAll() const;
    double totalDiagonal() const;

    catalog_rec_t& operator[](int index);
    const catalog_rec_t& operator[](int index) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
