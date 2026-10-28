#ifndef BAD_CYCLE_H
#define BAD_CYCLE_H

#include <iostream>
#include <memory>
#include <string>

class BadMediaCenter;

class BadSmartApp {
public:
    std::string name;
    std::shared_ptr<BadMediaCenter> center;

    explicit BadSmartApp(const std::string& n);
    ~BadSmartApp();
};

class BadMediaCenter {
public:
    std::string name;
    std::shared_ptr<BadSmartApp> app;

    explicit BadMediaCenter(const std::string& n);
    ~BadMediaCenter();
};

#endif
