#include "Station.h"

Station::Station(std::string code, std::string name, std::string city,
    std::string type, int platforms)
    : stationCode(code), name(name), city(city), stationType(type),
    numberOfPlatforms(platforms), hasParking(false),
    hasWaitingRoom(true), latitude(0.0), longitude(0.0), location(nullptr) {
}

std::string Station::getStationCode() {
    return stationCode;
}

void Station::addFacility(std::string facility) {
    facilities.push_back(facility);
}

void Station::removeFacility(std::string facility) {
    for (auto it = facilities.begin(); it != facilities.end(); ++it) {
        if (*it == facility) {
            facilities.erase(it);
            break;
        }
    }
}

int Station::getFacilityCount() {
    return facilities.size();
}

bool Station::isParkingAvailable() {
    return hasParking;
}

void Station::enableParking() {
    hasParking = true;
}

void Station::setCoordinates(double lat, double lon) {
    latitude = lat;
    longitude = lon;
}

std::string Station::getStationType() {
    return stationType;
}