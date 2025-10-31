#include "Passport.h"

Passport::Passport(std::string number, std::string firstName, std::string lastName,
    std::string nationality, std::string dob, std::string pob, std::string gender)
    : passportNumber(number), firstName(firstName), lastName(lastName),
    nationality(nationality), dateOfBirth(dob), placeOfBirth(pob),
    gender(gender), issueDate(nullptr), expiryDate(nullptr) {
}

Passport::Passport(std::string number, std::string firstName, std::string lastName,
    std::string nationality, std::string dob, std::string pob,
    std::string gender, Date* issue, Date* expiry)
    : passportNumber(number), firstName(firstName), lastName(lastName),
    nationality(nationality), dateOfBirth(dob), placeOfBirth(pob),
    gender(gender), issueDate(issue), expiryDate(expiry) {
}

bool Passport::isValid() {
    if (passportNumber.empty() || firstName.empty() || lastName.empty()) {
        return false;
    }
    return true;
}

bool Passport::isExpired() {
    return expiryDate != nullptr;
}

std::string Passport::getFullName() {
    return firstName + " " + lastName;
}

std::string Passport::getPassportNumber() {
    return passportNumber;
}

std::string Passport::getNationality() {
    return nationality;
}

void Passport::updateExpiryDate(Date* newExpiry) {
    expiryDate = newExpiry;
}