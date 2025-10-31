#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Passport {
private:
    std::string passportNumber;
    std::string nationality;
    Date* issueDate;
    Date* expiryDate;

public:
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string placeOfBirth;
    std::string gender;

    Passport(std::string number, std::string firstName, std::string lastName,
        std::string nationality, std::string dob, std::string pob, std::string gender);
    Passport(std::string number, std::string firstName, std::string lastName,
        std::string nationality, std::string dob, std::string pob,
        std::string gender, Date* issue, Date* expiry);
    bool isValid();
    bool isExpired();
    std::string getFullName();
    std::string getPassportNumber();
    std::string getNationality();
    void updateExpiryDate(Date* newExpiry);
};