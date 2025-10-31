#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Passport.h"

class Visa {
private:
    std::string visaNumber;
    std::string visaType;
    Date* issueDate;
    Date* expiryDate;

public:
    std::string country;
    int duration;
    bool isMultipleEntry;
    std::string purpose;
    Passport* passport;

    Visa(std::string number, std::string country, std::string type,
        int duration, bool multiEntry, std::string purpose, Passport* pass);
    bool isValid();
    bool isExpired();
    std::string getVisaNumber();
    std::string getVisaType();
    int getRemainingDays();
    void extendVisa(int additionalDays);
    bool requiresPassport();
};