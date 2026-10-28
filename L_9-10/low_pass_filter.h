#ifndef LOW_PASS_FILTER_H
#define LOW_PASS_FILTER_H

#include "filter.h"
#include <string>

class LowPassFilter : public Filter {
private:
    double cutoffFreq;
    double attenuation;

public:
    LowPassFilter();
    LowPassFilter(std::string model, int order, double price,
                  double cutoffFreq, double attenuation);
    ~LowPassFilter();

    void setCutoffFreq(double cutoffFreq);
    void setAttenuation(double attenuation);

    void inputData();

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
