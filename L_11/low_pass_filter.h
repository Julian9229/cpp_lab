#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include "filter.h"
#include <string>

class FilterFriend;

class LowPassFilter : public Filter {
private:
    double cutoffFreq;
    double attenuation;

    friend class FilterFriend;

public:
    LowPassFilter();
    LowPassFilter(std::string model, int order, double price,
                  double cutoffFreq, double attenuation);
    ~LowPassFilter();

    void setCutoffFreq(double cutoffFreq);
    void setAttenuation(double attenuation);

    virtual std::string getType() const;
};

#endif
