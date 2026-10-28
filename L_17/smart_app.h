#ifndef SMART_APP_H
#define SMART_APP_H

#include <iostream>
#include <memory>
#include <string>

class MediaCenter;

class SmartApp {
public:
    std::string name;
    std::weak_ptr<MediaCenter> center;

    explicit SmartApp(const std::string& n);
    ~SmartApp();
};

#endif
