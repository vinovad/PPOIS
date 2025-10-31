#pragma once
#include <string>
#include <stdexcept>

class DataException : public std::runtime_error {
public:
    DataException();
};