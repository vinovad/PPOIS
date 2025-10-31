#pragma once
#include <string>
#include <stdexcept>

class BookingApplication : public std::runtime_error {
public:
    BookingApplication();
};