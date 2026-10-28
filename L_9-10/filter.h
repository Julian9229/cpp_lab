#ifndef FILTER_H
#define FILTER_H

#include <string>

struct filter_s_t {
    std::string model;
    int order;
    double price;
};

class Filter {
private:
    filter_s_t data;

public:
    Filter();
    Filter(std::string model, int order, double price);
    virtual ~Filter();

    void setModel(std::string model);
    void setOrder(int order);
    void setPrice(double price);

    std::string getModel() const;
    int getOrder() const;
    double getPrice() const;

    virtual void display() const;
    virtual std::string getType() const;
};

#endif
