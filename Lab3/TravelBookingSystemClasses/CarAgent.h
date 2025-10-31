#pragma once
#include <string>
#include "ContactInfo.h"

class CarAgent : public ContactInfo {
public:
    std::string name;
    CarAgent(std::string name, std::string email, std::string phone);
    std::string getContactDetails();  
    int getExperienceYears();
};