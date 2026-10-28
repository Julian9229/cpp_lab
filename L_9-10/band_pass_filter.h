#ifndef BAND_PASS_FILTER_H
#define BAND_PASS_FILTER_H

#include "filter.h"

class BandPassFilter : public Filter {
private:
    double lowFreq;
    double highFreq;

public:
    BandPassFilter();
    BandPassFilter(std::string model, int order, double price,
                   double lowFreq, double highFreq);
    ~BandPassFilter();

    void setLowFreq(double lowFreq);
    void setHighFreq(double highFreq);

    void inputData();

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
