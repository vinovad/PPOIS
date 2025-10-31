#include "RoomException.h"

RoomException::RoomException()
    : std::runtime_error("this unit doesn't have the coordinatess") {}