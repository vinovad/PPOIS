#pragma once
#include <iostream>
#include <string> 

class AuthException {
    std::string error;
public:
    AuthException(std::string error);
    std::string getError();
};