#include "AddingBonusesException.h"

AddingBonusesException::AddingBonusesException(const std::string& message)
    : std::runtime_error(message) {}