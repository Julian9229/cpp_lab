#ifndef MEDIA_CENTER_H
#define MEDIA_CENTER_H

#include <iostream>
#include <memory>
#include <string>

class SmartApp;

class MediaCenter {
public:
    std::string name;
    std::shared_ptr<SmartApp> app;

    explicit MediaCenter(const std::string& n);
    ~MediaCenter();
};

#endif
