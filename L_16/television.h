#ifndef TELEVISION_H
#define TELEVISION_H

#include <cstddef>
#include <iostream>

class Television {
private:
    double screenDiagonal;
    char* resolution;
    bool hasSmartTV;
    int* inputs;
    std::size_t inputCount;

    void allocate(double diagonal, bool smart, const char* res, std::size_t inputs);
    void freeResources();

public:
    Television(double diagonal, bool smart, const char* resolution, std::size_t inputCount = 3);
    ~Television();

    Television(const Television& other);
    Television& operator=(const Television& other);

    Television(Television&& other) noexcept;
    Television& operator=(Television&& other) noexcept;

    static Television inputFromKeyboard();

    double getScreenDiagonal() const;
    bool getHasSmartTV() const;
    const char* getResolution() const;
    const int* getInputs() const;
    std::size_t getInputCount() const;

    void display() const;
};

#endif
