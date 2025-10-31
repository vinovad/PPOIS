#pragma once
#include <string>
#include <stdexcept>

class BookingExceprion: public std::runtime_error {
public:
    BookingExceprion();
};