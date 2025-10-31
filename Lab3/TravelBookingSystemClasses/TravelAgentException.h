#pragma once
#include <string>
#include <stdexcept>

class TravelAgentException : public std::runtime_error {
public:
    TravelAgentException();
};