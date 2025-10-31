#pragma once
#include <string>
#include <stdexcept>

class CardError : public std::runtime_error {
public:
    CardError(const std::string& error);
};