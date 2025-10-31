#include "TimeException.h"

TimeException::TimeException()
    : std::runtime_error("sec id negative") {}