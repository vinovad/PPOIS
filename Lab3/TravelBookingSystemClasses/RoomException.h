#pragma once
#include <string>
#include <stdexcept>

class RoomException : public std::runtime_error {
public:
    RoomException();
};