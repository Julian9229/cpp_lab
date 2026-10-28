#ifndef HOME_TELEVISION_H
#define HOME_TELEVISION_H

#include "television.h"
#include <string>

class HomeTelevision : public Television {
private:
    std::string room;

public:
    HomeTelevision();
    HomeTelevision(double diagonal, const std::string& resolution, bool smart,
                   const std::string& room);
    ~HomeTelevision();

    void setRoom(const std::string& room);
    std::string getRoom() const;

    void inputData();

    virtual std::string getType() const;
    virtual void display() const;
};

#endif
