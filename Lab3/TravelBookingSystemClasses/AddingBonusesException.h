#pragma once
#include <string>
#include <stdexcept>

class AddingBonusesException : public std::runtime_error {
public:
    AddingBonusesException(const std::string& message);
};