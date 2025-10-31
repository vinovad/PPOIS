#pragma once
#include <string>
#include <stdexcept>

class ContactInfoError : public std::runtime_error {
public:
    ContactInfoError(const std::string& error);
};