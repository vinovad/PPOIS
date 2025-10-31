#include "AuthExceptions.h"

AuthException::AuthException(std::string error) :error(error) {}

std::string AuthException::getError() {
    return error;
}