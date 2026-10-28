#ifndef BAND_PASS_FILTER_H
#define BAND_PASS_FILTER_H

#include "filter.h"

class FilterFriend;

class BandPassFilter : public Filter {
private:
    double lowFreq;
    double highFreq;

    friend class FilterFriend;

public:
    BandPassFilter();
    BandPassFilter(std::string model, int order, double price,
                   double lowFreq, double highFreq);
    ~BandPassFilter();

    void setLowFreq(double lowFreq);
    void setHighFreq(double highFreq);

    virtual std::string getType() const;
};

#endif
