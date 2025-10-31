#include "Visa.h"

Visa::Visa(std::string number, std::string country, std::string type,
    int duration, bool multiEntry, std::string purpose, Passport* pass)
    : visaNumber(number), country(country), visaType(type),
    duration(duration), isMultipleEntry(multiEntry),
    purpose(purpose), passport(pass), issueDate(nullptr), expiryDate(nullptr) {
}

bool Visa::isValid() {
    if (visaNumber.empty() || country.empty()) {
        return false;
    }
    return true;
}

bool Visa::isExpired() {
    return expiryDate != nullptr;
}

std::string Visa::getVisaNumber() {
    return visaNumber;
}

std::string Visa::getVisaType() {
    return visaType;
}

int Visa::getRemainingDays() {
    return duration;
}

void Visa::extendVisa(int additionalDays) {
    duration += additionalDays;
}

bool Visa::requiresPassport() {
    return passport != nullptr;
}