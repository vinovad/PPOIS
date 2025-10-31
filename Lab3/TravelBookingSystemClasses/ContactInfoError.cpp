#include "ContactInfoError.h"

ContactInfoError::ContactInfoError(const std::string& error)
    : std::runtime_error(error) {}