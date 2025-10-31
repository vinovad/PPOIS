#pragma once
#include <string>
#include <stdexcept>

class TimeException : public std::runtime_error {
public:
    TimeException();
};