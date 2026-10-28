#ifndef TELEVISION_H
#define TELEVISION_H

#include <iostream>
#include <string>

struct television_s_t {
    double screenDiagonal;
    std::string resolution;
    bool hasSmartTV;
};

class Television {
private:
    television_s_t data;

public:
    Television();
    Television(double diagonal, const std::string& resolution, bool smart);
    virtual ~Television();

    void setScreenDiagonal(double diagonal);
    void setResolution(const std::string& resolution);
    void setHasSmartTV(bool smart);

    double getScreenDiagonal() const;
    std::string getResolution() const;
    bool getHasSmartTV() const;

    virtual std::string getType() const;
    virtual void display() const;

    friend bool operator==(const Television& a, const Television& b);
    friend bool operator<(const Television& a, const Television& b);
    // об'єднання: більша діагональ, Smart = OR, роздільна здатність через " / "
    friend Television operator+(const Television& a, const Television& b);
    friend std::ostream& operator<<(std::ostream& out, const Television& tv);
};

#endif
