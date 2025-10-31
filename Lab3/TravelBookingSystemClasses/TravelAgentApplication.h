#pragma once
#include <string>
#include <stdexcept>

class TravelAgentApplication : public std::runtime_error {
public:
    TravelAgentApplication();
};