#pragma once
#include <iostream>
#include <string>
#include "ContactInfoError.h" 

class ContactInfo {
public:
    std::string email;
    std::string phoneNumber;
    ContactInfo(std::string email, std::string phoneNumber);
    bool isValid();
};