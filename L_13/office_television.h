#ifndef OFFICE_TELEVISION_H
#define OFFICE_TELEVISION_H

#include "television.h"

class OfficeTelevision : public Television {
private:
    int floor;

public:
    OfficeTelevision();
    OfficeTelevision(double diagonal, const std::string& resolution, bool smart, int floor);
    ~OfficeTelevision();

    void setFloor(int floor);
    int getFloor() const;

    virtual std::string getType() const;
    virtual void display() const;
};

#endif
