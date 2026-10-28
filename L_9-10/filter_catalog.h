#ifndef FILTER_CATALOG_H
#define FILTER_CATALOG_H

#include "filter.h"
#include <vector>

class FilterCatalog {
private:
    std::vector<Filter*> filters;

public:
    FilterCatalog();
    ~FilterCatalog();

    void add(Filter* filter);
    void displayAll() const;
    double totalPrice() const;
    int count() const;
};

#endif
