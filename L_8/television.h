#ifndef TELEVISION_H
#define TELEVISION_H

#include <string>
#include <vector>

struct television_s_t {
    double screenDiagonal;
    std::string resolution;
    bool hasSmartTV;
};

class TelevisionStore {
private:
    std::vector<television_s_t> televisions;

public:
    TelevisionStore();
    ~TelevisionStore();

    void addTelevision(double diagonal, std::string resolution, bool smart);
    void inputTelevision();
    void insertTelevision(int index, double diagonal, std::string resolution, bool smart);
    void removeTelevision(int index);
    void swapTelevisions(int i, int j);
    void clearAll();

    void setScreenDiagonal(int index, double diagonal);
    void setResolution(int index, std::string resolution);
    void setHasSmartTV(int index, bool smart);

    void displayAll() const;
    void displayBySmartTV(bool smart) const;
};

#endif
