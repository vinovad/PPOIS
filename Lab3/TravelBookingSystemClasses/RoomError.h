#pragma once
#include <string>
#include <stdexcept>

class RoomError : public std::runtime_error {
public:
    RoomError();
};