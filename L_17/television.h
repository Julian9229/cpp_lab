#ifndef TELEVISION_H
#define TELEVISION_H

#include <iostream>
#include <string>

class Television {
private:
    double screenDiagonal;
    std::string resolution;
    bool hasSmartTV;

public:
    Television();
    Television(double diagonal, const std::string& resolution, bool smart);
    ~Television();

    void setScreenDiagonal(double diagonal);
    void setResolution(const std::string& resolution);
    void setHasSmartTV(bool smart);

    void inputData();

    double getScreenDiagonal() const;
    std::string getResolution() const;
    bool getHasSmartTV() const;

    void display() const;
};

#endif
