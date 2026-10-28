#include "tv_exception.h"

TelevisionException::TelevisionException(const std::string& msg) : message(msg) {}

TelevisionException::~TelevisionException() {}

const char* TelevisionException::what() const {
    return message.c_str();
}

ValidationException::ValidationException(const std::string& msg)
    : TelevisionException(msg) {}

FileException::FileException(const std::string& msg)
    : TelevisionException(msg) {}
