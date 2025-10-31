#include "CarAgent.h"

CarAgent::CarAgent(std::string name, std::string email, std::string phone) :
    ContactInfo(email, phone), name(name) {
}

std::string CarAgent::getContactDetails() {
    return name + " - " + email + " - " + phoneNumber;
}

int CarAgent::getExperienceYears() {
    return 5;
}