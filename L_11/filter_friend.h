#ifndef FILTER_FRIEND_H
#define FILTER_FRIEND_H

#include "low_pass_filter.h"
#include "band_pass_filter.h"
#include <string>
#include <vector>

struct catalog_item_t {
    std::string type;
    std::string model;
    int order;
    double price;
    std::string extra;
};

class FilterFriend {
private:
    std::vector<catalog_item_t> items;

public:
    FilterFriend();
    ~FilterFriend();

    void inputLowPass(LowPassFilter& lp, std::string model, int order,
                      double price, double cutoffFreq, double attenuation);
    void inputBandPass(BandPassFilter& bp, std::string model, int order,
                       double price, double lowFreq, double highFreq);

    void inputLowPassFromKeyboard(LowPassFilter& lp);
    void inputBandPassFromKeyboard(BandPassFilter& bp);

    void printLowPass(LowPassFilter& lp) const;
    void printBandPass(BandPassFilter& bp) const;
    void printBase(Filter& filter) const;

    void addToCatalog(LowPassFilter& lp);
    void addToCatalog(BandPassFilter& bp);

    void displayCatalog() const;
    double totalPrice() const;
    int count() const;
    double maxPrice() const;
};

#endif
