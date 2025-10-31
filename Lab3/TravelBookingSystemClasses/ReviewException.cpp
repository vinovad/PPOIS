#include "ReviewException.h"

ReviewException::ReviewException()
    : std::runtime_error("Comment is empty") {}