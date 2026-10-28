#ifndef TELEVISION_H
#define TELEVISION_H

#include <array>
#include <string>

const int SIZE = 5;

struct television_s_t {
    double screenDiagonal;
    std::string resolution;
    bool hasSmartTV;
};

class TelevisionStore {
private:
    std::array<television_s_t, SIZE> televisions;
    int count;

public:
    TelevisionStore();
    ~TelevisionStore();

    void addTelevision(double diagonal, std::string resolution, bool smart);
    void inputTelevision();
    void setScreenDiagonal(int index, double diagonal);
    void setResolution(int index, std::string resolution);
    void setHasSmartTV(int index, bool smart);

    void displayAll() const;
    void displayBySmartTV(bool smart) const;
    void displayByMinDiagonal(double minDiagonal) const;
};

#endif
