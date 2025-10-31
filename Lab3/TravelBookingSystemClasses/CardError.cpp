#include "CardError.h"

CardError::CardError(const std::string& error)
    : std::runtime_error(error) {}