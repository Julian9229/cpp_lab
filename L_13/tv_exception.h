#ifndef TV_EXCEPTION_H
#define TV_EXCEPTION_H

#include <string>

class TelevisionException {
private:
    std::string message;

public:
    TelevisionException(const std::string& msg);
    virtual ~TelevisionException();
    virtual const char* what() const;
};

class ValidationException : public TelevisionException {
public:
    ValidationException(const std::string& msg);
};

class FileException : public TelevisionException {
public:
    FileException(const std::string& msg);
};

#endif
