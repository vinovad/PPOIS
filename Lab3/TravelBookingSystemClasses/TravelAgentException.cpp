#include "TravelAgentException.h"

TravelAgentException::TravelAgentException()
    : std::runtime_error("booking is already closed") {}