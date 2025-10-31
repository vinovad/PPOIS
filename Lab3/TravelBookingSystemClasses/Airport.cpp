#include "Airport.h"

Airport::Airport(std::string code, std::string name, std::string city,
    std::string country, int terminals, bool international)
    : airportCode(code), name(name), city(city), country(country),
    numberOfTerminals(terminals), isInternational(international),
    numberOfRunways(1), latitude(0.0), longitude(0.0), location(nullptr) {
}

std::string Airport::getAirportCode() {
    return airportCode;
}

void Airport::addAirline(std::string airline) {
    airlines.push_back(airline);
}

void Airport::removeAirline(std::string airline) {
    for (auto it = airlines.begin(); it != airlines.end(); ++it) {
        if (*it == airline) {
            airlines.erase(it);
            break;
        }
    }
}

int Airport::getAirlineCount() {
    return airlines.size();
}

bool Airport::hasInternationalFlights() {
    return isInternational;
}

void Airport::setCoordinates(double lat, double lon) {
    latitude = lat;
    longitude = lon;
}

std::string Airport::getFullName() {
    return name + " (" + airportCode + ")";
}

void Airport::upgradeTerminals(int count) {
    numberOfTerminals += count;
}